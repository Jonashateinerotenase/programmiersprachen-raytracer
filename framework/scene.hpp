#ifndef SCENE_HPP
#define SCENE_HPP
#include "material.hpp"
#include <map>
#include <vector>
#include "shape.hpp"
//#include "material.hpp"
//#include "camera.hpp"
//#include "light.hpp"

struct Scene{

	Scene():
	filename{"defaultscene.ppm"},
//	camera{},
	amblight{},
	background{}
//	materials{},
//	lights{},
//	shapes{}
	{}

	Scene(
	std::string const& fname,
//	Camera cam,
    Color const& al,
    Color const& bg
//	std::map<std::string, std::shared_ptr<Material>> materials_map,
//	std::vector<std::shared_ptr<Light>> lights_vec,
//	std::vector<std::shared_ptr<Shape>> shapes):
    ):

	filename{fname},
	//camera{cam},
	amblight{al},
	background{bg}
	//materials{},
	//lights{},
	//shapes_ptr{shapes}
	{        
	//	materials.swap(materials_map);
    //    lights.swap(lights_vec)
    }


	std::string filename;
//	std::Camera camera;
//	std::map<std::string, Material> materials;	
//	std::map<std::string, std::shared_ptr<Material>> materials;	
//	std::vector<Shape> shapes_ptr;
//	std::vector<std::shared_ptr<Shape>> shapes_ptr;
//	std::std::vector<Light> lights;
//	std::std::vector<shared_ptr<Light>> lights;
	Color amblight;
	Color background;

};

#endif //#define SHAPE_HPP