#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
/*
TEST_CASE("intersectRaySphere","[intersect]")
{
// Ray
glm::vec3 ray_origin{0.0,0.0,0.0};
// ray direction has to be normalized !
// you can use :
//
v = glm::normalize(some_vector)
glm::vec3 ray_direction{0.0,0.0,1.0};
// Sphere
glm::vec3 sphere_center{0.0,0.0,5.0};
float sphere_radius{1.0};
float distance{0.0};
auto result = glm::intersectRaySphere(
ray_origin,ray_direction,
sphere_center,sphere_radius,distance);
REQUIRE(distance == Approx(4.0f));
}*/





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
 REQUIRE(Kuchel.area()== Approx(12.56637f));
 REQUIRE(Kuchel.volume()==Approx(4.18879f));
}

TEST_CASE("print", "[box]")
{
  Box b{glm::vec3{-1.0f}, glm::vec3{1.0f}};
  std::stringstream ss;
  // schreibe ausgabe in den stringstream ss
  b.print(ss);
  
  b.print(std::cout);
}

TEST_CASE("printsphere", "[sphere]")
{
  Sphere s{};
  glm::vec3 fgt{1.0f,1.0f,1.0f};
  float g= 2.0f;
  std::string hs = "Fabienne";
  Color farbi{1.0f,1.0f,1.0f};
  Sphere z{fgt,g,hs,farbi};
  std::stringstream ss;
  // schreibe ausgabe in den stringstream ss
  s.print(ss);
  
  s.print(std::cout);
  // schreibe ausgabe in den stringstream ss
  z.print(ss);
  
  z.print(std::cout);


  glm::vec3 fgt2{1.0f,1.0f,1.0f};
  glm::vec3 fgt3{1.0f,1.0f,1.0f};
  std::string hs2 = "Herodes";
  Color farbi2{0.198f,0.146f,0.082fgit};
  Box h{fgt2,fgt3,hs2,farbi2};
  h.print(ss);
  h.print(std::cout);

}

//Sphere(glm::vec3 const& middle, float r, std::string const& name, Color const& farbe);

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

