/*! 	
	\file    Grafo.hpp
	\brief   Declaración del TAD Lado
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/

#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

#include "macros.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
using std::istream;
using std::ostream;

/*!	
\namespace ed
\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed {

/*!
\class Grafo
\brief Definición de la clase Grafo
*/

class Grafo
{
	private:
	/*!		
		\name Atributos o métodos privados
	*/
		std::vector<ed::Vertice> _vertices; //!< Vector de vertices
		std::vector<ed::Lado> _lados;		//!< Vector de lados
		std::vector< std::vector<int> > Matrix;	//!< Matrix de adyacencia

	public:
	/*!
		\name Constructor
	*/
	/*!		
	\brief     Constructor parametrizado 
	\note      Función inline
	\pre   	   Ninguna
	\post  	   Crea un nuevo objeto de la clase Grafo, con un vector de lados, un vector de vertices y una matriz de adyacencias
	\sa	   setItem,setPrimero,setSegundo	   
	*/
		inline Grafo()
		{
			Matrix.resize(0);
			_vertices.resize(0);
			_lados.resize(0);
		}

	/*!
		\name Observadores de la clase Grafo
	*/
		
	/*!		
	\brief     Comprueba si el grafo esta vacio
	\note      Función inline
	\pre   	   Ninguna
	\post	   Ninguna
	\return    Devuelve true si el grafo estaba vacio, falso en caso contrario
	*/	
		inline bool isEmpty()
		{
			if(_vertices.size() == 0 && _lados.size() == 0)
				return true;
			return false;
		}

		inline bool adjacent(Vertice u, Vertice v)
		{

		}

		inline bool hasCurrVertex()
		{

		}

		inline void addVertex(Vertice u)
		{
			Matrix.push_back(std::vector<int> (1,0));

		}



}; //class Grafo
} //namespace

#endif