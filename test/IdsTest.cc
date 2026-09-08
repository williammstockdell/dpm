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

#include "master/common/Ids.h"

TEST_CASE("BinaryId can be constructed from its string representation") {

    std::string idstr = "bogus_host:12345";

    const BinaryId id{idstr};

    REQUIRE(id.str() == idstr);
}

TEST_CASE("BinaryId equality is value based") {
    const BinaryId a{"foo:12"};
    const BinaryId b{"foo:12"};
    const BinaryId c{"bar:56"};

    REQUIRE(a == b);
    REQUIRE(a != c);
}

TEST_CASE("Assignment assigns") {

    const BinaryId a{"bogus_host:12345"};
    const BinaryId b = a;
    const BinaryId c{"bogus_host:32145"};

    REQUIRE(a == b);
    REQUIRE(a != c);
}

TEST_CASE("Validate constructor") {

    REQUIRE_NOTHROW([&]() {BinaryId a("bogus_host:4567");}());
    CHECK_THROWS([&]() {BinaryId b("123");}());
    CHECK_THROWS([&]() {BinaryId c("bogus");}());
}
