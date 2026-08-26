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

#include <poll.h>
#include <errno.h>
#include <log4cxx/helpers/messagebuffer.h>
#include <log4cxx/logger.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <utility/include/Log.h>
#include <boost/assert.hpp>
#include <csignal>
#include <thread>
#include <chrono>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>

#include "Agent.h"
#include "MasterConnection.h"

LOG_DECLARE_FILE("master");

void MasterConnection::makeConnection() {

    while (!_ending) {

        static constexpr unsigned MaxAttempts = 30;

        bool connected = false;

        // Loop through all ports to attempt a connection.
        for (const bgq::utility::PortConfiguration::Pair& port : _ports) {

            unsigned attempts = 0;

            // Connect and join loop
            // cppcheck-suppress knownConditionTrueFalse
            while (!_ending && attempts < MaxAttempts) {
                if (attempts == 0) {
                    LOG_INFO_MSG("Attempting to connect on " << port.first << ":" << port.second);
                }

                try {
                    if (_agent->join(port) == 0) {
                        connected = true;
                        break;
                    }
                } catch (const std::exception& e) {
                    LOG_WARN_MSG(e.what());
                }

                ++attempts;

                if (!_ending) {
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
            }

            if (connected || _ending) {
                break;
            }

            LOG_WARN_MSG("Connection to dpm_server failed on " << port.first << ":" << port.second);
        }

        if (_ending) {
            break;
        }

        // Exhausted all configured ports; start over.
        if (connected)
            return;
    }
}

bool MasterConnection::pollConnection(const int signal_read_fd) {

    const int master_fd = _agent->getMasterFD();

    struct pollfd fds[2]{};

    fds[0].fd = signal_read_fd;
    fds[0].events = POLLIN;

    fds[1].fd = master_fd;
    fds[1].events = POLLIN;

    while (!_ending) {
        const int rc = ::poll(fds, 2, -1);

        if (rc < 0) {

            if (errno == EINTR) {
                continue;
            }

            throw std::runtime_error(std::string("poll failed: ") + strerror(errno));
        }

        if (fds[0].revents & POLLIN) {
            siginfo_t siginfo{};

            const ssize_t bytes = ::read(signal_read_fd, &siginfo, sizeof(siginfo));

            if (bytes == static_cast<ssize_t>(sizeof(siginfo))) {
                _ending = true;
                _agent->doEndAgentRequest(siginfo.si_signo);
                return false;
            }
        }

        if (fds[1].revents & (POLLERR | POLLHUP | POLLNVAL)) {
            return false;
        }

        if (fds[1].revents & POLLIN) {
            return true;
        }
    }

    return false;
}

void MasterConnection::run(const int signal_read_fd) {

    // Main thread loop
    makeConnection();

    // This point, we're connected.  Loop until we get an end flag.
    while (!_ending) {

        // Wait for either a signal or activity from dpm_server.
        if (!pollConnection(signal_read_fd)) {
            // Signal handling may have set _ending.
            if (_ending) {
                break;
            }
        }

        // Consume one request. processRequest() returns true
        // when the connection has failed and must be re-established.
        // This is a blocking wait on new requests.
        if (_agent->processRequest()) {

            LOG_INFO_MSG("Connection to dpm_server ended. "
                         "Waiting 5 seconds before attempting to reconnect.");

            std::this_thread::sleep_for(std::chrono::seconds(5));

            makeConnection();
        }
    }
}

MasterConnection::MasterConnection(const bgq::utility::PortConfiguration::Pairs& ports, Agent* const agent) : _ports(ports), _agent(agent) {
    LOG_TRACE_MSG(__FUNCTION__);
    BOOST_ASSERT(_agent);
    BOOST_ASSERT(!_ports.empty());
}

MasterConnection::~MasterConnection() { LOG_DEBUG_MSG("Terminating"); }
