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

Renderer::Renderer()
  :
  scene_{},
  colorbuffer_(scene_.xres_*scene_.yres_, Color{}),
  ppm_(scene_.xres_, scene_.yres_, "default.ppm")  
  {}

Renderer::Renderer(Scene scene)
  : /*width_{scene->xres_}
  , height_{scene->yres_}
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)*/
  scene_{scene},
  colorbuffer_(scene.xres_*scene.yres_, Color{}),
  ppm_(scene.xres_, scene.yres_, scene.filename)
  {}



//0.5 Alpha / 2 M_PI
void Renderer::render()
{

  float pic_ymax =2/scene_.xres_*scene_.yres_;
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



  const std::size_t checkersize = 20;

    float distance=(((45/360)*2*3.1415)*0.5)/2*3.1415;
    glm::vec3 mittelp{0.0,0.0,3.0*distance};
    float rad = 1;
    Sphere kugel{mittelp, rad};
    glm::vec3 onedirection{0.0,0.0,0.0};
    int height_=400;
    int width_=400;

    
  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      // 
      // p.color = raytrace(ray, depth);
      glm::vec3 origin{x,y,0.0};
      Ray camray{origin, onedirection};
      Pixel p(x,y);
      Hit hitteter=kugel.intersect(camray);
      if (hitteter.hit_ == true){
        p.color = Color(1.0,1.0,1.0);
      } else{
        p.color = Color(0.0,0.0,0.0);
      }   
      write(p);
    }
  }
  ppm_.save(scene_.filename);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (scene_.xres_*p.y + p.x);
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
