#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <iostream>

TEST_CASE("box default test", "[box]")
{
  Box kiste;
  glm::vec3 testmin{0.0f,0.0f,0.0f};
  //std::cout << kiste.min().x << std::endl;
  REQUIRE(kiste.min().x == testmin.x);
  REQUIRE(kiste.min().y == testmin.y);
  REQUIRE(kiste.min().z == testmin.z);
  REQUIRE(1==1);

  Sphere kugel;
  glm::vec3 testmin2{0.0f,0.0f,0.0f};
  //std::cout << kugel.middle().x << std::endl;
  REQUIRE(kugel.middle().x == testmin2.x);
  REQUIRE(kugel.middle().y == testmin2.y);
  REQUIRE(kugel.middle().z == testmin2.z);
  REQUIRE(1==1);
}

TEST_CASE("area der box", "[box]")
{
  
  glm::vec3 testmin{0.0f,0.0f,0.0f};
  glm::vec3 testmax{1.0f,1.0f,1.0f};
  Box kiste{testmin,testmax};
  //std::cout << kiste.min().x << std::endl;
  REQUIRE(kiste.area() == 6);
  REQUIRE(kiste.volume() == 1);

 glm::vec3 testmink{0.0f,0.0f,0.0f};
 float rad = 1.0f;
 Sphere Kuchel{testmink,rad};
 REQUIRE(Kuchel.area()==12);
 //REQUIRE(Kuchel.volume()==Approx(4));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

