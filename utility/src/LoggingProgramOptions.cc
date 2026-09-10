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

#include <LoggingProgramOptions.h>
#include <Log.h>
#include <log4cxx/helpers/messagebuffer.h>
#include <log4cxx/level.h>
#include <log4cxx/logger.h>
#include <log4cxx/spi/loggerrepository.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <memory>
#include <utility>
#include <vector>
#include <utility/include/LogHelper.h>

using log4cxx::Level;
using log4cxx::LevelPtr;
using log4cxx::Logger;

using std::string;

LOG_DECLARE_FILE("utility");

static bool debug(false);


namespace bgq {
namespace utility {

LevelPtr LoggingProgramOptions::parseVerboseArgument(const string& level_str) {
    // Single letters.
    if (level_str == "O" || level_str == "o")
        return Level::getOff();
    if (level_str == "F" || level_str == "f")
        return Level::getFatal();
    if (level_str == "E" || level_str == "e")
        return Level::getError();
    if (level_str == "W" || level_str == "w")
        return Level::getWarn();
    if (level_str == "I" || level_str == "i")
        return Level::getInfo();
    if (level_str == "D" || level_str == "d")
        return Level::getDebug();
    if (level_str == "T" || level_str == "t")
        return Level::getTrace();
    if (level_str == "A" || level_str == "a")
        return Level::getAll();

    int level_int(std::stoi(level_str));

    switch (level_int) {
    case 0:
        return Level::getOff();
    case 1:
        return Level::getFatal();
    case 2:
        return Level::getError();
    case 3:
        return Level::getWarn();
    case 4:
        return Level::getInfo();
    case 5:
        return Level::getDebug();
    case 6:
        return Level::getTrace();
    case 7:
        return Level::getAll();
    }

    throw(std::invalid_argument("invalid verbose option '" + level_str + "'"));
}

LoggingProgramOptions::LoggingProgramOptions(const std::string& default_logger_name) : _default_logger_name(default_logger_name) {
    // Nothing to do.
}

void LoggingProgramOptions::notifier(const Strings& strs) {
    for (Strings::const_iterator i(strs.begin()); i != strs.end(); ++i) {
        const string& str(*i);

        if (debug)
            std::cerr << __FUNCTION__ << " called with '" << str << "'\n";

        string logger_name;
        LevelPtr level_ptr;

        _parseVerboseString(str, logger_name, level_ptr);

        if (debug)
            std::cerr << __FUNCTION__ << " -> '" << logger_name << "'='" << (level_ptr ? level_ptr->toString() : "null") << "'\n";

        _logging_levels[logger_name] = level_ptr;
    }
}


void LoggingProgramOptions::apply() const {

    // Go through the stored logging settings and apply to the current logging configuration.

    for (LoggingLevels::const_iterator i(_logging_levels.begin()); i != _logging_levels.end(); ++i) {
        Logger::getLogger(i->first)->setLevel(i->second);
    }

    // Log current logger settings.
    const auto root = log4cxx::Logger::getRootLogger();

    if (const auto repo = getRepository(root->getLoggerRepository())) {
        for (const log4cxx::LoggerPtr& curr_loggerp : repo->getCurrentLoggers()) {
            const log4cxx::LevelPtr level = curr_loggerp->getLevel();

            LOG_DEBUG_MSG(curr_loggerp->getName() << "=" << (level ? level->toString() : "<inherited>"));
        }
    }
}


void LoggingProgramOptions::_parseVerboseString(const std::string& str, std::string& logger_name_out, log4cxx::LevelPtr& level_ptr_out) {
    if (str.empty()) {
        logger_name_out = _default_logger_name;
        level_ptr_out = Level::getDebug();
        return;
    }

    string::size_type split_pos(str.find('='));

    if (split_pos == string::npos) {         // didn't find =, so is either a logger name or a level.
        if (str.find('.') == string::npos) { // no . so it's a level.
            logger_name_out = _default_logger_name;
            level_ptr_out = parseVerboseArgument(str);
            return;
        }

        // found a . so it's a logger name.
        logger_name_out = str;
        level_ptr_out = Level::getDebug();
        return;
    }

    // found = so it's a logger name and level.

    logger_name_out = str.substr(0, split_pos);
    level_ptr_out = parseVerboseArgument(str.substr(split_pos + 1));
}

} // namespace utility
} // namespace bgq
