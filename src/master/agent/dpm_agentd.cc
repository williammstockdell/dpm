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

#include <filesystem>
#include <csignal>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <utility/include/BoolAlpha.h>
#include <utility/include/version.h>
#include <utility/include/LoggingProgramOptions.h>

#include "Agent.h"
#include "../common/ArgParse.h"


LOG_DECLARE_FILE( "master" );


namespace {

const std::vector<int> signals{SIGINT, SIGUSR1, SIGTERM, SIGPIPE };

// This gets updated when setupSignals runs
int signal_write_fd = -1;

}

// Signal handler
extern "C" void
dpm_agent_sighandler(
        int signum,
        siginfo_t* siginfo,
        void*
        )
{
    const int saved_errno = errno;
    (void)::write(signal_write_fd, &signum, sizeof(signum));
    errno = saved_errno;
}

int setupSignals() {
    int signal_descriptors[2];

#ifdef O_CLOEXEC
    if (pipe2(signal_descriptors, O_CLOEXEC | O_NONBLOCK) != 0)
#else
    if (pipe(signal_descriptors) != 0)
#endif
    {
        LOG_ERROR_MSG("Could not create pipe for signal handler.");
        exit(EXIT_FAILURE);
    }

    signal_write_fd = signal_descriptors[1];

    for (std::size_t i = 0; i < signals.size(); ++i) {
        struct sigaction action {};
        action.sa_sigaction = &dpm_agent_sighandler;
        action.sa_flags = SA_SIGINFO;
        sigemptyset(&action.sa_mask);

        const int rc = sigaction(signals[i], &action, nullptr);

        if (rc < 0) {
            LOG_ERROR_MSG(
                "Error setting up dpm_agent signal handler: "
                << strerror(errno)
            );
            exit(EXIT_FAILURE);
        }
    }

    return signal_descriptors[0];
}


std::string setlogging(
        std::string& logdir,
        const std::string& hostname
        )
{
    if (logdir.empty()) {
        // Use default
        logdir = "/var/log";
    }

    const std::string logfile( logdir + "/" + hostname + "-dpm_agentd.log" );

    // Now open it. User and group readable. User writable.
    const int openfd = open(logfile.c_str(), O_WRONLY|O_APPEND|O_CREAT,
                      S_IRUSR|S_IWUSR|S_IRGRP);
    if (openfd == -1) {
        const std::string error_str = "Error opening log file " + logfile;
        perror(error_str.c_str());
        exit( EXIT_FAILURE );
    }

    // One last notification before dumping output to file
    std::cout << "dpm_agentd [" << getpid() << "] starting and logging to " << logfile << std::endl;

    // And send stdout and stderr to it.
    dup2(openfd, STDOUT_FILENO);
    dup2(openfd, STDERR_FILENO);

    // Not using it any more.
    close(openfd);

    return logfile;
}


void usage() {

    std::cerr << "FIX THIS USAGE TEXT" << std::endl;
}

void help() {

    std::cerr << "FIX THIS HELP TEXT" << std::endl;
}


int main(int argc, const char** argv)
{

    std::vector<std::string> validargs;
    std::vector<std::string> singles;
    validargs.push_back("--debug");
    validargs.push_back("--logdir");
    validargs.push_back("--workingdir");
    validargs.push_back("--users");

    Args largs(argc, argv, &usage, &help, validargs, singles, AGENT);
    bgq::utility::Properties::Ptr props = largs.get_props();

    try {
        bgq::utility::LoggingProgramOptions lpo( "master.agent" );

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
     std::string workingdir = largs["--workingdir"];
     std::string users = largs["--users"];

    // Add host option
    bgq::utility::ClientPortConfiguration host(2041, bgq::utility::ClientPortConfiguration::ConnectionType::Administrative);


    host.setProperties( props, "master.agent" );
    host.notifyComplete();

    int signal_read_fd = setupSignals();

    Agent agent( props );

    if (!debug._value) {
        // Now find the logdir
        if (logdir.empty()) {
            try {

                logdir = largs["--logdir"];

                if(logdir.empty())
                   logdir = props->getValue("master.agent", "logdir");

            } catch (const std::invalid_argument& e) {
                LOG_ERROR_MSG("No logging directory specified or missing section. " << e.what());
                exit( EXIT_FAILURE );
            }
        }

        // Create log file and symlink
        setlogging(logdir, agent.get_hostname().uhn());

        // daemonize
        if (daemon(0, 1) < 0) {
            std::cerr << "Error trying to daemonize dpm_agentd: " << strerror(errno) << std::endl;
            exit( EXIT_FAILURE );
        }
    }

    if (debug._value) {
        LOG_INFO_MSG( argv[0] << " [" << getpid() << "] starting in debug mode." );
    }

    if (!workingdir.empty() ) {
        LOG_DEBUG_MSG("Changing working directory to: " << workingdir);
        const int rc = chdir(workingdir.c_str());
        if (rc) {
            LOG_FATAL_MSG("Could not change working directory to '" << workingdir << "', error is: " << strerror(errno));
            exit( EXIT_FAILURE );
        }
    }

    agent.set_users(users);

    struct rlimit rlimit_nofile = {0, 0}; // process limit on number of files
    struct rlimit rlimit_core = {0, 0};    // process limit on core file size
    rlimit_core.rlim_cur = RLIM_INFINITY;
    rlimit_core.rlim_max = RLIM_INFINITY;
    if (setrlimit(RLIMIT_CORE, &rlimit_core) < 0) {
        LOG_WARN_MSG("Could not set core dump limit to unlimited. May not be able to capture any core dumps for debug.");
    }
    getrlimit(RLIMIT_NOFILE, &rlimit_nofile); // get the current process file descriptor limit
    if (rlimit_nofile.rlim_cur < 819200) {
        rlimit_nofile.rlim_max = 819200;
        rlimit_nofile.rlim_cur = 819200;

        if (setrlimit(RLIMIT_NOFILE, &rlimit_nofile) < 0) {
            LOG_WARN_MSG("Could not increase file descriptor rlimits, some programs may be resource constrained. Current rlimits setting is "
                         << rlimit_nofile.rlim_cur);
        }
    }

    getrlimit(RLIMIT_CORE, &rlimit_core); // get the current process core file limit
    LOG_DEBUG_MSG("Core limits: " << rlimit_core.rlim_cur);
    LOG_DEBUG_MSG("File limits: " << rlimit_nofile.rlim_cur);

    LOG_INFO_MSG("dpm_agentd [" << getpid() << "] " <<

            std::filesystem::path(argv[0]).stem().string() <<
            " " << "Fred" << " (revision " << "Barney" << ") " <<
            __DATE__ << " " << __TIME__ << " starting"
            );
    agent.start(host.getPairs(), signal_read_fd);
}
