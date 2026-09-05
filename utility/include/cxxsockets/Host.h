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
/*!
 * \file Host.h
 */

#ifndef UTILITY_CXXSOCKETS_HOST_H_
#define UTILITY_CXXSOCKETS_HOST_H_

#include <string>

namespace CxxSockets {

enum class HostSpecType {
    IpAddress,
    Uhn,
    Fqhn
};

//! \brief Representation of a Host in an IP network.  Encapsulates
//! the name and the IPv4 or IPv6 address.
class Host {

    mutable std::string _ip;
    mutable std::string _name;

    //! \brief the specification is a unique identifier for this host assigned at construction.
    mutable std::string _specification;
    mutable HostSpecType _spec_type;

    //! \brief This is the primary, preferred host.
    bool _primary;

    void build(const std::string& identifier);
    void resolve(const std::string& identifier) const;
    void inferSpecType(const std::string& identifier) const;

  public:
    //! \brief Default constructor.
    Host() : _ip(), _name(), _specification(""), _spec_type(HostSpecType::Uhn), _primary(false) {}

    //! \brief Constructor
    //! \param identifier Either an IP address or host name.
    explicit Host(const std::string& identifier) : _specification(identifier), _spec_type(HostSpecType::Uhn) {
        build(identifier);
        _primary = false;
    }

    bool matches(const Host& actual) const;

    bool operator==(const Host& host) const { return matches(host); }
    bool operator<(const Host& h) const { return _specification < h._specification; }

    //! \brief return the specification
    const std::string& spec() const { return _specification; }

    //! \brief return the ip address
    const std::string& ip() const;

    //! \brief Return the fully qualified host name.
    //  ex: 'foo.bar.com'
    const std::string& fqhn() const;

    //! \brief Return unqualified host name. ex: 'foo'
    std::string uhn() const;

    void set_primary(bool p) { _primary = p; }
    bool get_primary() const { return _primary; }
};

} // namespace CxxSockets

#endif
