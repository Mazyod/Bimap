//
// Created by Mazyad Alabduljaleel on 8/11/15.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <Bimap/Bimap.h>


TEST_CASE("Something happens") {

    Bimap<std::string, int> bimap;

    bimap.set("test", 5);
    bimap.set("key", 10);

    REQUIRE(bimap.valueForKey("test") == 5);
    REQUIRE(bimap.keyForValue(10) == "key");

    REQUIRE(bimap.hasKey("test"));
    REQUIRE(bimap.hasValue(5));

    REQUIRE_FALSE(bimap.hasKey("bad"));
    REQUIRE_FALSE(bimap.hasValue(6));

    REQUIRE(bimap.removeKey("test"));
    REQUIRE_FALSE(bimap.hasValue(5));
    REQUIRE_FALSE(bimap.hasKey("test"));

    REQUIRE(bimap.removeValue(10));
    REQUIRE_FALSE(bimap.hasKey("key"));
    REQUIRE_FALSE(bimap.hasValue(10));
}
