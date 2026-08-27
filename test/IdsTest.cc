#include "catch2/catch_amalgamated.hpp"

#include "master/common/Ids.h"

TEST_CASE("BinaryId can be constructed from its string representation") {

    std::string idstr = "bogus_host:12345";

    const BinaryId id{idstr};

    REQUIRE(id.str() == idstr);
}

TEST_CASE("BinaryId equality is value based") {
    const BinaryId a{"foo"};
    const BinaryId b{"foo"};
    const BinaryId c{"bar"};

    REQUIRE(a == b);
    REQUIRE(a != c);
}
