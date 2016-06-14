#include "shape.hpp"

Shape::Shape():
	name_{"xxx"},
	color_{0.0f,0.0f,0.0f}
{}

Shape::Shape(std::string const& name, Color const& farbe):
  name_{name},
  color_{farbe}
{}

std::string Shape::getname() const{
	return name_;
}
Color const& Shape::getcolor() const{
	return color_;
}
