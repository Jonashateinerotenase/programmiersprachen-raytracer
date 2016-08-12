#include "shape.hpp"

Shape::Shape():
	name_{"xxx"},
	mat_{}
{}

Shape::Shape(std::string const& name, Material const& mati):
  	name_{name},
  	mat_{mati}
{}

std::string const& Shape::getname() const{
	return name_;
}
Material const& Shape::getmaterial() const{
	return mat_;
}


std::ostream& Shape::print(std::ostream& os) const{
	os << "name: " << name_<< "\n" << "material: " << mat_;
 	return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}
