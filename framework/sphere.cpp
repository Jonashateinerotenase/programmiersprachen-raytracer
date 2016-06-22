#include "sphere.hpp"
#include <cmath>


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

Sphere::Sphere(glm::vec3 const& middle, float r, std::string const& name, Material const& mat):
Shape(name, mat),
middle_{middle},
r_{r}
{}

float Sphere::area() const {
  return 4.0f * M_PI * r_*r_;
}

float Sphere::volume() const {
  return 4.0f/3.0f * M_PI * r_*r_*r_;
}

glm::vec3 const& Sphere::middle() const
{
  return middle_;
}

float Sphere::rad() const
{
  return r_;
}

std::ostream& Sphere::print(std::ostream& os) const{
	Shape::print(os);
        os <<"Radius: "<< r_ << " \n"<< "mitte: ("<<middle_.x
	<< ", "<<middle_.y
  	<< ", "<<middle_.z
	<< ")\n";
}

bool Sphere::intersect(Ray const& ray, float& distance) {
return glm::intersectRaySphere(ray.origin, ray.direction, middle_, r_*r_, distance);
}
