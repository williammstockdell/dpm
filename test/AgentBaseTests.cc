#include "catch2/catch_amalgamated.hpp"

#define protected public

#include "master/common/AgentBase.h"
#include "master/server/AgentRep.h"
#include "master/common/BinaryController.h"


TEST_CASE("Add a binary and find it") {

    const BinaryId bid{"bogus_host:1234"};

    auto binary = std::make_shared<BinaryController>(bid, "/usr/bin/sleep", "sleeper", "bob", 6, 0, "2026-Jan-01 12:12:12");

    AgentBase ab;

    ab.addController(binary);
    CHECK(ab.find_binary(bid, binary));

    ab.removeController(binary);
    CHECK(ab.find_binary(bid, binary) == false);
}
#undef protected
