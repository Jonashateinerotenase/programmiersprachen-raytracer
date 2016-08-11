#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"
#include "material.hpp"
class Shape{
public:
  Shape();
  Shape(std::string const& name, Material const& mat_);

  virtual float area() const =0;
  virtual float volume() const =0;
  virtual bool intersect(Ray const& ray, float& t) =0;
  std::string const& getname() const;
  Material const& getmaterial() const;
  virtual std::ostream& print(std::ostream& os) const;
  std::string name_;
  Material mat_;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);



#endif //#define SHAPE_HPP
