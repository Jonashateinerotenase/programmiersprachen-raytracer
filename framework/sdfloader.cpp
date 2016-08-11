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
#include "shape.hpp"
#include <memory>
//#include "sdfloader.hpp"
//#include "camera.hpp"
#include "color.hpp"
//#include "renderer.hpp"

int main () {
  std::string line;
  std::ifstream myfile ("../../../scene/scene1.txt");
  std::map<std::string, std::shared_ptr<Material>> materials;
  std::map<std::string, std::shared_ptr<Shape>> shapes;
//  Scene scene1;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
     {
      //std::cout << line << '\n';
      std::stringstream ss;
  	  ss << line;
  	 
  	  std::string keyword;
  
  	  ss>>keyword;
      if(keyword == "#"){continue;}
//if(line.find("#"){break;})
      if(keyword == "define"){
     	    ss>>keyword;
          if(keyword == "material"){
            Material mat;
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
              glm::vec3 testmid{1.0f,2.0f,3.0f};
              float testr = 1;
              Material testmat;
              std::string testname ="hi";
              Sphere sph{testmid, testr, testname, testmat};
              //float x,y,z,r;
              Material mat;
              ss>>sph.name_;
              ss>>sph.middle_.x;
              ss>>sph.middle_.y;
              ss>>sph.middle_.z;
              ss>>sph.r_;
              std::string mat_name;
              ss>>mat_name;              
              std::cout <<mat_name;
              //ss>>sph.name_;
              //ss>>sph.middle_.x;
              //ss>>sph.middle_.y;
              //ss>>sph.middle_.z;
              //ss>>sph.r_;

              //sph.mat_=*materials(mat_name);
              //std::shared_ptr<Shape> temp_ptr = std::make_shared<Shape>(sph);
              //shapes.insert({sph.name, temp_ptr});
            // std::cout << sph;
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
