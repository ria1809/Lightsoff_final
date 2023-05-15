#include "gridScene.hpp"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>



TEST_CASE("Test BoxScene getBoxAtPosition function") {
    BoxScene boxScene;
    Vector2 pos(-1, -1);

    REQUIRE(boxScene.getBoxAtPosition(pos) == Vector2{-1, -1});

}








