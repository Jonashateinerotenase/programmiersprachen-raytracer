#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include <string>
struct Ray
{
	Ray():
	origin{0.0,0.0,0.0},
	direction{0.0,0.0,0.0},
	inv_direction{-0.0,-0.0,-0.0}
	{}


	Ray(glm::vec3 const& ori, glm::vec3 const& dir):
	origin{ori},
	direction{dir},
	inv_direction{1.0/dir.x,1.0/dir.y,1.0/dir.z}
	{}


	friend std::ostream& operator<<(std::ostream& os, Ray const& ray){

     	os << "Ray: " << std::endl << "Origin: ("
        << ray.origin.x << ","
        << ray.origin.y << ","
        << ray.origin.z << ") \n"
        << "Direction: ("
        << ray.direction.x << ","
        << ray.direction.y << ","
        << ray.direction.z << ") \n";
	}

	glm::vec3 origin;
	glm::vec3 direction;
	glm::vec3 inv_direction;

};

#endif