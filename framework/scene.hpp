#ifndef SCENE_HPP
#define SCENE_HPP
#include "material.hpp"
#include <map>
#include <vector>
#include "shape.hpp"
#include <memory>
#include <vector>
#include "camera.hpp"
#include "light.hpp"

struct Scene{

	std::string filename;
	float yres_ = 0.0;
	float xres_ = 0.0;
	Camera camera;
	std::map<std::string,Material> materials;	
	std::vector<std::shared_ptr<Shape>> shapes_ptr;
	std::vector<Light> lights;
	Color amblight;
	Color background;

};

#endif //#define SHAPE_HPP