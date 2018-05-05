/*! 
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
{
	stream<<medicion.getFecha().getDia()<<"-"<<medicion.getFecha().getMes()<<"-"<<medicion.getFecha().getAgno()<<" "<<medicion.getPrecipitacion()<<" "<<std::endl;
	return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion)
{
	std::string cadena;

	std::getline(stream,cadena,'-');
    int dia = atoi(cadena.c_str());

	std::getline(stream,cadena,'-');
    int mes = atoi(cadena.c_str());

	std::getline(stream,cadena,' ');
    int agno = atoi(cadena.c_str());
    
  std::getline(stream, cadena);
  	medicion.setPrecipitacion(atof(cadena.c_str()));

  ed::Fecha *aux = new ed::Fecha(dia, mes, agno);
  medicion.setFecha(*aux);
  return stream;
} 

} // Fin del espacio de nombres ed
