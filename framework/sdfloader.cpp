//reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <glm/vec3.hpp>
#include "material.hpp"
#include "scene.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include <memory>
//#include "sdfloader.hpp"
//#include "camera.hpp"
#include "color.hpp"
//#include "renderer.hpp"

int main () {
  std::string line;
  std::ifstream myfile ("../../../scene/scene1.txt");
  std::map<std::string, std::shared_ptr<Material>> materials;
//  Scene scene1;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
     {
      //std::cout << line << '\n';
      std::stringstream ss;
  	  ss << line;
  	  Material mat;
  	  std::string keyword;
  
  	  ss>>keyword;
      if(keyword == "#"){break;}
//if(line.find("#"){break;})
      if(keyword == "define"){
     	    ss>>keyword;
          if(keyword == "material"){
            ss>>mat.name;
     	      ss>>mat.ka.r;
     	      ss>>mat.ka.g;
            ss>>mat.ka.b;
        
            ss>>mat.ks.r;
        	  ss>>mat.ks.g;
            ss>>mat.ks.b;
        	   
            ss>>mat.kd.r;
        	  ss>>mat.kd.g;
            ss>>mat.kd.b;
       	    ss>>mat.m;
  
            std::shared_ptr<Material> temp_ptr = std::make_shared<Material>(mat);
            materials.insert({mat.name, temp_ptr});
            //materials[mat.name]= mat;
            std::cout << mat;
          }
          if(keyword == "shape"){
            ss>>keyword;
            if(keyword == "box"){

            }
            if(keyword == "sphere"){

            }

          }
          if(keyword == "light"){

          }
          if(keyword == "camera"){

          }
      } 
    } 
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}
