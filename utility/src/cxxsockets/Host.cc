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

#include "cxxsockets/Host.h"

#include <log4cxx/logger.h>
#include <sys/socket.h>
#include <sstream>
#include <cstddef>
#include <string>
#include <arpa/inet.h>
#include "cxxsockets/SockAddr.h"
#include "cxxsockets/exception.h"
#include "Log.h"

LOG_DECLARE_FILE("utility.cxxsockets");

namespace CxxSockets {

bool looksLikeIpAddress(const std::string& value) {

    in_addr ipv4{};
    in6_addr ipv6{};

    return inet_pton(AF_INET, value.c_str(), &ipv4) == 1 ||
           inet_pton(AF_INET6, value.c_str(), &ipv6) == 1;
}

void Host::inferSpecType(const std::string& identifier) const {

    if (looksLikeIpAddress(identifier)) {
        _spec_type = HostSpecType::IpAddress;
    } else if (identifier.find('.') != std::string::npos) {
        _spec_type = HostSpecType::Fqhn;
    } else {
        _spec_type = HostSpecType::Uhn;
    }
}

void Host::resolve(const std::string& identifier) const {
    LOG_TRACE_MSG("resolving " << identifier);

    try {
        SockAddr sa(AF_UNSPEC, identifier, "");
        _ip = sa.getHostAddr();
        _name = sa.getHostName();

        if (_name == _ip) {
            LOG_DEBUG_MSG("Unresolved IP: " << _ip << ":" << _name);
            _name = _ip;
        }

    } catch (const SoftError& e) {
        LOG_DEBUG_MSG(e.what() << " Will use IP address instead of name.");
    } catch (const Error& e) {
        std::ostringstream errormsg;
        errormsg << "Invalid host specification " << identifier << ". Not resolvable on local network. "
                 << "Check DNS, hostname and local network settings. " << e.what();
        LOG_DEBUG_MSG(errormsg.str());
        throw Error(e.errcode, errormsg.str());
    }
}

bool Host::matches(const Host& actual) const {

    switch (_spec_type) {
        case HostSpecType::IpAddress:
            return _specification == actual.ip();

        case HostSpecType::Uhn:
            return _specification == actual.uhn();

        case HostSpecType::Fqhn:
            return _specification == actual.fqhn();
    }

    return false;
}

const std::string& Host::ip() const {

    if(_ip.empty())
        resolve(_name);
    return _ip;
}

void Host::build(const std::string& identifier) {
    LOG_TRACE_MSG("Building " << identifier);

    inferSpecType(identifier);

    try {
        resolve(identifier);
    } catch(const Error& e) {
        LOG_WARN_MSG(e.what() << " Startup name resolution not available. Will pick up next time.");
        _name = identifier;
    }
}

const std::string& Host::fqhn() const { return _name; }

std::string Host::uhn() const {
    if (_name == _ip) {
        return _ip;
    }

    const std::size_t dot = _name.find('.');

    if (dot == std::string::npos) {
        return _name;
    }

    return _name.substr(0, dot);
}

} // namespace CxxSockets
