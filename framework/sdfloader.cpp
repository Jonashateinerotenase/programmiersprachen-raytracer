#include "sdfloader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <glm/vec3.hpp>

#include "color.hpp"
#include "material.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "camera.hpp"
//#include "scene.hpp"

void load_scene() {
  std::string line;
  std::ifstream myfile ("../../../scene/scene1.txt");
  std::map<std::string, std::shared_ptr<Material>> materials;
  std::vector<std::shared_ptr<Shape>> shapes;
  std::vector<std::shared_ptr<Light>> lights;
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
              std::string name;
              std::string mat_namebox;
              float minx,miny,minz,maxx,maxy,maxz;
              
              ss>>minx;
              ss>>miny;
              ss>>minz;
              ss>>maxx;
              ss>>maxy;
              ss>>maxz;

              glm::vec3 min{minx,miny,minz};
              glm::vec3 max{maxx,maxy,maxz};
              ss>>name;
              ss>>mat_namebox; 
              //std::string mat_namebox;
              
              std::shared_ptr<Shape> temp_ptr = std::make_shared<Box>
              (
                Box{min,max,name,*materials[mat_namebox]}
              );
                std::cout << *temp_ptr;
                shapes.push_back(temp_ptr);

            }
            else if(keyword == "sphere"){
              std::string name;
              float x,y,z,r;
              ss>>name;
              ss>>x;
              ss>>y;
              ss>>z;
              glm::vec3 middle{x,y,z};
              ss>>r;
              std::string mat_name;
              ss>>mat_name;             
            /*std::cout <<mat_name;
              ss>>sph.name_;
              ss>>sph.middle_.x;
              ss>>sph.middle_.y;
              ss>>sph.middle_.z;
              ss>>sph.r_;
              ss>>sph.mat_;
              std::cout << sph;sph.mat_=*materials(mat_name);*/
              std::shared_ptr<Shape> temp_ptr = std::make_shared<Sphere>
              (
                Sphere{middle,r,name,*materials[mat_name]}
              );
                std::cout << *temp_ptr;              
                shapes.push_back(temp_ptr);
              // std::cout << sph;
            }

            }
          if(keyword == "light"){
              std::string name;
              std::string mat_namelight;
              float posx, posy, posz, ldr, ldg, ldb;
              ss>>name;
              ss>>posx;
              ss>>posy;
              ss>>posz;
              glm::vec3 pos{posx,posy,posz};
              ss>>ldr;
              ss>>ldg;
              ss>>ldb;
              Color ld{ldr,ldg,ldb};
              
              std::shared_ptr<Light> temp_ptr = std::make_shared<Light>
              (
                Light{name, pos, ld}
              );
                std::cout << *temp_ptr;
              //geht erst wenn der operator da ist!
              std::cout << "das scheiss licht geht nich junge";
                lights.push_back(temp_ptr);


          }
          
          if(keyword == "camera"){
              std::string name;
              float angle, posx, posy, posz;
              ss>>name;
              ss>>posx;
              ss>>posy;
              ss>>posz;
              glm::vec3 pos{posx,posy,posz};
              ss>>angle;


              std::shared_ptr<Camera> cam_ptr = std::make_shared<Camera>
              (
                Camera{name,pos,angle};
              );
                std::cout << *cam_ptr;              
                s
              Camera cam{name,pos,angle};              
              
          }
        } 
      } 
      myfile.close();
    }

  else std::cout << "Unable to open file"; 
}
