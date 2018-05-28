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

	/*!		
	\brief     Menu de la practica 4
	\note      Función hecha en el principal.cpp
	\pre   	   Ninguna
	\post	   Ninguna
	\return    Devuelve un entero
	*/
	int menu();

	/*!		
	\brief     Carga un grafo desde un fichero introducido por el usuario
	\note      Función hecha en funcionesAuxiliares.cpp
	\pre   	   Ninguna
	\post	   Ninguna
	\return    void
	*/
	void cargarGrafoDesdeFichero(std::string const & nombreFichero, ed::Grafo & grafo);

	/*!		
	\brief     Graba el grafo desde un fichero introducido por el usuario
	\note      Función hecha en funcionesAuxiliares.cpp
	\pre   	   Ninguna
	\post	   Ninguna
	\return    void
	*/
	void grabarGrafoaFichero(std::string const & nombreFichero, ed::Grafo & grafo, ed::Grafo & kruskal, ed::Grafo & prim);

	/*!		
	\brief     Comprueba si el grafo principal esta vacio o no
	\note      Función hecha en funcionesAuxiliares.cpp
	\pre   	   Ninguna
	\post	   Ninguna
	\return    void
	*/
	void estaVacio(ed::Grafo const & grafo);
}


#endif
