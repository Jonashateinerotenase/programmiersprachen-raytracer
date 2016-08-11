#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
class Sphere : public Shape
{
public:
  Sphere();
  Sphere(glm::vec3 const& middle, float r);
  Sphere(glm::vec3 const& middle, float r, std::string const& name, Material const& mat);
  ~Sphere();
  float area() const override;
  float volume() const override;
  glm::vec3 const& middle() const;
  float rad() const;
  std::ostream& print(std::ostream& os) const override;
  bool intersect(Ray const& ray, float& distance) override;
//private:
  glm::vec3 middle_;
  float r_;

};

#endif // SPHERE_HPP
