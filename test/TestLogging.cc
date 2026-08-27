#include <log4cxx/basicconfigurator.h>
#include <log4cxx/logger.h>

namespace {

struct TestLoggingSetup {
    TestLoggingSetup() {
        log4cxx::BasicConfigurator::configure();
        log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getOff());
    }
};

TestLoggingSetup test_logging_setup;

}
