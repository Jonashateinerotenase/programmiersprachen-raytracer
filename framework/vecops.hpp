#ifndef vecops
#define vecops

#include <glm/glm.hpp>
#include <cmath>

inline glm::vec3 crossp(glm::vec3 const& s1, glm::vec3 const& s2){
	glm::vec3 N;
	N.x=s1.y*s2.z-s1.z*s2.y;
  	N.y=s1.z*s2.x-s1.x*s2.z;
  	N.z=s1.x*s2.y-s1.y*s2.x;
  	return N;
}
inline float betrag(glm::vec3 const& vecci){
	return std::sqrt(vecci.x*vecci.x+vecci.y*vecci.y+vecci.z*vecci.z);
}
inline skalar(glm::vec3 const& v1, glm::vec3 const& v2){
	return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
}
inline glm::vec3 sub(glm::vec3 const& v1, glm::vec3 const& v2){
	glm::vec3 temp;
	temp.x=v1.x-v2.x;
	temp.y=v1.y-v2.y;
	temp.z=v1.z-v2.z;
	return temp;
}
/*inline operator*(glm::vec3 const& v1, float a){
	glm::vec3 temp;
	temp.x=v1.x*a;
	temp.y=v1.y*a;
	temp.z=v1.z*a;
	return temp;
}*/
#endif