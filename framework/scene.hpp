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

	Scene():
	filename{"defaultscene.ppm"},
	xres_{},
	yres_{},
	camera{},
	amblight{},
	background{},
	materials{},
	lights{},
	shapes_ptr{}
	{std::cout <<"default scene erstellt!!!";}


	Scene(
	std::string const& fname,
	int const& xres,
	int const& yres,
	Camera cam,
    Color const& al,
    Color const& bg,
	std::map<std::string, std::shared_ptr<Material>> materials_map,
	std::vector<std::shared_ptr<Light>> lights_vec,
	std::vector<std::shared_ptr<Shape>> shapes):

	filename{fname},
	xres_{xres},
	yres_{yres},
	camera{cam},
	amblight{al},
	background{bg},
	materials{materials_map},
	lights{lights_vec},
	shapes_ptr{shapes}
	{ 
	std::cout <<"expert scene erstellt!!!";      
	//	materials.swap(materials_map);
    //    lights.swap(lights_vec)
    }


	std::string filename;
	int yres_, xres_;
	Camera camera;
	std::map<std::string, std::shared_ptr<Material>> materials;	
//	std::vector<Shape> shapes_ptr;
	std::vector<std::shared_ptr<Shape>> shapes_ptr;
//	std::std::vector<Light> lights;
	std::vector<std::shared_ptr<Light>> lights;
	Color amblight;
	Color background;

};

#endif //#define SHAPE_HPP