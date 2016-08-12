#include "camera.hpp"

Camera::Camera():
name_{"default camera"},
pos_{0.0f,0.0f,0.0f},
angle_{45.0}
{}

Camera::Camera(std::string const& name, glm::vec3 const& pos, float const& angle):
name_{name},
pos_{pos},
angle_{angle}
{}