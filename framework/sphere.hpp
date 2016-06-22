#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include "ray.hpp"


class Sphere : public Shape
{
public:
  Sphere();
  Sphere(glm::vec3 const& middle, float r);
  Sphere(glm::vec3 const& middle, float r, std::string const& name, Color const& farbe);
  float area() const override;
  float volume() const override;
  glm::vec3 const& middle() const;
  float rad() const;
  std::ostream& print(std::ostream& os) const override;
  bool intersect(Ray const& ray, float& distance);
private:
  glm::vec3 middle_;
  float r_;

};

#endif // SPHERE_HPP
