#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape
{
public:
  Sphere();
  Sphere(glm::vec3 const& middle, float r);
  float area() const override;
  float volume() const override;
private:
  glm::vec3 middle_;
  float r_;

};

#endif // SPHERE_HPP
