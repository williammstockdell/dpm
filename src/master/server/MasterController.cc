/* begin_generated_IBM_copyright_prolog                             */
/*                                                                  */
/* This is an automatically generated copyright prolog.             */
/* After initializing,  DO NOT MODIFY OR MOVE                       */
/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of IBM                             */
/*                                                                  */
/* Blue Gene/Q                                                      */
/*                                                                  */
/* (C) Copyright IBM Corp.  2010, 2011                              */
/*                                                                  */
/* US Government Users Restricted Rights -                          */
/* Use, duplication or disclosure restricted                        */
/* by GSA ADP Schedule Contract with IBM Corp.                      */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL).                                    */
/*                                                                  */
/* ================================================================ */
/*                                                                  */
/* end_generated_IBM_copyright_prolog                               */

/* ================================================================ */
/*                                                                  */
/* Modifications Copyright (C) Will Stockdell 2026                  */
/*                                                                  */
/* Modifications to this file are made available under the          */
/* Eclipse Public License (EPL) version 1.0.                        */
/*                                                                  */
/* ================================================================ */

#include <poll.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <utility/include/TimeStuff.h>
#include <utility/include/version.h>
#include <errno.h>
#include <log4cxx/helpers/messagebuffer.h>
#include <log4cxx/logger.h>
#include <string.h>
#include <sys/types.h>
#include <utility/include/Log.h>
#include <utility/include/cxxsockets/Host.h>
#include <utility/include/cxxsockets/exception.h>
#include <barrier>
#include <ranges>
#include <algorithm>
#include <exception>
#include <iterator>
#include <limits>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "AgentManager.h"
#include "AgentRep.h"
#include "Alias.h"
#include "AliasList.h"
#include "ClientManager.h"
#include "LockFile.h"
#include "MasterController.h"
#include "Registrar.h"
#include "../lib/exceptions.h"
#include "common/ClientProtocol.h"
#include "common/Ids.h"
#include "protocol/BGMasterAgentProtocolSpec.h"
#include "protocol/BGMasterClientProtocolSpec.h"
#include "server/Behavior.h"
#include "server/LockingRingBuffer.h"
#include "server/Policy.h"
#include "server/types.h"

LOG_DECLARE_FILE("master");

const int CIRC_BUFFER_SIZE = 50;

extern LockFile* lock_file;

//! \brief static member instantiations
std::mutex MasterController::_policy_build_mutex;
bgq::utility::Properties::Ptr MasterController::_props;
bool MasterController::_master_terminating = false;
bool MasterController::_end_requested = false;
bool MasterController::_start_servers = false;
AliasList MasterController::_aliases;

std::barrier<> MasterController::_start_barrier(3);
std::string MasterController::_master_logdir;
bool MasterController::_master_db;
bool MasterController::_stop_once = false;
bool MasterController::_start_once = true;
std::chrono::system_clock::time_point MasterController::_start_time;
std::string MasterController::_version_string;
LockingStringRingBuffer MasterController::_err_buff(CIRC_BUFFER_SIZE);
LockingStringRingBuffer MasterController::_history_buff(CIRC_BUFFER_SIZE);
std::vector<ClientProtocolPtr> MasterController::_monitor_prots;
std::mutex MasterController::_monitor_prots_mutex;

AgentManager MasterController::_agent_manager;
ClientManager MasterController::_client_manager;

Registrar MasterController::_agent_registrar;
Registrar MasterController::_client_registrar;

MasterController::MasterController(const bgq::utility::Properties::Ptr& properties) { _props = properties; }

void MasterController::stopThreads(const bool end_binaries, const int signal) {
    LOG_TRACE_MSG(__FUNCTION__);
    if (_stop_once) {
        return;
    } else {
        _stop_once = true;
    }

    LOG_INFO_MSG("Stopping all threads.");

    // Stop the agent registrar.
    _agent_registrar.cancel();

    // Stop agent threads.
    _agent_manager.cancel(end_binaries, signal);

    // Stop client threads.
    _client_manager.cancel();

    // Stop the client registrar.
    _client_registrar.cancel();
}

void MasterController::handleErrorMessage(const std::string& msg) {

    LOG_ERROR_MSG(__FUNCTION__ << ": " << msg);

    std::ostringstream errmsg;
    std::vector<ClientProtocolPtr> deadClients;

    const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    errmsg << time_to_string(now) << ": " << msg;
    _err_buff.push_back(errmsg.str());

    // Send it to all of the monitors.
    BGMasterClientProtocolSpec::ErrorMessage error(errmsg.str());
    sendClientMessage(error, error.getClassName(), deadClients);

    // Loop through the deadClients and remove them from _monitor_prots container.
    for (unsigned i = 0; i < deadClients.size(); ++i) {
        LOG_WARN_MSG("Removing master_monitor client instance after socket error ...");
        MasterController::get_monitor_prots().erase(std::remove(MasterController::get_monitor_prots().begin(), MasterController::get_monitor_prots().end(), deadClients[i]),
                                                    MasterController::get_monitor_prots().end());
    }

    return;
}

void MasterController::getErrorMessages(std::vector<std::string>& messages) {
    LOG_TRACE_MSG(__FUNCTION__);

    // Going to pop items out of the circular buffer.
    _err_buff.getContents(messages);
}

void MasterController::sendClientMessage(const XML::Serializable& message, const std::string& classname, std::vector<ClientProtocolPtr>& deadClients) {
    LOG_TRACE_MSG(__FUNCTION__);

    std::scoped_lock scoped_lock(_monitor_prots_mutex);

    for (const ClientProtocolPtr& prot : _monitor_prots) {

        try {
            prot->sendOnly(classname, message);
        } catch (const CxxSockets::Error& e) {

            // If we get an error we assume that the client has been killed and should be removed
            // otherwise we have a potential memory leak.
            LOG_WARN_MSG(e.what());
            deadClients.push_back(prot);
        }
    }
}

void MasterController::addHistoryMessage(const std::string& message) {
    LOG_TRACE_MSG(__FUNCTION__);
    std::ostringstream msg;
    std::vector<ClientProtocolPtr> deadClients;

    const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    msg << time_to_string(now) << ": " << message;

    _history_buff.push_back(msg.str());

    // Send it to all of the monitors.
    BGMasterClientProtocolSpec::EventMessage event(msg.str());
    sendClientMessage(event, event.getClassName(), deadClients);

    // Loop through the deadClients and remove them from _monitor_prots container.
    for (unsigned i = 0; i < deadClients.size(); ++i) {
        LOG_WARN_MSG("Removing master_monitor client instance after socket error ...");
        MasterController::get_monitor_prots().erase(std::remove(MasterController::get_monitor_prots().begin(), MasterController::get_monitor_prots().end(), deadClients[i]),
                                                    MasterController::get_monitor_prots().end());
    }

    return;
}

void MasterController::getHistoryMessages(std::vector<std::string>& messages) {
    LOG_TRACE_MSG(__FUNCTION__);
    _history_buff.getContents(messages);
}

void MasterController::buildHostList(const bgq::utility::Properties::Section& hosts, const std::vector<std::string>& exclude_list, std::ostringstream& failmsg) {
    LOG_TRACE_MSG(__FUNCTION__);

    bool firstdup = true;

    for (const bgq::utility::Properties::Pair& keyval : hosts) {
        bool found = false;

        for (const AliasPtr& al : _aliases) {
            const std::string& all_hosts(keyval.second);
            if (keyval.first == al->get_name()) {
                std::vector<std::string>::const_iterator it = std::find(exclude_list.begin(), exclude_list.end(), al->get_name());
                if (it != exclude_list.end()) {

                    // This was defined previously.  Refresh is additive.  We don't want to mess with this on a running system.
                    if (firstdup) {
                        firstdup = false;
                        failmsg << "Host list previously set for " << al->get_name();
                    } else {
                        failmsg << ", " << al->get_name();
                    }
                    std::ostringstream msg;
                    msg << "Host list previously set for " << al->get_name();
                    handleErrorMessage(msg.str());
                } else {

                    // Found an existing alias so parse out the hosts and update the alias
                    bool first = true;

                    for (auto&& part : all_hosts | std::views::split(',')) {
                        const std::string curr_host(part.begin(), part.end());

                        if (curr_host.empty()) {
                            continue;
                        }

                        try {
                            CxxSockets::Host h(curr_host);

                            if (first) {
                                LOG_DEBUG_MSG("Host " << h.uhn() << " is the preferred host.");
                                h.set_primary(true);
                            }

                            first = false;

                            LOG_DEBUG_MSG("Adding host " << h.uhn() << " to alias " << al->get_name());

                            al->add_host(h);

                        } catch (const CxxSockets::Error& e) {
                            throw exceptions::APIUserError(exceptions::INFO, e.what());
                        }
                    }
                }
                found = true;
                break;
            }
        }

        if (!found) {
            // Didn't find an alias.  Assume the [master.binmap] entry has been commented out.
            // Log a warning message in case something else is going on.
            LOG_WARN_MSG("Alias " << keyval.first << " was not defined. Skipping [master.policy.host_list] entry ...");
        }
    }
}

void MasterController::buildFailover(const bgq::utility::Properties::Section& failover, std::multimap<Policy::Trigger, Behavior>& behaviors) {
    LOG_TRACE_MSG(__FUNCTION__);

    // Finally, go through the failover list
    for (const bgq::utility::Properties::Pair& keyval : failover) {

        LOG_DEBUG_MSG("Building policy for " << keyval.first << "=" << keyval.second);

        std::string failover_policy = keyval.second;
        std::erase(failover_policy, ' ');

        std::vector<std::string> tokens;

        for (auto&& part : failover_policy | std::views::split(',')) {
            if (!part.empty()) {
                tokens.emplace_back(part.begin(), part.end());
            }
        }

        if (tokens.empty()) {
            std::ostringstream msg;
            msg << "Invalid failover policy configuration. No policy specified for " << keyval.first;
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        // Trigger is first
        const Policy::Trigger my_trigger = Policy::string_to_trigger(tokens[0]);

        if (my_trigger == Policy::INVALID_TRIGGER) {
            std::ostringstream msg;
            msg << "Invalid failover trigger " << tokens[0] << " specified.";
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        // Second is the action to take
        if (tokens.size() < 2) {
            std::ostringstream msg;
            msg << "Invalid failure configuration for " << keyval.first << ". No action specified.";
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        const Behavior::Action act = Behavior::string_to_action(tokens[1]);

        if (act == Behavior::INVALID_ACTION) {
            std::ostringstream msg;
            msg << "Invalid failure action '" << tokens[1] << "' specified.";
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        // Third is number of retries
        if (tokens.size() < 3) {
            std::ostringstream msg;
            msg << "Invalid failure configuration for " << keyval.first << ". No retries specified.";
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        unsigned short retries = 0;

        try {
            const unsigned long value = std::stoul(tokens[2]);

            if (value > std::numeric_limits<unsigned short>::max()) {
                throw std::out_of_range("retry count out of range");
            }

            retries = static_cast<unsigned short>(value);
        } catch (const std::exception& e) {
            std::ostringstream msg;
            msg << e.what();
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        if (retries == 0) {
            std::ostringstream msg;
            msg << "Invalid retry configuration for " << keyval.first << ". Number of retries, " << retries << ", must be greater than zero.";
            handleErrorMessage(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }

        std::map<CxxSockets::Host, CxxSockets::Host> failpairs;

        // Fourth is associated host pairs
        if (tokens.size() < 4) {
            if (act == Behavior::FAILOVER) {
                LOG_INFO_MSG("Failure configuration for " << keyval.first << " 'failover' action specified, but no failover pair specified.");
            }
        } else {
            if (act == Behavior::RESTART) {
                std::ostringstream msg;
                msg << "Bad policy configuration specified, cannot specify failover pairs"
                    << " for a \"restart\" policy.";
                handleErrorMessage(msg.str());
                throw exceptions::ConfigError(exceptions::WARN, msg.str());
            }

            const std::string& host_pairs = tokens[3];

            // host:host|host:host
            for (auto&& part : host_pairs | std::views::split('|')) {
                const std::string current(part.begin(), part.end());

                const auto first_colon = current.find(':');

                if (first_colon == std::string::npos) {
                    std::ostringstream msg;
                    msg << "Failover configuration syntax incorrect. Missing \":\"";
                    handleErrorMessage(msg.str());
                    throw exceptions::ConfigError(exceptions::WARN, msg.str());
                }

                if (first_colon != current.rfind(':')) {
                    std::ostringstream msg;
                    msg << "Failover configuration syntax incorrect. More than one ':' in the pair \"" << current << "\"";
                    handleErrorMessage(msg.str());
                    throw exceptions::ConfigError(exceptions::WARN, msg.str());
                }

                const std::string from = current.substr(0, first_colon);
                const std::string to = current.substr(first_colon + 1);

                if (to.empty()) {
                    std::ostringstream msg;
                    msg << "Failover pair for policy " << keyval.first << " missing a target.";
                    handleErrorMessage(msg.str());
                    throw exceptions::ConfigError(exceptions::WARN, msg.str());
                }

                try {
                    CxxSockets::Host from_host(from);
                    CxxSockets::Host to_host(to);

                    LOG_DEBUG_MSG("Created failover pair for " << from_host.uhn() << " to " << to_host.uhn() << " for alias " << keyval.first);

                    failpairs[from_host] = to_host;

                } catch (const CxxSockets::Error& e) {
                    throw exceptions::APIUserError(exceptions::INFO, e.what());
                }
            }
        }

        Behavior my_behavior(keyval.first, act, failpairs, retries);
        behaviors.emplace(my_trigger, my_behavior);
    }
}

void MasterController::buildInstances(const bgq::utility::Properties::Section& instances, const std::vector<std::string>& exclude_list, std::ostringstream& failmsg) {
    LOG_TRACE_MSG(__FUNCTION__);
    // Update the alias object for each instance found
    bool firstdup = true;
    for (const bgq::utility::Properties::Pair& keyval : instances) {
        bool found = false;

        for (const AliasPtr& al : _aliases) {
            const std::string& instance_policy(keyval.second);
            if (keyval.first == al->get_name()) {
                const std::vector<std::string>::const_iterator it = std::find(exclude_list.begin(), exclude_list.end(), al->get_name());
                if (it != exclude_list.end()) {
                    // This was defined previously. Refresh is additive. We don't want to mess with this on a running system.
                    std::ostringstream msg;
                    if (firstdup) {
                        msg << "Instances already defined for ";
                        firstdup = false;
                        msg << al->get_name();
                    } else
                        msg << ", " << al->get_name();
                    failmsg << msg.str();
                } else {
                    // Found an existing alias so update the policy
                    try {
                        const int ip = stoi(instance_policy);
                        al->policy().changeInstances(static_cast<unsigned short>(ip));
                        if (ip <= 0 || ip > std::numeric_limits<unsigned short>::max()) {
                            std::ostringstream msg;
                            msg << "Bad instance value " << instance_policy << " defined for " << al->get_name();
                            LOG_WARN_MSG(msg.str());
                            throw exceptions::ConfigError(exceptions::WARN, msg.str());
                        }
                    } catch (const std::invalid_argument& e) {
                        std::ostringstream msg;
                        msg << "Bad instance value " << instance_policy << " defined. " << e.what();
                        LOG_WARN_MSG(msg.str());
                        throw exceptions::ConfigError(exceptions::WARN, msg.str());
                    } catch (const std::out_of_range& e) {
                        std::ostringstream msg;
                        msg << "Out of range instance value " << instance_policy << " defined. " << e.what();
                        LOG_WARN_MSG(msg.str());
                        throw exceptions::ConfigError(exceptions::WARN, msg.str());
                    }

                    LOG_DEBUG_MSG("Found instance of " << instance_policy << " for alias " << al->get_name());
                }
                found = true;
                break;
            }
        }

        if (!found) {
            // Didn't find an alias, Assume the [master.binmap] entry has been commented out.
            // Log a warning message in case something else is going on.
            LOG_WARN_MSG("Alias " << keyval.first << " not defined.  Skipping [master.policy.instances] entry ... ");
        }
    }
    if (failmsg.str().length() != 0) {
        failmsg << ". ";
    }
}

void MasterController::buildArgs(const bgq::utility::Properties::Section& args) {
    LOG_TRACE_MSG(__FUNCTION__);

    // Args are optional. Don't complain if we find nothing.
    for (const bgq::utility::Properties::Pair& keyval : args) {
        bool found = false;

        for (const AliasPtr& al : _aliases) {

            if (keyval.first == al->get_name()) {
                found = true;
                LOG_DEBUG_MSG("Adding args " << keyval.second << " for " << keyval.first);
                al->set_args(keyval.second);
            }
        }

        if (!found) {
            // Didn't find an alias, Assume the [master.binmap] entry has been commented out.
            // Log a warning message in case something else is going on.
            LOG_WARN_MSG("Alias " << keyval.first << " not defined in [master.binmap] section. Skipping [master.binargs] entry ...");
        }
    }
}

void MasterController::addBehaviors(const bgq::utility::Properties::Section& failmap, std::multimap<Policy::Trigger, Behavior>& behaviors) {
    LOG_TRACE_MSG(__FUNCTION__);

    using Bevmap = std::multimap<Policy::Trigger, Behavior>;

    bool firstdup = true;

    for (const bgq::utility::Properties::Pair& keyval : failmap) {
        const std::string& current_alias = keyval.first;
        const std::string& policy_set = keyval.second;
        bool alias_found = false;

        LOG_TRACE_MSG("Checking for policies for alias " << current_alias << " against " << policy_set);

        for (auto&& part : policy_set | std::views::split(',')) {
            const std::string current_policy(part.begin(), part.end());

            if (current_policy.empty()) {
                continue;
            }

            LOG_TRACE_MSG("Evaluating policy " << current_policy << " against alias " << current_alias);

            bool policy_found = false;

            for (Bevmap::iterator it = behaviors.begin(); it != behaviors.end(); ++it) {

                if (current_policy == it->second.get_name()) {
                    // Got a match.  Now find the alias with the name that matches keyval.first and insert the behavior.
                    policy_found = true;
                    std::ostringstream logmsg;
                    for (const AliasPtr& al : _aliases) {

                        LOG_TRACE_MSG("Comparing alias " << al->get_name() << " to policy alias " << keyval.first);

                        if (keyval.first == al->get_name()) {
                            // Found an existing alias so update the policy
                            alias_found = true;
                            if (al->policy().addBehavior(it->first, it->second) == false) {
                                if (firstdup) {
                                    firstdup = false;
                                    logmsg << "Duplicate policy triggers defined: ";
                                }
                                logmsg << "Ignoring duplicate policy triggers ";
                                logmsg << current_policy << " ";
                            } else {

                                // Now check to make sure that if there are failover pairs,
                                // all hosts are in the alias' host list.
                                typedef std::pair<CxxSockets::Host, CxxSockets::Host> HostPair;
                                for (const HostPair pair : it->second.get_host_pairs()) {
                                    std::string failname = "";
                                    if (al->find_host(pair.first) == false) {
                                        failname = pair.first.fqhn();
                                    }
                                    if (al->find_host(pair.second) == false) {
                                        failname = pair.second.fqhn();
                                    }
                                    if (failname.length() > 0) {
                                        LOG_ERROR_MSG("Host " << failname << " not in host list for alias " << al->get_name());
                                    }
                                }
                                LOG_DEBUG_MSG("Added trigger " << it->first << " and behavior " << it->second.get_name() << " to " << al->get_name());
                            }
                            break;
                        }
                    }
                    if (logmsg.str().length() != 0) {
                        handleErrorMessage(logmsg.str());
                    }
                }
            }

            if (!policy_found) {
                // Didn't find a policy, Assume the [master.binmap] entry has been commented out.
                // Log warning message in case something else is going on.
                LOG_WARN_MSG("Policy " << current_policy << " found for undefined alias: " << keyval.first << " Skipping [master.policy.map] entry ...");
            }
        }
        if (!alias_found) {
            // Didn't find an alias.  Assume the [master.binmap] entry has been commented out.
            // Log a warning message in case something else is going on.
            LOG_WARN_MSG("Alias " << keyval.first << " not defined in section [master.binmap].  Skipping failover configuration for this alias ...");
        }
    }
}

void MasterController::buildStartList(const bgq::utility::Properties::Section& startlist) {
    LOG_TRACE_MSG(__FUNCTION__);
    for (const bgq::utility::Properties::Pair& keyval : startlist) {
        if (keyval.first == "start_servers") {
            if (keyval.second == "true") {
                _start_servers = true;
            } else {
                _start_servers = false;
            }
            LOG_DEBUG_MSG("Start servers is " << _start_servers);
        }
    }
}

void MasterController::buildUidList(const bgq::utility::Properties::Section& uidlist) {
    LOG_TRACE_MSG(__FUNCTION__);
    for (const bgq::utility::Properties::Pair& keyval : uidlist) {
        bool found = false;
        for (const AliasPtr& al : _aliases) {
            if (keyval.first == al->get_name()) {
                found = true;
                LOG_DEBUG_MSG("Adding user id " << keyval.second << " for " << keyval.first);
                al->set_user(keyval.second);
            }
        }
        if (!found) {
            // Didn't find an alias.  Assume that the [master.binmap] entry has been commented out.
            // Log a warning message in case something else is going on.
            LOG_WARN_MSG("Alias " << keyval.first << " not defined in section [master.binmap].  Skipping [master.user] entry ...");
        }
    }
}

void MasterController::buildLogDirs(const bgq::utility::Properties::Section& logdirs) {
    LOG_TRACE_MSG(__FUNCTION__);
    // For each alias/directory pair, find the alias.
    for (const bgq::utility::Properties::Pair& keyval : logdirs) {
        bool found = false;
        for (const AliasPtr& al : _aliases) {
            if (keyval.first == al->get_name()) {
                found = true;
                LOG_DEBUG_MSG("Adding log directory " << keyval.second << " for " << keyval.first);
                al->set_logdir(keyval.second);
            }
        }
        if (!found) {
            // Didn't find an alias.  Assume that the [master.binmap] entry has been commented out.
            // Log a warning message in case something else is going on.
            LOG_WARN_MSG("Alias " << keyval.first << " not defined in section [master.binmap]. Skipping [master.logdirs] entry ...");
        }
    }
}

void MasterController::buildPolicies(std::ostringstream& failmsg) {
    LOG_TRACE_MSG(__FUNCTION__);
    typedef bgq::utility::Properties::Section Sect;

    // Will contain the number of seconds to wait for an alias' preferred agent to check in.
    int preferredHostWait;

    // Protect the policy building process
    std::scoped_lock scoped_lock(_policy_build_mutex);

    Sect master, args, hosts, instances, failover, failmap, startlist, uidlist, logdirs;
    try {
        master = _props->getValues("master.binmap");
        args = _props->getValues("master.binargs");
        hosts = _props->getValues("master.policy.host_list");
        instances = _props->getValues("master.policy.instances");
        failover = _props->getValues("master.policy.failure");
        failmap = _props->getValues("master.policy.map");
        startlist = _props->getValues("master.startup");
        uidlist = _props->getValues("master.user");
        _start_once = false;
    } catch (const std::invalid_argument& e) {
        std::ostringstream msg;
        msg << "Properties file error. " << e.what();
        handleErrorMessage(msg.str());

        // Only exit if we are starting dpm_master_server , not on a refresh.
        if (_start_once) {
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        } else {
            return;
        }
    }

    bool dologdirs = false;
    try {
        logdirs = _props->getValues("master.logdirs");
        dologdirs = true;
    } catch (const std::invalid_argument& e) {
        std::ostringstream msg;
        msg << "Properties file error. " << e.what();
        handleErrorMessage(msg.str());
    }

    std::vector<std::string> exclude_list;

    // Get the $BG_DRIVER environment variable
    std::string driver = "";
    char* drv = getenv("DPM_DRV");
    if (drv != NULL)
        driver = drv;
    if (driver.length() == 0)
        driver = "/opt/"; // reasonable default
    LOG_DEBUG_MSG("DPM_DRV environment variable is " << driver);

    // Need to get preferred_host_wait time to send to the alias constructor.
    try {
        preferredHostWait = std::stoi(_props->getValue("master.server", "preferred_host_wait"));
        if (preferredHostWait <= 0) {
            std::ostringstream msg;
            msg << "Invalid preferred_host_wait setting in [master.server] section: Value must be an integer greater than 0.";
            LOG_ERROR_MSG(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        } else {
            std::ostringstream msg;
            msg << "Found user preferred_host_wait key with value: " << preferredHostWait << " in [master.server] section.";
            LOG_DEBUG_MSG(msg.str());
        }
    } catch (const std::invalid_argument& e) {
        // It is ok if it is not set.  We default it to 15 here.
        std::ostringstream msg;
        msg << "Did not find optional preferred_host_wait key in [master.server] section. Setting default of 15 seconds.";
        LOG_DEBUG_MSG(msg.str());
        preferredHostWait = 15;
    } catch (const std::out_of_range& e) {
        std::ostringstream msg;
        msg << "Out of range: Invalid preferred_host_wait setting in [master.server] section: " << e.what();
        LOG_ERROR_MSG(msg.str());
        throw exceptions::ConfigError(exceptions::WARN, msg.str());
    }

    // Create an alias object for every alias in the master map
    for (const bgq::utility::Properties::Pair& keyval : master) {
        AliasPtr alp;
        if (_aliases.find_alias(keyval.first, alp) == false) {
            // Alias doesn't yet exist, make it so.
            Policy pol; // Empty policy with default single instance
            std::string path = keyval.second;
            const AliasPtr al(new Alias(keyval.first, path, pol, "", _master_logdir, preferredHostWait));
            LOG_DEBUG_MSG("Adding alias " << keyval.first << " for " << path);
            _aliases.push_back(al);
            alp = al;
        } else {
            exclude_list.push_back(keyval.first); // Refreshing!
        }

        // The $DPM_DRIVER environment variable can be part of the path.
        // We need to replace what's in the property file with the env var.
        std::string path = keyval.second;
        const size_t path_loc = path.find("$DPM_DRIVER");
        if (path_loc != std::string::npos) {    // If $DPM_DRIVER is in the path...
            path.replace(path_loc, 10, driver); // ...replace it with the driver variable
        }
        LOG_DEBUG_MSG("Setting path to " << path);
        alp->set_path(path);
    }

    try {
        const std::string value(_props->getValue("master.server", "max_agents_per_host"));
        const int max_agents(std::stoi(value));
        if (max_agents <= 0) {
            std::ostringstream msg;
            msg << "Invalid max_agents_per_host setting in [master.server] section: value must be greater than zero";
            LOG_ERROR_MSG(msg.str());
            throw exceptions::ConfigError(exceptions::WARN, msg.str());
        }
        _agent_manager.setCount(static_cast<unsigned>(max_agents));
    } catch (const std::invalid_argument& e) {
        // this is OK, missing means default to 1
        LOG_DEBUG_MSG("missing max_agents_per_host setting in [master.server] section, using default value of 1");
    } catch (const std::out_of_range& e) {
        std::ostringstream msg;
        msg << "Out of range: Invalid max_agents_per_host setting in [master.server] section: " << e.what();
        LOG_ERROR_MSG(msg.str());
        throw exceptions::ConfigError(exceptions::WARN, msg.str());
    }

    buildArgs(args);

    buildHostList(hosts, exclude_list, failmsg);
    if (!failmsg.str().empty()) {
        failmsg << ". ";
    }

    buildInstances(instances, exclude_list, failmsg);
    std::multimap<Policy::Trigger, Behavior> behaviors;
    buildFailover(failover, behaviors);
    addBehaviors(failmap, behaviors);
    buildStartList(startlist);
    buildUidList(uidlist);
    if (dologdirs) {
        buildLogDirs(logdirs);
    }
}

void MasterController::startServers(std::map<std::string, std::string>& failed_aliases, AgentRepPtr agentrep) {
    LOG_TRACE_MSG(__FUNCTION__);

    LOG_INFO_MSG("Starting all listed binaries for agent " << (agentrep ? agentrep->get_agent_id().str() : "all agents") << ".");
    std::vector<AliasPtr> servers_to_start = _aliases.get_list_copy();

    while (!servers_to_start.empty() && !_master_terminating) {

        const AliasPtr al = servers_to_start.front();

        // Now take it out of the list, we'll put it in the back later if we can't start it.
        servers_to_start.erase(std::remove(servers_to_start.begin(), servers_to_start.end(), al), servers_to_start.end());

        if (al->get_name() == "dpm_master_server" || al->get_name() == "dpm_master") {
            continue; // Don't start ourselves
        }

        BinaryId id;
        if (al->running(id)) {
            continue; // Don't start one already running.
        }

        LOG_INFO_MSG("Attempting to start alias " << al->get_name() << ".");

        // Find an agent we can use. Supply an empty ID and let the alias pick one based on its policy.
        BGAgentId aid;
        AgentRepPtr agent;
        std::string failreason;

        try {
            agent = al->validateStartAgent(aid);
        } catch (const exceptions::InternalError& e) {
            LOG_ERROR_MSG("Unexpected error finding an agent: " << e.what());
            if (agentrep && !al->find_host(agentrep->get_host())) {
                // this agent was not configured to start this alias, keep going
                continue;
            } else {
                failreason = e.what();
                sleep(1);
            }
        } catch (...) {
            LOG_ERROR_MSG("Unexpected exception!");
            if (agentrep && !al->find_host(agentrep->get_host())) {
                // this agent was not configured to start this alias, keep going
                continue;
            } else {
                failreason = "Unexpected exception";
                sleep(1);
            }
        }

        if (agent) {
            // If we got here, we have an agent ready.
            const BGMasterAgentProtocolSpec::StartRequest agentreq(al->get_path(), al->get_args(), al->get_logdir(), al->get_name(), al->get_user());
            BGMasterAgentProtocolSpec::StartReply reply;
            reply._rc = exceptions::OK;

            const BinaryId bid = agent->startBin(agentreq, reply);

            if (bid.str() == "0") {
                std::ostringstream msg;
                msg << "Attempt to start binary for alias " << al->get_name() << " failed.";
                failed_aliases[al->get_name()] = msg.str();
                handleErrorMessage(msg.str());
            }
        } else {
            // Didn't start it, so put it back in the list.
            servers_to_start.push_back(al);
            LOG_DEBUG_MSG("No agent found running for alias " << al->get_name());
            failed_aliases[al->get_name()] = failreason;
        }
    }
}

void MasterController::startup(const int signal_fd) {
    LOG_TRACE_MSG(__FUNCTION__);
    std::ostringstream version;
    version << "DPM";
    version << " version: " << dpm::version::tag();
    version << " hash: " << dpm::version::hash();
    version << " " << __DATE__ << " " << __TIME__;
    _version_string = version.str();
    LOG_INFO_MSG("dpm_master_server [" << getpid() << "] " << _version_string << " starting...");

    LOG_INFO_MSG("Using " << _props->getFilename() << " for properties.");

    _master_db = false;
    _start_time = std::chrono::system_clock::now();

    try {
        _master_logdir = _props->getValue("master.server", "logdir");
        if (access(_master_logdir.c_str(), R_OK | W_OK) < 0) {
            std::ostringstream errmsg;
            errmsg << "Log directory " << _master_logdir << " is not accessible to dpm_master_server.";
            handleErrorMessage(errmsg.str());
            throw exceptions::ConfigError(exceptions::FATAL, errmsg.str());
        }
    } catch (const std::invalid_argument& e) {
        LOG_WARN_MSG("No log directory found. Will use default.");
    }

    // Read policy information from the config file
    std::ostringstream failmsg;
    buildPolicies(failmsg);
    LOG_INFO_MSG("Policies complete");
    if (!failmsg.str().empty()) {
        std::ostringstream msg;
        msg << "Invalid configuration: " << failmsg.str();
        handleErrorMessage(msg.str());
        throw exceptions::ConfigError(exceptions::FATAL, failmsg.str());
    }
    LOG_INFO_MSG("Config read");
    _agent_registrar.run(true);
    LOG_INFO_MSG("Agent Registrar run");
    _client_registrar.run(false);
    LOG_INFO_MSG("Client Registrar run");

    std::ostringstream startmsg;
    startmsg << "dpm_master_server startup completed";
    addHistoryMessage(startmsg.str());

    _start_barrier.arrive_and_wait();

    while (!_master_terminating) {

        struct pollfd pollfd;
        pollfd.fd = signal_fd;
        pollfd.events = POLLIN;
        pollfd.revents = 0;
        const int seconds = 5;
        const int rc = poll(&pollfd, 1, seconds);

        if (rc == -1) {
            if (errno != EINTR) {
                char errorText[256];
                LOG_ERROR_MSG("Could not poll: " << std::string(strerror_r(errno, errorText, 256)));
            }
        } else if (rc) {
            // Read siginfo from pipe
            siginfo_t siginfo;
            while (1) {
                const ssize_t lrc = read(signal_fd, &siginfo, sizeof(siginfo));
                if (lrc > 0) {
                    break;
                }
                if (lrc == -1 && errno == EINTR) {
                    continue;
                } else {
                    char errorText[256];
                    LOG_FATAL_MSG("Could not read from pipe: " << std::string(strerror_r(errno, errorText, 256)));
                    exit(1);
                }
            }
            if (siginfo.si_signo == SIGUSR1 || siginfo.si_signo == SIGPIPE || siginfo.si_signo == SIGHUP) {
                LOG_DEBUG_MSG("Received signal " << siginfo.si_signo << " from " << siginfo.si_pid);
            } else {
                LOG_FATAL_MSG("dpm_master_server ending due to signal " << siginfo.si_signo << " from " << siginfo.si_pid << ".");

                if (lock_file) {
                    delete lock_file;
                    lock_file = NULL;
                }

                // use _exit instead of exit since other threads are running and we don't want to
                // run global destructors
                _exit(128 + siginfo.si_signo);
            }
        } else {
            // Check if either registrar has failed. If so, restart it.
            bool reregister = false;
            if (_agent_registrar.get_failed()) {
                _client_registrar.cancel();
                _agent_registrar.run(true);
                _client_registrar.run(false);
                reregister = true;
            } else if (_client_registrar.get_failed()) {
                _agent_registrar.cancel();
                _client_registrar.run(false);
                _agent_registrar.run(true);
                reregister = true;
            }
            if (reregister) { // Only barrier wait if we restarted registrars
                _start_barrier.arrive_and_wait();
            }
        }
    }
}
