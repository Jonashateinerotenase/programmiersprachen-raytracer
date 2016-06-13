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

float Box::area() const {
  return 0;
}

float Box::volume() const {
  return 0;
}

glm::vec3 const& Box::min() const
{
  return min_;
}

glm::vec3 const& Box::max() const
{
  return max_;
}
