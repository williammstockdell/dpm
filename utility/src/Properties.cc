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

#include <Properties.h>
#include <Log.h>
#include <Trim.h>
#include <string.h>
#include <log4cxx/logger.h>
#include <stdint.h>
#include <stdlib.h>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <shared_mutex>
#include <stdexcept>
#include <string>
#include <exception>
#include <map>
#include <mutex>
#include <utility>
#include <vector>

using std::string;

LOG_DECLARE_FILE("utility");

namespace bgq {
namespace utility {

#include <algorithm>

//---------------------------------------------------------------------
// class Properties

const std::string Properties::EnvironmentalName("DPM_PROPERTIES_FILE");
const std::string Properties::DefaultLocation("/opt/etc/dpm.properties");

Properties::Properties(const std::string& file) : _filename(file), _map(), _mutex() { this->read(); }

void Properties::read() {
    // get filename
    if (_filename.empty()) {
        // use env value
        if (getenv(EnvironmentalName.c_str())) {
            _filename = getenv(EnvironmentalName.c_str());
        } else {
            // use default
            _filename = DefaultLocation;
        }
    }

    // open config file
    std::ifstream stream(_filename.c_str());
    if (!stream) {
        char buf[256];
        throw(FileError("could not open properties " + _filename + " (" + strerror_r(errno, buf, sizeof(buf)) + ")"));
    }

    // parse config file
    unsigned int lineno = 0;
    Map::iterator section = _map.end();
    while (stream) {
        // get line
        std::string line;
        std::getline(stream, line);
        ++lineno;

        // strip comments after '#'
        std::string::size_type comment = line.find_first_of('#');
        if (comment != std::string::npos) {
            line.erase(comment);
        }

        // trim left white space
        trim_left(line);

        // ignore empty lines
        if (line.empty()) {
            continue;
        }

        // look for section markers
        if (line.at(0) == '[') {
            section = this->parseSection(line, lineno);
        } else if (section != _map.end()) {
            this->parseLine(section, line, lineno);
        } else {
            throw(MissingSection("line " + std::to_string(lineno) + " of properties file " + _filename + " is invalid"));
        }
    }
}

Properties::Map::iterator Properties::parseSection(const std::string& line, uint32_t lineno) {
    // ensure we have left brackets
    std::string::size_type leftBracket = line.find_first_of('[');
    if (leftBracket == std::string::npos) {
        throw(MalformedSection("missing [ character at line " + std::to_string(lineno) + " in file " + _filename));
    }

    // ensure we have right bracket
    std::string::size_type rightBracket = line.find_first_of(']', leftBracket);
    if (rightBracket == std::string::npos) {
        throw(MalformedSection("missing ] character at line " + std::to_string(lineno) + " in file " + _filename));
    }

    // get section name
    std::string name = line.substr(leftBracket + 1, rightBracket - leftBracket - 1);

    // strip white space
    trim(name);

    // make sure we don't have this section
    Map::const_iterator section = _map.find(name);
    if (section != _map.end()) {
        throw(DuplicateSection("section " + name +
                               " already exists"
                               " in properties file " +
                               _filename));
    }

    // add section
    Map::iterator result = _map.insert(Map::value_type(name, Section())).first;
    return result;
}

void Properties::parseLine(Map::iterator sectionIterator, const std::string& line, uint32_t lineno) {
    // look for equals char
    std::string::size_type equals = line.find_first_of('=');
    if (equals == std::string::npos) {
        throw(MalformedKey("line " + std::to_string(lineno) +
                           " missing equals token"
                           " in properties file " +
                           _filename));
    }

    // tokenize
    std::string key = line.substr(0, equals);
    std::string value = line.substr(equals + 1);

    // trim white space
    trim(key);
    trim(value);

    // make sure we don't have this key
    try {
        this->getValueImpl(sectionIterator->first, key);
        throw(DuplicateKey("found duplicate key in section " + sectionIterator->first + " of properties file " + _filename));
    } catch (const std::invalid_argument& e) {
        // fall through
    }

    // add to section
    Pair pair(key, value);
    sectionIterator->second.push_back(pair);
}

const std::string& Properties::getValue(const std::string& sectionName, const std::string& keyName) const {
    // acquire read lock
    std::shared_lock<Mutex> lock(_mutex);
    return this->getValueImpl(sectionName, keyName);
}

const std::string& Properties::getValueImpl(const std::string& sectionName, const std::string& keyName) const {
    const Section& section = getValuesImpl(sectionName);

    const auto keyIterator = std::find_if(section.begin(), section.end(), [&keyName](const auto& entry) { return entry.first == keyName; });

    if (keyIterator == section.end()) {
        throw std::invalid_argument("could not find key " + keyName + " in section " + sectionName + " of properties file " + _filename);
    }

    return keyIterator->second;
}

const Properties::Section& Properties::getValues(const std::string& sectionName) const {
    // acquire read lock
    std::shared_lock<Mutex> lock(_mutex);
    return this->getValuesImpl(sectionName);
}

const Properties::Section& Properties::getValuesImpl(const std::string& sectionName) const {
    // find section
    Map::const_iterator sectionIterator = _map.find(sectionName);
    if (sectionIterator == _map.end()) {
        throw(std::invalid_argument("Could not find section " + sectionName + " in properties file " + _filename));
    }

    return sectionIterator->second;
}

bool Properties::reload(const std::string& filename) {
    // ensure filename is fully qualified
    if (!filename.empty() && !std::filesystem::path(filename).is_absolute()) {
        LOG_WARN_MSG(filename << " is not a fully qualified path");
        throw(std::invalid_argument(filename));
    }

    // acquire write lock
    std::unique_lock<Mutex> unique(_mutex);

    // retain copy
    Map map;
    map.swap(_map);

    // reset filename
    std::string old_filename(_filename);
    if (!filename.empty()) {
        _filename = filename;
    }

    // try to read
    try {
        this->read();
        return true;
    } catch (const std::exception& e) {
        // restore old values
        _map.swap(map);
        _filename = old_filename;
        throw;
    }
}

} // namespace utility
} // namespace bgq
