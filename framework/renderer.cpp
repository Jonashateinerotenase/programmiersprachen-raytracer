// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include <math.h>
#include "renderer.hpp"
//#include "scene.hpp"

/*Renderer::Renderer()
  :
  scene_{}
  {}
*/
Renderer::Renderer(std::shared_ptr<Scene> scene)
  : /*width_{scene->xres_}
  , height_{scene->yres_}
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)*/
  scene_{scene},
  colorbuffer_(scene->xres_*scene->yres_, Color{}),
  ppm_(scene->xres_, scene->yres_, scene->filename)
  {}



//0.5 Alpha / 2 M_PI
void Renderer::render()
{

  float pic_ymax =2/scene_->xres_*scene_->yres_;
//float pic_z =1/(0.5*1.0/*alpha*/);//alpha von der camera aus der scene "angle"
//glm::vec3 p1{-1.0,};
//  height_=(2/scene.width_);
//prinzipieller aufbau
  /*
while (int x = 0; x < width; ++x)
{
  for (int y = 0; y < height; ++y)
  {
    Pixel p(x,y,pic_z);
  }
}*/



  /*const std::size_t checkersize = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      // 
      // p.color = raytrace(ray, depth);

      Pixel p(x,y);
      if ( ((x/checkersize)%2) != ((y/checkersize)%2)) {
        p.color = Color(1,1,1);
      } else {
        p.color = Color(0.0, 0.0, 0.0);
      }

      write(p);
    }
  }*/
  ppm_.save(scene_->filename);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (scene_->xres_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}
