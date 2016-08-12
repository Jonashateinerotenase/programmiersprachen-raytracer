#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape
{
public:
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name,
  	Material const& mat);
  
  bool intersect(Ray const& ray, float& t) const override;
  glm::vec3 const& min() const;
  glm::vec3 const& max() const;
  std::ostream& print(std::ostream& os) const override;

private:
  glm::vec3 min_;
  glm::vec3 max_;
};

#endif // BOX_HPP
