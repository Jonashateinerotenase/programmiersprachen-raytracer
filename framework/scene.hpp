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
	int yres_, xres_;
	Camera camera;
	std::map<std::string, std::shared_ptr<Material>> materials;	
//	std::vector<Shape> shapes_ptr;
	std::vector<std::shared_ptr<Shape>> shapes_ptr;
//	std::std::vector<Light> lights;
	std::vector<Light> lights;
	Color amblight;
	Color background;

};

#endif //#define SHAPE_HPP