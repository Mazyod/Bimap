//
// Created by Mazyad Alabduljaleel on 8/11/15.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <Bimap/Bimap.h>


TEST_CASE("Something happens") {

    Bimap<std::string, int> bimap;

    bimap.set("test", 5);
    bimap.set("test again", 5);
    bimap.set("key", 10);
    bimap.set("key again", 10);

    /* test query methods */
    // given a key, the value is returned
    REQUIRE(bimap.valueForKey("test") == 5);
    // given a value, associated keys are returned
    auto& keys = bimap.keysForValue(10);
    REQUIRE(keys.size() == 2);
    REQUIRE(keys.find("key") != keys.end());

    /* test has methods */
    // given an available key, true is returned
    REQUIRE(bimap.hasKey("test"));
    // given an available value, true is returned
    REQUIRE(bimap.hasValue(5));

    // given an unavailable key, false is returned
    REQUIRE_FALSE(bimap.hasKey("bad"));
    // given an unavailable key, false is returned
    REQUIRE_FALSE(bimap.hasValue(6));

    /* test remove methods */
    // removing an existing key succeeds
    REQUIRE(bimap.removeKey("test"));
    // a duplicate value remains, referenced by other key
    REQUIRE(bimap.hasValue(5));
    // removing the other key succeeds
    REQUIRE(bimap.removeKey("test again"));
    // value is no longer referenced, and disappears
    REQUIRE_FALSE(bimap.hasValue(5));
    // make sure the key doesn't exist
    REQUIRE_FALSE(bimap.hasKey("test"));

    // given multiple keys reference one value
    REQUIRE(bimap.hasKey("key"));
    REQUIRE(bimap.hasKey("key again"));
    // when the value is removed
    REQUIRE(bimap.removeValue(10));
    // all keys disappear, as well as the value
    REQUIRE_FALSE(bimap.hasKey("key"));
    REQUIRE_FALSE(bimap.hasKey("key again"));
    REQUIRE_FALSE(bimap.hasValue(10));
}
