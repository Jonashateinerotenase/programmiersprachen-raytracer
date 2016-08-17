#include <cmath>
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

Sphere::Sphere(glm::vec3 const& middle, float r, std::string const& name, Material const& mat):
Shape(name, mat),
middle_{middle},
r_{r}
{}



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

/*bool Sphere::intersect(Ray const& ray, float& distance) const {
  return glm::intersectRaySphere(ray.origin, ray.direction, middle_, r_*r_, distance);
}*/

/* virtual */ Hit Sphere::intersect(Ray const& ray) {
    Hit s_hit;

    s_hit.hit_ = glm::intersectRaySphere(
        ray.origin,
        glm::normalize(ray.direction),
        middle_, r_,
        s_hit.target_, s_hit.normal_
    );

    s_hit.distance_ = glm::distance(ray.origin, s_hit.target_);

    s_hit.sptr_ = this;

    return s_hit;
}