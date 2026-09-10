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

#define protected public

#include <utility/include/cxxsockets/Host.h>
#include <iostream>

TEST_CASE("default_ctor")
{
    CxxSockets::Host h;

    CHECK( h.ip() == "0.0.0.0" );
    CHECK( h.fqhn() == "0.0.0.0" );
    CHECK( h.uhn() == "0.0.0.0" );
}

TEST_CASE("localhost_explicit_ctor")
{
    CxxSockets::Host h( "127.0.0.1" );
    CHECK( !h.ip().empty() );
    CHECK( !h.fqhn().empty() );
    CHECK( !h.uhn().empty() );
}

TEST_CASE("equality_operator")
{
    CxxSockets::Host h1( "127.0.0.1" );
    CxxSockets::Host h2( "192.168.0.1" );
    CHECK( h1 == h1 );
    CHECK( h2 == h2 );
}

TEST_CASE("less_than_operator")
{
    CxxSockets::Host h1( "1.9.1.9" );
    CxxSockets::Host h2( "1.9.1.10" );
    if ( !(h1 == h2) ) {
        CHECK( h2 < h1 );
    }
}
