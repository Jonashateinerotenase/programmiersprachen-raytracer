#include "sphere.hpp"

Sphere::Sphere():
Shape(),
middle_{0.0f,0.0f,0.0f},
r_{1.0f}
{}

Sphere::Sphere(glm::vec3 const& middle, float r):
Shape(),
middle_{middle},
r_{r}
{}

Sphere::Sphere(glm::vec3 const& middle, float r, std::string const& name, Color const& farbe):
Shape(name, farbe),
middle_{middle},
r_{r}
{}

float Sphere::area() const {
  return 4*3/*.1415926536*/*(r_*r_);
}

float Sphere::volume() const {
  return ((4/3)*3/*.1415926536*/*(r_*r_*r_));
}

glm::vec3 const& Sphere::middle() const
{
  return middle_;
}

float const& Sphere::rad() const
{
  return r_;
}