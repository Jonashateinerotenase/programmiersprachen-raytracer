#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <catch.hpp>

#include "box.hpp"
#include "sphere.hpp"


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


TEST_CASE("print", "[box]")
{
  Box b{glm::vec3{-1.0f}, glm::vec3{1.0f}};
  std::stringstream ss;
  // schreibe ausgabe in den stringstream ss
  b.print(ss);
  
  b.print(std::cout);
}

/*TEST_CASE("boxintersect", "[box]")
{
  Box b{glm::vec3{-0.0f}, glm::vec3{1.0f}};
  glm::vec3 orimori{-1.0f,-1.0f,-1.0f};
  glm::vec3 dirimiri{1.0f,1.0f,1.0f};

  glm::vec3 orimori2{2.0f,2.0f,2.0f};
  glm::vec3 dirimiri2{-1.0f,-1.0f,-1.0f};

  glm::vec3 orimori3{-5.5f,-153.5f,98.5f};
  glm::vec3 dirimiri3 = glm::vec3(0.5f,0.5f,0.5f) - orimori3;

  glm::vec3 orimori4{1.1f,1.1f,1.1f};
  glm::vec3 dirimiri4{2.0f,2.0f,2.0f};


  Ray triffter{orimori,dirimiri};
  Ray triffter2{orimori2,dirimiri2};
  Ray triffter3{orimori3,dirimiri3};
   Ray triffter4{orimori4,dirimiri4};
  float x = 1.0f;

  REQUIRE(b.intersect(triffter, x));
  REQUIRE(b.intersect(triffter2, x));
  REQUIRE(b.intersect(triffter3, x));
  REQUIRE(!b.intersect(triffter4, x));
}*/

TEST_CASE("printsphere", "[sphere]")
{
  Sphere s{};
  glm::vec3 mid{1.0f,1.0f,1.0f};
  float r= 2.0f;
  std::string name = "Fabienne";
  Material mat;
  Sphere z{mid,r,name,mat};
  std::stringstream ss;
  // schreibe ausgabe in den stringstream ss
  s.print(ss);
  
  s.print(std::cout);
  // schreibe ausgabe in den stringstream ss
  /*z.print(ss);
  
  z.print(std::cout);*/


  /*glm::vec3 fgt2{1.0f,1.0f,1.0f};
  glm::vec3 fgt3{1.0f,1.0f,1.0f};
  std::string hs2 = "Herodes";
  Color farbi2{0.198f,0.146f,0.082f};
  Box h{fgt2,fgt3,hs2,farbi2};
  h.print(ss);
  h.print(std::cout);*/

}

//Sphere(glm::vec3 const& middle, float r, std::string const& name, Color const& farbe);

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

