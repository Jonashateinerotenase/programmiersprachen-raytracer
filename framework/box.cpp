#include "box.hpp"

Box::Box():
Shape::Shape(),
    min_{0.0f,0.0f,0.0f},
    max_{0.0f,0.0f,0.0f}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
Shape::Shape(),
    min_{min},
    max_{max}
  
{}
