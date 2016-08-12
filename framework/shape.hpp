#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

#include "hit.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "material.hpp"



class Shape{
public:
  virtual ~Shape() {}

  virtual Hit intersect(Ray const& ray) = 0;
  std::string const& getname() const;
  Material const& getmaterial() const;
  virtual std::ostream& print(std::ostream& os) const;

protected:
  Shape();
  Shape(std::string const& name, Material const& mat_);

private:
  std::string name_;
  Material mat_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);



#endif //#define SHAPE_HPP
