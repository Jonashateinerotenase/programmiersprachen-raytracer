#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape{
public:
  Shape();
  virtual float area() const =0;
  virtual float volume() const =0;

};



#endif //#define SHAPE_HPP