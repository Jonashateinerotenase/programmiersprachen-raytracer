// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include "scene.hpp"
#include <string>
#include <glm/glm.hpp>
#include "sphere.hpp"
//#include "sdfloader.cpp"
class Renderer
{
public:

  Renderer();
  Renderer(Scene scene);


  void render();
  Color shade(Ray const& ray, Hit const& hit, float depth);
  Color trace(Ray const& ray);
  void write(Pixel const& p);

  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }
 int depth=0;
private:

//  int width_;
//  int height_;
  std::vector<Color> colorbuffer_;
//  std::string filename_;
  PpmWriter ppm_;
  Scene scene_;

};

#endif // #ifndef BUW_RENDERER_HPP
