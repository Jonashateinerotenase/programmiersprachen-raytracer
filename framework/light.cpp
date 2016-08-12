#include "light.hpp"

Light::Light():
	name_{"name"},
	pos_{},
	ld_{}
	{}

Light::Light(std::string const& name, glm::vec3 const& pos, Color const& ld):
	name_{name},
	pos_{pos},
	ld_{ld}
	{}

std::ostream& operator<<(std::ostream& os, Light const& light)
  {
    os << "Light: \n"
       << "Position: (" 
       << light.pos_.x 
       << "," 
       << light.pos_.y 
       << "," 
       << light.pos_.z 
       << ")\n"
       << "Farbe: "
       << light.ld_ 
       << "\n\n";
    return os;
  }