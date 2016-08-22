#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include "scene.hpp"

class Sdfloader {
 public:
	Sdfloader() = default;
	Sdfloader(std::string const& file);
	//~Sdfloader();

	//Scene load_scene(std::string file) const;
	Scene load_scene() const;

	std::string file_;

};

#endif