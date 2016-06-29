#include "box.hpp"
#include <algorithm>

Box::Box():
Shape(),
min_{0.0f,0.0f,0.0f},
max_{0.0f,0.0f,0.0f}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
Shape(),
min_{min},
max_{max}
{}
Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Material const& mat):
Shape {name, mat},
min_{min},
max_{max}
{}



float Box::area() const {
	float a=max_.x-min_.x;
	float b=max_.y-min_.y;
	float c=max_.z-min_.z;
  return 2*a*b+2*a*c+2*b*c;
}

float Box::volume() const {
	float a=max_.x-min_.x;
	float b=max_.y-min_.y;
	float c=max_.z-min_.z;
  return a*b*c;
}

glm::vec3 const& Box::min() const
{
  return min_;
}

glm::vec3 const& Box::max() const
{
  return max_;
}

std::ostream& Box::print(std::ostream& os) const{
	Shape::print(os);
        os << "min: ("<<min_.x
	<< ", "<<min_.y
  	<< ", "<<min_.z
	<< ") max: ("<<max_.x
	<< ", "<<max_.y
	<< ", "<<max_.z << ")\n";
}

bool Box::intersect(Ray const& ray, float& t) {
glm::vec3 dirfrac{1.0f,1.0f,1.0f};
// r.dir is unit direction vector of ray
dirfrac.x = 1.0f / ray.direction.x;
dirfrac.y = 1.0f / ray.direction.y;
dirfrac.z = 1.0f / ray.direction.z;
// lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
// r.org is origin of ray
float t1 = (min_.x - ray.origin.x)*dirfrac.x;
float t2 = (max_.x - ray.origin.x)*dirfrac.x;
float t3 = (min_.y - ray.origin.y)*dirfrac.y;
float t4 = (max_.y - ray.origin.y)*dirfrac.y;
float t5 = (min_.z - ray.origin.z)*dirfrac.z;
float t6 = (max_.z - ray.origin.z)*dirfrac.z;

float tmin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
float tmax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

// if tmax < 0, ray (line) is intersecting AABB, but whole AABB is behing us
if (tmax < 0)
{
    t = tmax;
    return false;
}

// if tmin > tmax, ray doesn't intersect AABB
if (tmin > tmax)
{
    t = tmax;
    return false;
}

t = tmin;
return true;

}
