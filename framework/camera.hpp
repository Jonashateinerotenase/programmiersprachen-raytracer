#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <string>
#include <glm/vec3.hpp>
#include <iostream>
#include "ray.hpp"

class Camera
{
public:
	Camera();
	Camera(std::string const& name, glm::vec3 const& pos, float angle);

	std::string const& name() const;
	glm::vec3 const& pos() const; 
	float const& angle() const;

	Ray const castray(glm::vec3 const& dir) const;


    friend std::ostream& operator<<(std::ostream& os, Camera const& c);



private:
	std::string name_;
	glm::vec3 pos_;
	float angle_;
};
#endif