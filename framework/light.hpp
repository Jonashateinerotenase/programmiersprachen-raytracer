#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

class Light{
public:
	Light();
	Light(std::string const& name, glm::vec3 const& pos, Color const& ld);
	friend std::ostream& operator<<(std::ostream& os, Light const& light);

//	glm::vec3 const& pos() const;
//	Color const& ld() const;
//	std::string const& name() const;
//	std::ostream& print(std::ostream& os) const;
//private:
	std::string name_;
	glm::vec3 pos_;
	Color ld_;


};

#endif