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
