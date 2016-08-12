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
Shape(name, mat),
min_{min},
max_{max}
{}



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

Hit Box::intersect(Ray const& ray) {

  // r.dir is unit direction vector of ray
  // lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
  // r.org is origin of ray
  float t1 = (min_.x - ray.origin.x)*ray.inv_direction.x;
  float t2 = (max_.x - ray.origin.x)*ray.inv_direction.x;
  float t3 = (min_.y - ray.origin.y)*ray.inv_direction.y;
  float t4 = (max_.y - ray.origin.y)*ray.inv_direction.y;
  float t5 = (min_.z - ray.origin.z)*ray.inv_direction.z;
  float t6 = (max_.z - ray.origin.z)*ray.inv_direction.z;

  float tmin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
  float tmax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

  // if tmax < 0, ray (line) is intersecting AABB, but whole AABB is behing us
  Hit b_hit;


  /*if (tmax < 0)
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
  return true;*/

    if (tmax > std::max(0.0f, tmin)) {
        b_hit.distance_ = sqrt(tmin * tmin *
                             (ray.direction.x * ray.direction.x +
                              ray.direction.y * ray.direction.y +
                              ray.direction.z * ray.direction.z)
                            );

        b_hit.target_ = glm::vec3{
            tmin * ray.direction.x,
            tmin * ray.direction.y,
            tmin * ray.direction.z
        };

        glm::vec3 normal{std::numeric_limits<float>::infinity(),std::numeric_limits<float>::infinity(),std::numeric_limits<float>::infinity()};
//        float bias = 0.0009f;
        //getting the normal vec on the side of the intersection
        if (abs(b_hit.target_.x - max_.x) /*< bias*/) {
            normal = glm::vec3{1.0, 0.0, 0.0};
        } else if (abs(b_hit.target_.x - min_.x) /*< bias*/) {
            normal = glm::vec3{-1.0, 0.0, 0.0};
        } else if (abs(b_hit.target_.y - max_.y) /*< bias*/) {
            normal = glm::vec3{0.0, 1.0, 0.0};
        } else if (abs(b_hit.target_.y - min_.y) /*< bias*/) {
            normal = glm::vec3{0.0, -1.0, 0.0};
        } else if (abs(b_hit.target_.z - max_.z) /*< bias*/) {
            normal = glm::vec3{0.0, 0.0, 1.0};
        } else if (abs(b_hit.target_.z - min_.z) /*< bias*/) {
            normal = glm::vec3{0.0, 0.0, -1.0};
        }

        // std::cout << "INTERSECT IS GOING ON: \n";
        // std::cout << b_hit.intersection_.x << std::endl;
        // std::cout << max_.x << std::endl;
        // std::cout << min_.x << std::endl;
        // std::cout << b_hit.intersection_.y << std::endl;
        // std::cout << max_.y << std::endl;
        // std::cout << min_.y << std::endl;
        // std::cout << b_hit.intersection_.z << std::endl;
        // std::cout << max_.z << std::endl;
        // std::cout << min_.z << std::endl;

        b_hit.normal_ = normal;
        b_hit.sptr_ = std::make_shared<Box>(*this);
        b_hit.hit_ = true;
    }

    return b_hit;
}
