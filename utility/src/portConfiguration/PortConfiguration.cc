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

#include "portConfiguration/PortConfiguration.h"

#include <Properties.h>
#include <log4cxx/logger.h>
#include <stdint.h>
#include <stdexcept>
#include <string>
#include <cstddef>
#include <exception>
#include <memory>
#include <vector>

#include "Log.h"

using std::string;

LOG_DECLARE_FILE("utility");

namespace bgq {
namespace utility {

PortConfiguration::Pair PortConfiguration::parsePortStr(const std::string& port_str, const std::string& default_service_name) {
    std::string host_name;
    std::string service_name = default_service_name;

    if (port_str.empty()) {
        return {host_name, service_name};
    }

    if (port_str.front() == '[') {
        const auto close = port_str.find(']');

        if (close == std::string::npos) {
            throw InvalidPortStr("host:port value '" + port_str + "' is not valid");
        }

        host_name = port_str.substr(1, close - 1);

        if (close + 1 < port_str.size()) {
            if (port_str[close + 1] != ':') {
                throw InvalidPortStr("host:port value '" + port_str + "' is not valid");
            }

            service_name = port_str.substr(close + 2);
        }
    } else {
        const auto colon = port_str.find(':');

        if (colon == std::string::npos) {
            host_name = port_str;
        } else {
            host_name = port_str.substr(0, colon);
            service_name = port_str.substr(colon + 1);
        }
    }

    return {host_name, service_name};
}

void PortConfiguration::parsePortsStr(const std::string& ports_str, const std::string& default_service_name, Pairs& pairs_out) {
    std::size_t start = 0;

    while (start <= ports_str.size()) {
        const auto end = ports_str.find(',', start);

        const std::string token = ports_str.substr(start, end == std::string::npos ? std::string::npos : end - start);

        pairs_out.push_back(parsePortStr(token, default_service_name));

        if (end == std::string::npos) {
            break;
        }

        start = end + 1;
    }
}

void PortConfiguration::parsePortsStrs(const Strings& ports_strs, const std::string& default_service_name, Pairs& pairs_out) {
    for (Strings::const_iterator i(ports_strs.begin()); i != ports_strs.end(); ++i) {
        parsePortsStr(*i, default_service_name, pairs_out);
    }
}

PortConfiguration::PortConfiguration(uint32_t default_tcp_port) : _default_service_name(std::to_string(default_tcp_port)) {
    // Nothing to do.
}

PortConfiguration::PortConfiguration(const std::string& default_service_name) : _default_service_name(default_service_name) {
    // Nothing to do.
}

void PortConfiguration::setProperties(Properties::ConstPtr properties_ptr, const std::string& section_name) {
    _properties_ptr = properties_ptr;
    _section_name = section_name;
}

const PortConfiguration::Pairs& PortConfiguration::getPairs() const { return _pairs; }

void PortConfiguration::setPorts(const Strings& ports_strs) {
    _pairs.clear();
    parsePortsStrs(ports_strs, _default_service_name, _pairs);
}

void PortConfiguration::notifyComplete() {
    _handlePairsComplete();

    if (_properties_ptr) {
        try {
            _administrative_cn = _properties_ptr->getValue("security.admin", "cn");
        } catch (std::exception& e) {
            LOG_WARN_MSG("Administrative CN isn't configured in the properties.");
        }

        try {
            _command_cn = _properties_ptr->getValue("security.command", "cn");
        } catch (std::exception& e) {
            LOG_WARN_MSG("Command CN isn't configured in the properties.");
        }
    }
}

void PortConfiguration::_handlePairsComplete() {
    if (!_pairs.empty()) {
        return;
    }

    // If properties has been set, see if can use the value in the properties file.

    if (_properties_ptr && (!_section_name.empty())) {
        try {
            string ports_str(_properties_ptr->getValue(_section_name, _getPropertyName()));
            parsePortsStr(ports_str, _default_service_name, _pairs);
            return;
        } catch (const std::invalid_argument& e) {
            LOG_WARN_MSG(e.what());
            // fall through and use default
        }
    }

    // Otherwise, use the default.

    _pairs = _getDefault();
}

} // namespace utility
} // namespace bgq
