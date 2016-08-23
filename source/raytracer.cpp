#include <thread>
#include <renderer.hpp>
#include <fensterchen.hpp>

//#include "scene.hpp"
#include "sdfloader.cpp"

int main(int argc, char* argv[])
{
//  std::string scenename = argv[1];

  if (argc !=2){
    std::cout << "Usage:raytracer filename.sdf \n";
//    std::cout << argv[0] << "\n";
    return 1;




  };

  Scene scene = load_sdf_file(argv[1]);




  
//load_scene();
//Scene scene = load_scene();
//render(scene);

  /*Sdfloader 
  load_scene(scenname);*/

  /*unsigned w = 400;
  unsigned h = 400;
  std::string file ="hiereinnamenstest.ppm";
  Renderer ersterversuch(w,h,file);*/
//  ersterversuch.render();

  /*unsigned const width = 600;
  unsigned const height = 600;
  std::string const filename = "./checkerboard.ppm";

  Renderer app(width, height, filename);

  //std::thread thr([&app]() { app.render(); });

  Window win(glm::ivec2(width,height));

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }

    glDrawPixels( width, height, GL_RGB, GL_FLOAT
                , app.colorbuffer().data());

    win.update();
  }

  //thr.join();*/

  return 0;
}
