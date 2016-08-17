#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP
#include "scene.hpp"

class Sdfloader{
Sdfloader();
Sdfloader(std::string file);
~Sdfloader();

Scene load_scene(std::string file) const;

private:
	std::string file_;

};
#endif