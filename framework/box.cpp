#include "box.hpp"

Box::Box():
Shape(),
min_{0.0f,0.0f,0.0f},
max_{0.0f,0.0f,0.0f}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
Shape(),
min_{min},
max_{max}
{}
Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& farbe):
Shape {name, farbe},
min_{min},
max_{max}
{}



float Box::area() const {
	float a=max_.x-min_.x;
	float b=max_.y-min_.y;
	float c=max_.z-min_.z;
  return 2*a*b+2*a*c+2*b*c;
}

float Box::volume() const {
	float a=max_.x-min_.x;
	float b=max_.y-min_.y;
	float c=max_.z-min_.z;
  return a*b*c;
}

glm::vec3 const& Box::min() const
{
  return min_;
}

glm::vec3 const& Box::max() const
{
  return max_;
}

std::ostream& Box::print(std::ostream& os) const{
	Shape::print(os);
        os << "min: ("<<min_.x
	<< ", "<<min_.y
  	<< ", "<<min_.z
	<< ") max: ("<<max_.x
	<< ", "<<max_.y
	<< ", "<<max_.z << ")\n";
}
