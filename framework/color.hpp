// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Color
// -----------------------------------------------------------------------------

#ifndef BUW_COLOR_HPP
#define BUW_COLOR_HPP

#include <iostream>

struct Color
{
  Color(float red, float green, float blue) : r(red), g(green), b(blue) {}

  Color() : r(0.0), g(0.0), b(0.0) {}

  float r;
  float g;
  float b;

  friend std::ostream& operator<<(std::ostream& os, Color const& c)
  {
    os << "(" << c.r << "," << c.g << "," << c.b << ")\n";
    return os;
  }

  Color& operator+=(Color const& other)
  {
    r += other.r;
    g += other.g;
    b += other.b;
    return *this;
  }

  Color& operator-=(Color const& other)
  {
    r -= other.r;
    g -= other.g;
    b -= other.b;
    return *this;
  }

  friend Color operator+(Color const& a, Color const& b)
  {
    auto tmp(a);
    tmp += b;
    return tmp;
  }

  friend Color operator-(Color const& a, Color const& b)
  {
    auto tmp(a);
    tmp -= b;
    return tmp;
  }

  friend Color operator*(Color const& a, Color const& b)
  {
    auto tmp(a);
    tmp.r = a.r * b.r;
    tmp.g = a.g * b.g;
    tmp.b = a.b * b.b;

    return tmp;
  }

  friend Color operator*(Color const& a, float b)
  {
    auto tmp(a);
    tmp.r = a.r * b;
    tmp.g = a.g * b;
    tmp.b = a.b * b;

    return tmp;
  }
  friend Color operator*(double b, Color const& a)
  {
    auto tmp(a);
    tmp.r = a.r * b;
    tmp.g = a.g * b;
    tmp.b = a.b * b;

    return tmp;
  }

      friend bool operator==(Color const& a, Color const& b)
  {
    if(a.r == b.r && a.g == b.g && a.b == b.b){

      return true;
    }
    else{
      return false;
    }
  }

    friend bool operator!=(Color const& a, Color const& b)
  {
    if(a == b) return false;
    else return true;
  }
};

#endif //#define BUW_COLOR_HPP
