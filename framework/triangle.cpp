#include "triangle.hpp"
#include <algorithm>

Triangle::Triangle():
Shape(),
ecke1_{1.0f,0.0f,-2.0f},
ecke2_{-1.0f,0.0f,-2.0f},
ecke3_{0.0f,1.0f,-2.0f}
{}

Triangle::Triangle(glm::vec3 const& ecke1, glm::vec3 const& ecke2, glm::vec3 const& ecke3):
Shape(),
ecke1_{ecke1.x,ecke1.y,ecke1.z},
ecke2_{ecke2.x,ecke2.y,ecke2.z},
ecke3_{ecke3.x,ecke3.y,ecke3.z}
{}

Triangle::Triangle(glm::vec3 const& ecke1, glm::vec3 const& ecke2, glm::vec3 const& ecke3, std::string const& name, Material const& mat):
Shape(name, mat),
ecke1_{ecke1.x,ecke1.y,ecke1.z},
ecke2_{ecke2.x,ecke2.y,ecke2.z},
ecke3_{ecke3.x,ecke3.y,ecke3.z}
{}

std::ostream& Triangle::print(std::ostream& os) const{
	Shape::print(os);
 os << "Punkt 1: ("<<ecke1_.x
	  << ", "<<ecke1_.y
    << ", "<<ecke1_.z
    << "Punkt 2: ("<< ecke2_.x
    << ", "<<ecke2_.y
    << ", "<<ecke2_.z
    << "Punkt 3: ("<< ecke3_.x
    << ", "<<ecke3_.y
    << ", "<<ecke3_.z
    << "\n";	
}

Hit Triangle::intersect(Ray const& ray) {
  Hit defaulthit;
  return defaulthit;
}

/*Hit Triangle::intersect(Ray const& ray) {
  glm::vec3 sub21 = ecke2_ - ecke1_;
  glm::vec3 sub31 = ecke3_ - ecke1_;
  glm::vec3 N{0.0,0.0,0.0};
  N.x=sub21.y*sub31.z-sub21.z*sub31.y;
  N.y=sub21.z*sub31.x-sub21.x*sub31.z;
  N.z=sub21.x*sub31.y-sub21.y*sub31.x;
}*/
/*bool rayTriangleIntersect( 
    const Vec3f &orig, const Vec3f &dir, 
    const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, 
    float &t) 
{ 
    // compute plane's normal
    Vec3f v0v1 = v1 - v0; 
    Vec3f v0v2 = v2 - v0; 
    // no need to normalize
    Vec3f N = v0v1.crossProduct(v0v2); // N 
    float area2 = N.length(); 
 
    // Step 1: finding P
 
    // check if ray and plane are parallel ?
    float NdotRayDirection = N.dotProduct(dir); 
    if (fabs(NdotRayDirection) < kEpsilon) // almost 0 
        return false; // they are parallel so they don't intersect ! 
 
    // compute d parameter using equation 2
    float d = N.dotProduct(v0); 
 
    // compute t (equation 3)
    t = (N.dotProduct(orig) + d) / NdotRayDirection; 
    // check if the triangle is in behind the ray
    if (t < 0) return false; // the triangle is behind 
 
    // compute the intersection point using equation 1
    Vec3f P = orig + t * dir; 
 
    // Step 2: inside-outside test
    Vec3f C; // vector perpendicular to triangle's plane 
 
    // edge 0
    Vec3f edge0 = v1 - v0; 
    Vec3f vp0 = P - v0; 
    C = edge0.crossProduct(vp0); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side 
 
    // edge 1
    Vec3f edge1 = v2 - v1; 
    Vec3f vp1 = P - v1; 
    C = edge1.crossProduct(vp1); 
    if (N.dotProduct(C) < 0)  return false; // P is on the right side 
 
    // edge 2
    Vec3f edge2 = v0 - v2; 
    Vec3f vp2 = P - v2; 
    C = edge2.crossProduct(vp2); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side; 
 
    return true; // this ray hits the triangle 
} */