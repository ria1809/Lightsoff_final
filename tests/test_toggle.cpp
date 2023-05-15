
#include "threepp/threepp.hpp"
#include "Box.hpp"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Toggle checking") {

    // Create a white box
    Box box;
    auto material = MeshBasicMaterial::create();
    auto geometry = BoxGeometry::create(2, 2, 2);
    box.mesh = Mesh::create(geometry, material);

    // Toggle the box color to yellow
    box.toggle();
    REQUIRE(dynamic_cast<threepp::MeshBasicMaterial*>(box.mesh->material())->color == Color::yellow);

    // Toggle the box back to white
    box.toggle();
    REQUIRE(dynamic_cast<threepp::MeshBasicMaterial*>(box.mesh->material())->color == Color::white);

}
