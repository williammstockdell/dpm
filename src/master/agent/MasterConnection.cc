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

#include "MasterConnection.h"
#include "Agent.h"

LOG_DECLARE_FILE( "master" );

void MasterConnection::run()
{
    static constexpr unsigned MaxAttempts = 30;

    // Main thread loop

    while (!_ending) {

        bool connected = false;

        // Loop through all ports to attempt a connection.
        for (const bgq::utility::PortConfiguration::Pair& port : _ports) {

            unsigned attempts = 0;

            // Connect and join loop
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
        if (!connected) {

            continue;
        }

        // This point, we're connected.  Loop until we get an end flag.

        while (!_ending) {

            // This is a blocking wait on new requests.
            _agent->processRequest();
        }

        if (!_ending) {
            LOG_INFO_MSG("Connection to dpm_server ended. Waiting 5 seconds before attempting to reconnect.");

            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}


MasterConnection::MasterConnection(const bgq::utility::PortConfiguration::Pairs& ports, Agent* const agent) :
    _ports( ports ),
    _agent( agent )
{
    LOG_TRACE_MSG( __FUNCTION__ );
    BOOST_ASSERT( _agent );
    BOOST_ASSERT( !_ports.empty() );
}

MasterConnection::~MasterConnection()
{
    LOG_DEBUG_MSG( "Terminating" );
}
