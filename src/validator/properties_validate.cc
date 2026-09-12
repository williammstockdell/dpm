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

#include "../master/lib/exceptions.h"
#include "../master/server/LockFile.h"
#include "../master/server/MasterController.h"
#include <iostream>
#include <sstream>
#include <utility/include/Log.h>
#include <utility/include/LoggingProgramOptions.h>
#include <utility/include/portConfiguration/ClientPortConfiguration.h>
#include "../master/common/ArgParse.h"

// Bogus value to make bgmaster translation units happy.
LockFile* lock_file;
bgq::utility::Properties::Ptr props;

// Global list of valid servers.
std::vector<std::string> valid_server_names;

void server_names() {
    std::cerr << "Valid server names are:" << std::endl;
    for (const std::string& curr_server : valid_server_names) {
        std::cout << curr_server << std::endl;
    }
}

void help() {
    std::cout << "properties_validate examines the sections of the bg.properties file" << std::endl;
    std::cout << "related to server configuration.  It ensures that the" << std::endl;
    std::cout << "configuration options that must be present are there and that " << std::endl;
    std::cout << "dependencies are met.  Any failures detected here would also cause" << std::endl;
    std::cout << "servers to fail on startup." << std::endl << std::endl;
    std::cout << "By default, configuration for all supported servers is checked." << std::endl;
    std::cout << "The --server|-s option allows specification of specific servers." << std::endl;
}

void doBGMaster() {
    std::cout << "Evaluating DPM properties...." << std::endl;
    MasterController bgm(props);

    std::ostringstream failmsg;
    try {
        bgm.buildPolicies(failmsg);
    } catch (const exceptions::ConfigError& e) {
        std::cerr << "BGmaster Configuration error detected. " << e.errcode << " " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch (const std::runtime_error& e) {
        std::cerr << "BGmaster Configuration error detected. " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void usage() { std::cerr << "FIX THIS USAGE TEXT" << std::endl; }


int main(int argc, const char** argv) {

    // Parse --properties and --verbose before everything else

    std::vector<std::string> validargs;
    std::vector<std::string> singles;
    singles.push_back("-f");

    Args largs(argc, argv, &usage, &help, validargs, singles, SERVER);
    bgq::utility::Properties::Ptr props = largs.get_props();

    try {

        bgq::utility::LoggingProgramOptions lpo("dpm.master");

        // Create properties and initialize logging
        bgq::utility::initializeLogging(*props, lpo, std::string("master"));
    } catch (const std::runtime_error& e) {
        std::cerr << "Error reading configuration file: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "validating " << props->getFilename() << std::endl;

    std::vector<std::string> servers;
    servers.push_back("dpm_server");

    if (servers.size() == 0) {
        servers = valid_server_names;
    }

    for (const std::string& curr_server : servers) {
        if (curr_server == "dpm_server") {
            doBGMaster();
        } else {
            std::cerr << "Invalid server name \"" << curr_server << "\".  ";
            server_names();
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "No errors detected for servers ";
    for (const std::string& curr_server : servers) {
        std::cout << curr_server << " ";
    }
    std::cout << std::endl;
}
