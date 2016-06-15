#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <string>
class Shape{
public:
  Shape();
  Shape(std::string const& name, Color const& color);
  virtual float area() const =0;
  virtual float volume() const =0;
  std::string getname() const;
  Color const& getcolor() const;
  virtual std::ostream& print(std::ostream& os) const;
 private:
  std::string name_;
  Color color_;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

//-> nur auf linux geht hier in windows nich deswegen im lintpool fertig machen du fgt


#endif //#define SHAPE_HPP
