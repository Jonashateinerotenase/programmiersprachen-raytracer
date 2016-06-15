#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape
{
public:
  Sphere();
  Sphere(glm::vec3 const& middle, float r);
  Sphere(glm::vec3 const& middle, float r, std::string const& name, Color const& farbe);
  float area() const override;
  float volume() const override;
  glm::vec3 const& middle() const;
  float const& rad() const;
  std::ostream& print(std::ostream& os) const override;
  //bool intersect const&(glm::vec3 const& ori, glm::vec3 const& dir,....);
private:
  glm::vec3 middle_;
  float r_;

};

#endif // SPHERE_HPP
