#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
struct Ray
{
Ray();
Ray(glm::vec3 const& ori, glm::vec3 const& dir):
origin{ori},
direction{dir}
{}
glm::vec3 origin;
glm::vec3 direction;
};


