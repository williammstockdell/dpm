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

#include <pwd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <utility/include/Exec.h>
#include <utility/include/Log.h>
#include <utility/include/ScopeExit.h>
#include <utility/include/TimeStuff.h>
#include <cxxsockets/Host.h>
#include <errno.h>
#include <log4cxx/helpers/messagebuffer.h>
#include <log4cxx/logger.h>
#include <cstring>
#include <filesystem>
#include <compare>
#include <sstream>

#include "BinaryController.h"
#include "../lib/exceptions.h"
#include "types.h"
#include "common/Ids.h"

LOG_DECLARE_FILE("master");

void switchBackUID(uid_t my_euid, gid_t my_egid) {
    LOG_TRACE_MSG(__FUNCTION__);

    // Done. Go back to our user, but do it through root.
    int rc = seteuid(0); // Go back to root while we do this.

    if (rc != 0) {
        char errorText[256];
        LOG_ERROR_MSG("Cannot change uid back to 'root'. Current uid is " << geteuid() << ". " << std::string(strerror_r(errno, errorText, 256)));
    }

    rc = setegid(0);
    if (rc != 0) {
        char errorText[256];
        LOG_ERROR_MSG("Could not set effective gid back to 'root': " << std::string(strerror_r(errno, errorText, 256)));
    }

    rc = setegid(my_egid);
    if (rc != 0) {
        char errorText[256];
        LOG_ERROR_MSG("Could not set effective gid back to " << my_egid << ": " << std::string(strerror_r(errno, errorText, 256)));
    }

    rc = seteuid(my_euid);
    if (rc != 0) {
        char errorText[256];
        LOG_ERROR_MSG("Cannot reset effective uid to " << my_euid << ". Current euid is " << geteuid() << ".  " << std::string(strerror_r(errno, errorText, 256)));
    }
    LOG_DEBUG_MSG("Current uid: " << geteuid() << " Current gid: " << getegid());
}

BinaryController::BinaryController() : _status(UNINITIALIZED), _exit_status(0), _binary_bin_path(""), _alias_name(""), _stop_requested(false),
                                       _start_time(std::chrono::system_clock::now()), _user("")
{
}

BinaryController::BinaryController(const BinaryId& id, const std::string& bin_path, const std::string& alias, const std::string& user, int exit_status, Status stat, const std::string& start_time)
    : _status(stat), _exit_status(exit_status), _binary_bin_path(bin_path), _alias_name(alias), _host(), _binid(id), _user(user) {
    _stop_requested = false;
    if (start_time.length() == 0)
        _start_time = std::chrono::system_clock::now();
    else
        _start_time = time_from_string(start_time);
    _stop_requested = false;
}

BinaryController::BinaryController(const std::string& path, const std::string& arguments, const std::string& logfile, const std::string& alias, const CxxSockets::Host& host, const std::string& user) :
    _status(UNINITIALIZED),
    _exit_status(0),
    _binary_bin_path(path + (arguments.empty() ? "" : " " + arguments)),
    _alias_name(alias),
    _logfile(logfile),
    _host(host),
    _stop_requested(false),
    _start_time(std::chrono::system_clock::now()),
    _user(user)
{
}

BinaryController::BinaryController(const std::string& id, const std::string& bin_path, const std::string& alias, const std::string& user, int exit_status, int stat, const std::string& start_time)
    :  _status((Status)stat), _exit_status (exit_status), _binary_bin_path(bin_path), _alias_name(alias), _binid{id}, _stop_requested(false), _start_time(time_from_string(start_time)), _user(user) {}

BinaryId BinaryController::startBinary(const std::string& user_list, const std::string& properties) {
    LOG_TRACE_MSG(__FUNCTION__);

    // Pull out the full path and see if it exists
    const auto pos = _binary_bin_path.find(' ');
    const std::string path = _binary_bin_path.substr(0, pos);

    if (_user.length() == 0) {
        LOG_WARN_MSG("No user id defined for alias " << _alias_name << " running under default user.");
    } else {
        if (user_list.find(_user) == std::string::npos) {
            std::ostringstream err;
            err << "Invalid user id " << _user << " specified";
            LOG_ERROR_MSG(err.str() << ".");
            _exec_error = err.str();
            BinaryId badid(-1, "");
            return badid;
        }
    }

    if (!std::filesystem::exists(path)) {
        std::ostringstream msg;
        msg << "Command or path " << path << " does not exist.";
        LOG_ERROR_MSG(msg.str());
        _exec_error = msg.str();
        throw exceptions::FileError(exceptions::WARN, msg.str());
    }
    std::string error;
    int pipefd = 0;
    const pid_t pid = Exec::fexec(pipefd, _binary_bin_path, error, true, _logfile.c_str(), properties, _user);
    LOG_DEBUG_MSG("Returned from fexec for " << _alias_name << " pid=" << pid);
    if (pid < 0) {
        LOG_DEBUG_MSG("Error from exec: " << error);
        _exec_error = error;
        BinaryId badid(pid, "");
        return badid;
    }

    // If we get this far, we're successful.
    _binid = BinaryId(pid, _host.ip());
    if (_user.length() == 0) {
        LOG_INFO_MSG("Started binary id " << _binid.str() << " alias " << _alias_name);
    } else {
        LOG_INFO_MSG("Started binary id " << _binid.str() << " alias " << _alias_name << " under user " << _user);
    }
    return _binid;
}

bool isRunning(const pid_t pid) {
    LOG_TRACE_MSG(__FUNCTION__);
    bool retval = false;
    if (pid != 0) {
        const int rc = kill(pid, 0); // send a 0 signal just to test the pid
        if (rc == 0) {               // normal return implies process is running
            retval = true;
        } else {
            if (errno != ESRCH) { // ESRCH is normal for a terminated process
                char errorText[256];
                LOG_INFO_MSG("isRunning() failed, assuming process still running. " << std::string(strerror_r(errno, errorText, 256)));
                retval = true;
            }
        }
    }
    return retval;
}

int BinaryController::stop(int signal) {
    LOG_TRACE_MSG(__FUNCTION__);
    // This is how this works:
    // We use the signal passed to us as the initial signal... unless it is unspecified (zero).
    // In that case, we default to SIGTERM. After we try our initial signal, we wait a bit and start sending
    // SIGKILLs to REALLY kill it.
    LOGGING_DECLARE_ID_MDC(_binid.str());
    LOG_DEBUG_MSG("Stopping binary " << _binid.str());

    stopping(true);
    const int pid = _binid.get_pid();
    const uid_t my_euid = geteuid();
    const gid_t my_egid = getegid();

    if (pid != 0) {
        bool isroot = false;
        // Switch back to root so we can switch to assigned user.
        if (_user.length() != 0) {
            int rc = seteuid(0); // Go back to root while we do this.
            if (rc != 0) {
                char errorText[256];
                LOG_ERROR_MSG("Cannot change uid to root. Current uid is " << geteuid() << ". " << std::string(strerror_r(errno, errorText, 256)));
            } else {
                isroot = true;
                LOG_INFO_MSG("Changed effective uid to 'root'.");
            }
        }

        if (_user.length() != 0 && isroot) {
            const struct passwd* my_entry = getpwnam(_user.c_str());
            if (my_entry == NULL) {
                LOG_ERROR_MSG("Could not get password entry for " << _user << ". Check that " << _user << " is a valid user on this system.");
            } else {
                int rc = setegid(my_entry->pw_uid);
                if (rc != 0) {
                    char errorText[256];
                    LOG_ERROR_MSG("Could not set real and effective gids of this process: " << std::string(strerror_r(errno, errorText, 256)));
                }

                rc = seteuid(my_entry->pw_uid);
                if (rc != 0) {
                    char errorText[256];
                    LOG_ERROR_MSG("Could not set real and effective uids of this process: " << std::string(strerror_r(errno, errorText, 256)));
                }
            }
        }

        ScopeExit cleanup([&] { switchBackUID(my_euid, my_egid); });

        LOG_DEBUG_MSG("Running as " << geteuid() << " to kill " << pid << " with user " << _user);

        const auto kill_sent_time = std::chrono::steady_clock::now();

        unsigned timeout = 25000;
        bool signalSent = false;

        while (isRunning(pid)) {
            if (!signalSent) {
                if (signal == 0) {
                    signal = SIGTERM;
                    LOG_DEBUG_MSG("Killing " << pid << " with a SIGTERM");

                    const int killrc = ::kill(pid, SIGTERM);
                    if (killrc < 0) {
                        LOG_WARN_MSG("Failed to kill " << pid << " with SIGTERM.");
                    }
                } else {
                    LOG_DEBUG_MSG("Killing " << pid << " with signal " << signal);

                    const int killrc = ::kill(pid, signal);
                    if (killrc < 0) {
                        LOG_WARN_MSG("Failed to kill " << pid << " with signal " << signal);
                    }
                }

                signalSent = true;
            }

            const auto now = std::chrono::steady_clock::now();

            if (now - kill_sent_time > std::chrono::minutes(5)) {
                LOG_INFO_MSG("Initial signal failed. Killing " << pid << " with a SIGKILL.");
                signal = SIGKILL;

                const int killrc = ::kill(pid, SIGKILL);
                if (killrc < 0) {
                    LOG_ERROR_MSG("Failed to kill " << pid << " with SIGKILL.");
                }

                break;
            }

            usleep(timeout);

            timeout *= 2;

            // Max the sleep period to 5 seconds
            if (timeout > 5000000) {
                timeout = 5000000;
            }
        }
    }

    return signal;
}
