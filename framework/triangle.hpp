#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>


class Triangle : public Shape
{
public:
  Triangle();
  Triangle(glm::vec3 const& ecke1, glm::vec3 const& ecke2, glm::vec3 const& ecke3);
  Triangle(glm::vec3 const& ecke1, glm::vec3 const& ecke2, glm::vec3 const& ecke3, std::string const& name, Material const& mat);
  
  Hit intersect(Ray const& ray) override;
  std::ostream& print(std::ostream& os) const override;

private:
  glm::vec3 ecke1_;
  glm::vec3 ecke2_;
  glm::vec3 ecke3_;
};

#endif // TRIANGLE_HPP