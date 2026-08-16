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

#include <openssl/conf.h>
#include <openssl/engine.h>
#include <csignal>
#include <fcntl.h>

#include <utility/include/BoolAlpha.h>
#include <utility/include/Log.h>
#include <utility/include/LoggingProgramOptions.h>
#include <utility/include/version.h>
#include <utility/include/ScopeExit.h>
#include <filesystem>

#include "LockFile.h"
#include "MasterController.h"
#include "ras.h"

#include "lib/exceptions.h"

#include "../common/ArgParse.h"

LOG_DECLARE_FILE( "master" );

namespace {

const std::vector<int> signals{SIGINT, SIGUSR1, SIGTERM, SIGPIPE };

int signal_fd;

}

LockFile* lock_file = 0;

extern "C" void
dpm_master_server_sighandler(
        int /* signum */,
        siginfo_t* siginfo,
        void*
        )
{
    (void)write( signal_fd, siginfo, sizeof(siginfo_t) );
}

bool
setlogging(
        std::string& logdir
        )
{
    if (logdir.empty()) {
        // Use default
        logdir = "/var/log";
    }

    char hostname[HOST_NAME_MAX];
    if (gethostname(hostname, sizeof(hostname)) < 0) {
        char errorText[256];
        LOG_WARN_MSG( "Host name error: " << strerror_r(errno, errorText, 256) );
    }

    const CxxSockets::Host host(hostname);

    const std::string logfile = logdir + "/" + host.uhn() + "-dpm_master_server.log";
    LOG_INFO_MSG( "Log file is " << logfile );
    // Now open it.  User and group readable.  User writable.
    const int openfd = open(logfile.c_str(), O_WRONLY|O_APPEND|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP);
    if (openfd == -1) {
        LOG_FATAL_MSG( "Error opening log file " << logfile );
        LOG_FATAL_MSG( strerror(errno) );
        return false;
    }

    // Send stdout and stderr to it.
    dup2(openfd, STDOUT_FILENO);
    dup2(openfd, STDERR_FILENO);

    // Not using it any more.
    close(openfd);

    return true;
}

void usage() {

    std::cerr << "FIX THIS USAGE TEXT" << std::endl;
}

void help() {

    std::cerr << "FIX THIS HELP TEXT" << std::endl;
}

int
main(int argc, const char** argv)
{
    // Parse --properties and --verbose before everything else

    std::vector<std::string> validargs;
    std::vector<std::string> singles;

    Args largs(argc, argv, &usage, &help, validargs, singles, false);
    bgq::utility::Properties::Ptr props = largs.get_props();

    try {
        bgq::utility::LoggingProgramOptions lpo( "dpm.master" );

        // Create properties and initialize logging
        bgq::utility::initializeLogging(*props, lpo, std::string("master"));
    } catch (const std::runtime_error& e) {
        std::cerr << "Error reading configuration file: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } catch ( const std::exception& e ) {
        std::cerr << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }

    bgq::utility::BoolAlpha debug;


    std::string logdir;
    try {
        logdir = props->getValue("master.server", "logdir");
    } catch (const std::invalid_argument& e) {
        LOG_WARN_MSG( "No log directory found, will use default. Error is: " << e.what() );
    }

    std::string master_instances = "1";
    try {
        master_instances = props->getValue("master.policy.instances", "dpm_master_server");
    } catch (const std::invalid_argument& e) {
        // Don't care if it isn't there.
    }

    ScopeExit cleanup( []  {
        delete lock_file;
        lock_file = 0;
    });

    if (!debug._value) {
        if (master_instances == "1") {
            lock_file = new LockFile("dpm_master_server");
            if (lock_file->_fileExists ) {
                LOG_FATAL_MSG(
                        "Lock file for dpm_master_server found. End dpm_master_server process "
                        << lock_file->_pid << " and remove " << lock_file->_fname
                        );
                exit(EXIT_FAILURE);
            }
        }

        if (!setlogging(logdir)) {
            if (lock_file) {
                delete lock_file;
                lock_file = 0;
            }
            exit(EXIT_FAILURE);
        }

        // Run as background process
        if (daemon(1, 1) < 0) {
            LOG_FATAL_MSG( "Error trying to daemonize dpm_master_server: " << strerror(errno) );
            exit(-1);
        }
    }

    if (lock_file) {
        lock_file->setpid();
    }

    // Create pipe for signal handler
    int signal_descriptors[2];

#ifdef O_CLOEXEC
    if ( pipe2(signal_descriptors, O_CLOEXEC) != 0 ) {
#else
    if ( pipe(signal_descriptors) != 0 ) {
#endif
        LOG_ERROR_MSG( "Could not create pipe for signal handler." );
        exit( EXIT_FAILURE );
    }

    signal_fd = signal_descriptors[1];

    // Signal handlers
    for (size_t i = 0; i < signals.size(); ++i)
    {
        struct sigaction action;
        action.sa_sigaction = &dpm_master_server_sighandler;
        action.sa_flags = SA_SIGINFO;
        int rc = sigaction(signals[i], &action, 0);
        if (rc < 0)
        {
            LOG_ERROR_MSG("Error setting up dpm_master_server signal handler: " << strerror(errno));
            exit(1);
        }
    }

    // Construct master controller
    MasterController master(props);
    try {
        master.startup(signal_descriptors[0]);
    } catch (const exceptions::ConfigError& e) {
        LOG_ERROR_MSG("Invalid configuration file entry: " << e.what());
        std::map<std::string, std::string> details;
        details["PID"] = std::to_string(getpid());
        details["ERROR"] = e.what();

    }

    std::cout << "BAILING" << std::endl;
    // Stop threads
    MasterController::stopThreads(true, SIGTERM);

    // OpenSSL hygiene
    ENGINE_cleanup();
    CONF_modules_free();
}
