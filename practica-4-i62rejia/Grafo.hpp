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
		std::vector< std::vector<int> > _Matrix;	//!< Matrix de adyacencia

		int _dirigido;  //!< Define si es dirigido o no, 1 -> Dirigido   0 -> No dirigido 
		int _CurVertex; //!< Cursor del vertice
		int _CurEdge;	//!< Cursor del lado

	public:
	/*!
		\name Constructor
	*/
	/*!		
	\brief     Constructor parametrizado 
	\note      Función inline
	\param     dirigido: parametro no obligatorio que muestra si es o no dirigido el grafo
	\pre   	   Ninguna
	\post  	   Crea un nuevo objeto de la clase Grafo, con un vector de lados, un vector de vertices y una matriz de adyacencias
	\sa	   setItem,setPrimero,setSegundo	   
	*/
		inline Grafo(int dirigido = 0)
		{
			_Matrix.resize(0);
			_vertices.resize(0);
			_lados.resize(0);
			_dirigido = dirigido;
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
		inline bool isEmpty() const
		{
			if(_vertices.size() == 0 && _lados.size() == 0)
				return true;
			return false;
		}
	/*!		
	\brief     Comprueba si el grafo es dirigido
	\note      Función inline
	\pre   	   Ninguna
	\post	   Ninguna
	\return    Devuelve true si es dirigido el grafo, false en caso contrario
	*/
		inline bool isDirected() const
		{
			if(_dirigido == 1)
				return true;
			return false;
		}
	/*!		
	\brief     Comprueba si u y v estan unidos por un lado
	\note      Función inline
	\param     u: vertice uno
	\param     v: vertice dos
	\pre   	   No puede estar vacio
	\post	   Ninguna
	\return    Devuelve true si hay, false si no
	*/
		inline bool adjacent(ed::Vertice u, ed::Vertice v) const
		{
			#ifndef NDEBUG
				assert(!isEmpty());
			#endif
			for (int i = 0; i < _lados.size(); ++i)
			{
				if((_lados[i].first() == u && _lados[i].second() == v) or (_lados[i].first() == v && _lados[i].second() == u))
					return true;
			}
			return false;
		}

		inline const ed::Vertice currVertex() const
		{
			/*#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif*/
				return _vertices[_CurVertex];
		}

		inline const ed::Lado currEdge() const
		{
			/*#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif*/
				return _lados[_CurEdge];
		}

	/*!		
	\brief     Comprueba si existe el vertice
	\note      Función inline
	\param     v: vertice a buscar
	\pre   	   No puede estar vacio
	\post	   Ninguna
	\return    Devuelve true si hay, false si no
	*/
		inline bool existeVertice(ed::Vertice v) const
		{
			#ifndef NDEBUG
				assert(!isEmpty());
			#endif

			int i;
			for (i=0; i<_vertices.size();i++){
				if(_vertices[i] == v )
					return true;
			}
			return false;
		}

	/*!		
	\brief     Comprueba si existe el lado
	\note      Función inline
	\param     v: lado a buscar
	\pre   	   No puede estar vacio
	\post	   Ninguna
	\return    Devuelve true si hay, false si no
	*/
		inline bool existeLado(ed::Lado l)
		{
			#ifndef NDEBUG
				assert(!isEmpty());
			#endif

			int i;
			for (i=0; i<_lados.size();i++){
				if(_lados[i] == l )
					return true;
			}
			return false;
		}


		/*!
			\name Modificadores de la clase Grafo
		*/

		inline void addVertex(ed::Vertice u)
		{
			#ifndef NDEBUG
				assert(!existeVertice(u));
			#endif

			u.setLabel(_vertices.size() + 1);
			_vertices.push_back(u);
		//Queda ajustar adyacencia

			/*#ifndef NDEBUG
				assert(hasCurrVertex());
				assert(currVertex().getDataX() == u.getDataX() && currVertex().getDataY() == u.getDataY());
			#endif*/
		}

		inline void addEdge(ed::Vertice v, ed::Vertice u, double distance)
		{
			#ifndef NDEBUG
			#endif
			ed::Lado l;

			l.setItem(distance);
			l.setFirst(v);
			l.setSecond(u);
			_lados.push_back(l);
			//Ajustar adyacencias
		}

}; //class Grafo
} //namespace

#endif