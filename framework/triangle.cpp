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
/*ecke1_{ecke1.x,ecke1.y,ecke1.z},
ecke2_{ecke2.x,ecke2.y,ecke2.z},
ecke3_{ecke3.x,ecke3.y,ecke3.z}*/
ecke1_{ecke1},
ecke2_{ecke2},
ecke3_{ecke3}
{}

Triangle::Triangle(glm::vec3 const& ecke1, glm::vec3 const& ecke2, glm::vec3 const& ecke3, std::string const& name, Material const& mat):
Shape(name, mat),
/*ecke1_{ecke1.x,ecke1.y,ecke1.z},
ecke2_{ecke2.x,ecke2.y,ecke2.z},
ecke3_{ecke3.x,ecke3.y,ecke3.z}*/
ecke1_{ecke1},
ecke2_{ecke2},
ecke3_{ecke3}
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

/*Hit Triangle::intersect(Ray const& ray) {
  Hit defaulthit;
  return defaulthit;
}*/

Hit Triangle::intersect(Ray const& ray) {
  Hit impact;
  Hit noimpact;
  glm::vec3 e1,e2;
  glm::vec3 P,Q,T;
  float det, inv_det, u, v;
  float t;
  float bias = 0.00009;

  e1 = sub(ecke2_,ecke1_);
  e2 = sub(ecke3_,ecke1_);

  P = crossp(ray.direction,e2);
  det = skalar(e1,P);
  if(det > -bias && det < bias)return noimpact;
  inv_det = 1.0f / det;
  T = ray.origin-ecke1_;
  u = skalar(T,P) * inv_det;
  if(u < 0.0f || u > 1.0f)return noimpact;
  Q = crossp(T,e1);
  v = skalar(ray.direction,Q) * inv_det;
  if (v < 0.0 || u + v > 1.0)return noimpact;
  t = skalar(e2,Q) * inv_det;
  
  
  
  if (t > bias)
  { 
    float distance = t;
    impact.distance_=t;
    impact.target_  = ray.origin + (distance * glm::normalize(ray.direction));
    glm::vec3 norm = crossp(ecke1_-ecke2_,ecke1_-ecke3_);
    glm::normalize(norm);
    impact.hit_=true;
    impact.normal_=norm;
    impact.sptr_=this;
    //std::cout << "t: " << t << "\n";
    return impact;
    //std::cout << "ende";
    //std::cout << norm.x << norm.y << norm.z;
    //taken from https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
  }

  return noimpact;
 /* Hit HelloHitty;
  glm::vec3 norm = crossp(ecke1_-ecke2_,ecke1_-ecke3_);
  //glm::normalize(norm);
  float d = skalar(norm , ray.direction);
  if(d != 0)
  {
    float distance = (-(norm.x*(ray.origin.x - ecke1_.x))-(norm.y*(ray.origin.y - ecke1_.y))
      -(norm.z*(ray.origin.z - ecke1_.z))) / d;
    if(distance > 0)
    { 
      HelloHitty.target_  = ray.origin + (distance * ray.direction);
      {
        if(skalar(ecke3_-ecke1_, ecke1_ - HelloHitty.target_) <= skalar(ecke3_ - ecke1_, ecke2_ - ecke1_) and skalar(ecke1_-ecke2_, ecke2_ - HelloHitty.target_) <= skalar(ecke1_ - ecke2_, ecke3_ - ecke2_) and skalar(ecke2_-ecke3_, ecke3_ - HelloHitty.target_) <= skalar(ecke2_ - ecke3_, ecke1_ - ecke3_) )
        {
        HelloHitty.hit_ = true;
        HelloHitty.normal_ = norm;
        HelloHitty.sptr_ = this;
        HelloHitty.distance_= distance; // glm::length(HelloHitty.target_ - ray.origin);
        }
      }
    }
  }
  return HelloHitty;*/
  /*glm::vec3 sub21{0.0f,0.0f,0.0f};
  sub21.x = ecke2_.x - ecke1_.x;
  sub21.y = ecke2_.y - ecke1_.y;
  sub21.z = ecke2_.z - ecke1_.z;

  glm::vec3 sub31{0.0f,0.0f,0.0f};
  sub31.x = ecke3_.x - ecke1_.x;
  sub31.y = ecke3_.y - ecke1_.y;
  sub31.z = ecke3_.z - ecke1_.z;

  glm::vec3 N = crossp(sub21,sub31);
  float A = betrag(N);
  Hit HelloHitty;
  float NdotprodwithRaydir = skalar(N, ray.direction);
  if (fabs(NdotprodwithRaydir) < 0.005)return HelloHitty;
    
    
  float d = skalar(N,ecke1_);
  float t = (skalar(N,ray.origin)+d) / NdotprodwithRaydir;
  glm::vec3 p = ray.origin + t * ray.direction;
  glm::vec3 C{0.0f,0.0f,0.0f};

  //ecke 1
  glm::vec3 eckeone = ecke2_-ecke1_;
  glm::vec3 vpone = p - ecke1_;
  C=crossp(ecke1_,vpone);
  if(skalar(N,C)<0)return HelloHitty;

  //ecke 2
  glm::vec3 ecketwo = ecke3_-ecke2_;
  glm::vec3 vptwo = p - ecke2_;
  C=crossp(ecke2_,vptwo);
  if(skalar(N,C)<0)return HelloHitty;

  //ecke 3
  glm::vec3 eckethree = ecke1_-ecke3_;
  glm::vec3 vpthree = p - ecke3_;
  C=crossp(ecke3_,vpthree);
  if(skalar(N,C)<0)return HelloHitty;
  glm::vec3 target= ray.origin + glm::normalize(ray.direction) * t;
  
  glm::vec3 normale= glm::normalize(crossp(sub21,sub31));
  Hit trifft;
  trifft.hit_=true;
  trifft.distance_=t;
  trifft.target_=target;
  trifft.normal_=normale;
  trifft.sptr_=this;
  return trifft;*/

}
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
    Vec3f vecke2_ = P - v2; 
    C = edge2.crossProduct(vecke2_); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side; 
 
    return true; // this ray hits the triangle 
} */