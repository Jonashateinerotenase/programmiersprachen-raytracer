#ifndef SCENE_HPP
#define SCENE_HPP
#include "material.hpp"
#include <map>
#include <vector>
#include "shape.hpp"
#include "material.hpp"
//#include "camera.hpp"
//#include "light.hpp"

struct Scene{

	Scene():
	fliename{"defaultscene.ppm"},
	//camera{},
	amblight{},
	background{},
	materials{},
	//lights{},
	shapes{}
	{}

	std::string filename;
//	std::Camera camera;
	std::map<std::string, Material> materials;
	std::vector<Shape> shapes;
	//std::std::vector<Light> lights;
	Color amblight;
	Color background;

}

#endif //#define SHAPE_HPP