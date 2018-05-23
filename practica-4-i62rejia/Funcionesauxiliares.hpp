/*! 	
	\file    Funcionesauxiliares.hpp
	\brief   Funcionesauxiliares Practica 4
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/

#ifndef _FUNAUX_
#define _FUNAUX_

#include "macros.hpp"
#include "Grafo.hpp"


namespace ed{
	int menu();
	void cargarGrafoDesdeFichero(std::string const & nombreFichero, ed::Grafo & grafo);
	void grabarGrafoaFichero(std::string const & nombreFichero, ed::Grafo const & grafo);
}


#endif
