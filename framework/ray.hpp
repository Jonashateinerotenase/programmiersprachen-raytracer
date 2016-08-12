#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include <string>
struct Ray
{
	Ray();
	Ray(glm::vec3 const& ori, glm::vec3 const& dir):
	origin{ori},
	direction{dir}
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

};
