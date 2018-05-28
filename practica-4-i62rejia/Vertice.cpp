/*! 	
	\file    Vertice.cpp
	\brief   Clase vertice
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/

#include <iostream>

// atoi
#include <stdlib.h>

#include "Vertice.hpp"

namespace ed{


	std::ostream &operator<<(std::ostream &o, const ed::Vertice &v)
	{
		o<<v.getDataX()<<" , "<<v.getDataY()<<std::endl;

		return o;
	}

	std::istream &operator>>(std::istream &stream, ed::Vertice &v)
	{
		std::string cad,cad2;
		std::getline(stream,cad,' ');
		std::getline(stream,cad2);
		v.setData(atof(cad.c_str()),atof(cad2.c_str()));

		return stream;
	}

}