#include "camera.hpp"

Camera::Camera():
name_{"default camera"},
pos_{0.0f,0.0f,0.0f},
angle_{45.0}
{}

Camera::Camera(std::string const& name, glm::vec3 const& pos, float angle):
name_{name},
pos_{pos},
angle_{angle}
{}

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