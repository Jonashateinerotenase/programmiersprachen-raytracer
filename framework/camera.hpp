#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <String>
#include <glm/vec3.hpp>

class Camera
{
public:
	Camera();
	Camera(std::string const& name, glm::vec3 const& pos, float const& angle);

private:

	std::string name_;
	glm::vec3 pos_;
	float angle_;
}
#endif