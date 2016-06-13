#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "shape.hpp"
#include <glm/vec3.hpp>

TEST_CASE("box und sphere", "[box und sphere]")
{
  Box kiste;
  glm::vec3 testmin{0.0f,0.0f,0.0f};
  std::cout << kiste.min().x << std::endl;
  //REQUIRE(kiste.min().x == testmin.x);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

