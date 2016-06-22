#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <iostream>
#include "color.hpp"
#include <string>


struct Material
{
	Material():
	name{"Ich habe noch keinen Namen"},
	ka{0.0f,0.0f,0.0f},
	kd{0.0f,0.0f,0.0f},
	ks{0.0f,0.0f,0.0f},
	m{0.0f}
	{}

	Material(std::string const& name_,Color const& ka_,Color const& kd_,Color const& ks_,float m_):
		name{name_},
		ka{ka_},
		kd{kd_},
		ks{ks_},
		m{m_}
	{}

	std::string name;
	Color ka;
	Color kd;
	Color ks;
	float m;
	  friend std::ostream& operator<<(std::ostream& os, Material const& m){
	  os << m.name << "\n"
	  << m.ka << "\n"
	  << m.kd << "\n"
	  << m.ks << "\n"
	  << m.m << "\n";
	  return os;
	}
};

#endif //#define MATERIAL_HPP
