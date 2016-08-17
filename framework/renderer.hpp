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

class Renderer
{
public:
  Renderer(std::shared_ptr scene);

  void render();
  void write(Pixel const& p);

  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }

private:
  
//  int width_;
//  int height_;
  std::vector<Color> colorbuffer_;
//  std::string filename_;
  PpmWriter ppm_;
  std::shared_ptr scene_;
};

#endif // #ifndef BUW_RENDERER_HPP
