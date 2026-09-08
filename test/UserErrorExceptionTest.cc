/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of Will Stockdell                  */
/*                                                                  */
/* DPM -- Distributed Process Manager                               */
/*                                                                  */
/* (C) Copyright Will Stockdell 2026                                */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL) version 1.0                         */
/*                                                                  */
/* ================================================================ */

#include "catch2/catch_amalgamated.hpp"
#include <netinet/tcp.h>
#include <utility/include/Properties.h>
#include <utility/include/cxxsockets/FileSet.h>
#include <utility/include/cxxsockets/ListenerSet.h>
#include <utility/include/cxxsockets/SockAddrList.h>
#include <utility/include/cxxsockets/TCPSocket.h>

using namespace bgq::utility;
using namespace CxxSockets;

TEST_CASE(" file_set ")
{
    struct Foo : public CxxSockets::FileSet
    {

    };

    Foo f;
    const TCPSocketPtr foo( new TCPSocket );

    // add first should be ok
    f.AddFile( foo );

    // duplicate should throw
    CHECK_THROWS_AS(f.AddFile(foo), UserError);
}

TEST_CASE(" sock_addr_list ")
{
    SockAddrList* list;
    CHECK_THROWS_AS(list = new SockAddrList( 0, std::string(), std::string()), UserError);
}

TEST_CASE(" tcp_socket ")
{
    TCPSocket* t;

    // descriptor and family both 0
    CHECK_THROWS_AS(t = new TCPSocket( 0, 0 ), UserError);
}

TEST_CASE(" listener_set ")
{
    SockAddrList list; // empty list
    ListenerSet* l;
    CHECK_THROWS_AS(l = new ListenerSet(list), UserError);
}
