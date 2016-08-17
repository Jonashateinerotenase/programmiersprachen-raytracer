#include "camera.hpp"

Camera::Camera():
name_{"default camera"},
pos_{0.0f,0.0f,0.0f},
angle_{45.0}
{}

Camera::Camera(std::string const& n, glm::vec3 const& p, float a):
name_{n},
pos_{p},
angle_{a}
{}

std::string const& Camera::name() const{
  return name_;
} 
glm::vec3 const& Camera::pos() const{
  return pos_;
} 
float const& Camera::angle() const{
  return angle_;
}

Ray const Camera::castray(glm::vec3 const& dir) const {
	Ray ray{pos_, pos_+dir};
	return ray;
}



std::ostream& operator<<(std::ostream& os, Camera const& c)
  {
    os << "Camera: \n"
       << "Name: " << c.name_ << "\n"
       << "Pos: (" << c.pos_.x << "," << c.pos_.y << "," << c.pos_.z << ")\n"
       << "Winkel: "<< c.angle_ << "\n\n";
    return os;
  }
