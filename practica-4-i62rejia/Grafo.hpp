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
		int _curVertex; //!< Cursor del vertice
		int _curEdge;	//!< Cursor del lado

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
			_curVertex = -1;
			_curEdge = -1;
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
			for (int i = 0; i < (int)_lados.size(); ++i)
			{
				if((_lados[i].first() == u && _lados[i].second() == v) or (_lados[i].first() == v && _lados[i].second() == u))
					return true;
			}
			return false;
		}

	/*!		
	\brief     Comprueba si existe el vertice en el cursor
	\note      Función inline
	\pre   	   Ninguna
	\post	   Ninguna
	\return    Devuelve true si hay, false si no
	*/
		inline const bool hasCurrVertex() const
		{
			if (_curVertex >= 0 && _curVertex < (int)_vertices.size())
				return true;
			return false;
		}

	/*!		
	\brief     Comprueba si existe el lado en el cursor
	\note      Función inline
	\pre   	   Ninguna
	\post	   Ninguna
	\return    Devuelve true si hay, false si no
	*/
		inline const bool hasCurrEdge() const
		{
			if (_curEdge >= 0 && _curEdge < (int)_lados.size())
				return true;
			return false;
		}

	/*!		
	\brief     Devuelve el vertice donde apunta el cursor
	\note      Función inline
	\pre   	   hasCurrVertex()
	\post	   Ninguna
	\return    Devuelve objeto tipo vertice
	*/
		inline const ed::Vertice currVertex() const
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif
				return _vertices[_curVertex];
		}

	/*!		
	\brief     Devuelve el lado donde apunta el cursor
	\note      Función inline
	\pre   	   hasCurrVertex()
	\post	   Ninguna
	\return    Devuelve objeto tipo lado
	*/
		inline const ed::Lado currEdge() const
		{
			/*#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif*/

				return _lados[_curEdge];
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

			for (int i=0; i<(int)_vertices.size();i++){
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
		bool existeLado(ed::Lado l)
		{
			#ifndef NDEBUG
				assert(!isEmpty());
			#endif

			for (int i=0; i<(int)_lados.size();i++){
				if(_lados[i] == l )
					return true;
			 }
			return false;
		}

	/*!		
	\brief     Comprueba el numero de vertices del Grafo
	\note      Función inline
	\pre   	   ninguna
	\post	   Ninguna
	\return    Devuelve un entero que representa el numero de elementos en el vector
	*/
		inline int nVertices()
		{
			return _vertices.size();
		}

	/*!		
	\brief     Imprime la matriz de adyacencia
	\note      Función inline
	\pre   	   ninguna
	\post	   Ninguna
	\return    void
	*/
		inline void printMatriz(){
			int i,j;
			for(i=0; i< nVertices(); i++){
				for(j=0; j< nVertices(); j++){
					printf("[%d] [%d]: ",i,j);
					std::cout<< _Matrix[i][j]<<std::endl;
				}	
			}	
		}

		/*!
			\name Modificadores de la clase Grafo
		*/
	/*!
	\brief Reestructura la matriz de forma que comprueba que esten todos los lados puestos y tenga el tamaño adecuado.
	\note	Funcion hecha en el cpp
	\pre  Ninguna
	\post Ninguna
	*/
		void ajustarAdyacencias();

	/*!
	\brief Añade un vertice al grafo a partir del data
	\note Aumentamos el numero de vertices en 1.
	\param u: dato tipo vertice
	\pre !existeVertice(u)
	\post hasCurrVertex()
	*/
		void addVertex(ed::Vertice u)
		{
			#ifndef NDEBUG
				assert(!existeVertice(u));
			#endif

			u.setLabel(_vertices.size() + 1);
			_vertices.push_back(u);
			ajustarAdyacencias();

			_curVertex =(int) _vertices.size() - 1 ;
			#ifndef NDEBUG
				assert(hasCurrVertex());
				assert(currVertex().getDataX() == u.getDataX() && currVertex().getDataY() == u.getDataY());
			#endif
		}

		void addEdge(ed::Vertice v, ed::Vertice u, double distance)
		{
			#ifndef NDEBUG
				assert(existeVertice(v));
				assert(existeVertice(u));				
			#endif
			ed::Lado l;

			l.setItem(distance);
			l.setFirst(v);
			l.setSecond(u);
			_lados.push_back(l);
			ajustarAdyacencias();

			_curEdge = (int) _lados.size() - 1;
			#ifndef NDEBUG
				assert((hasCurrEdge() && currEdge().has(v))
					&& (currEdge().other(v) == u)
					&& (abs(currEdge().getItem() - distance) < COTA_ERROR));
				if(isDirected())
					assert(currEdge().first() == v && currEdge().second() == u);
			#endif
		}

		inline void removeVertex()
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif
				
			_vertices.erase(_vertices.begin() + _curVertex);
			ajustarAdyacencias();
		}

		inline void removeEdge()
		{
			#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif

			_lados.erase(_lados.begin() + _curEdge);
			ajustarAdyacencias();
		}

	/*!
		\name Modificadores del cursor
	*/

	/*!		
	\brief     Comprueba si existe el vertice y encuentra el primero que coincida
	\note      Función inline
	\param     x: coordenada x
	\param     y: coordenada y
	\pre   	   Ninguna
	\post	   hasCurrVertex()
	\return    void
	*/
		void findFirstVertex(float x, float y)
		{
			bool xd = false;
			int i = 0;
			while(!xd)
			{
				if(i >=(int) _vertices.size())
				{
					xd = true;
					_curVertex = -1;
				}
				if(_vertices[i].getDataX() == x && _vertices[i].getDataY() == y && xd == false)
				{
					_curVertex = i;
					xd = true;
				}
				i++;
			}
			#ifndef NDEBUG
			if(hasCurrVertex())
				assert((abs(currVertex().getDataX() - x) < COTA_ERROR) 
					&& (abs(currVertex().getDataY() - y) < COTA_ERROR));
			#endif
		}

	/*!		
	\brief     Comprueba si existe el vertice y encuentra el primero que coincida desde el cursor
	\note      Función inline
	\param     x: coordenada x
	\param     y: coordenada y
	\pre   	   Ninguna
	\post	   hasCurrVertex()
	\return    void
	*/
		void findNextVertex(float x, float y)
		{
			bool xd = false;
			int i = _curVertex;
			while(xd == false)
			{
				if(i >=(int) _vertices.size())
				{
					xd = true;
					_curVertex = -1;
				}
				if(_vertices[i].getDataX() == x && _vertices[i].getDataY() == y && xd == false)
				{
					xd = true;
					_curVertex = i;
				}
				i++;
			}

			#ifndef NDEBUG
			if(hasCurrVertex())
				assert((abs(currVertex().getDataX() - x) < COTA_ERROR) 
					&& (abs(currVertex().getDataY() - y) < COTA_ERROR));
			#endif
		}

	/*!		
	\brief     Comprueba si existe el lado y encuentra el primero
	\note      Función inline
	\param     p: peso del lado
	\pre   	   Ninguna
	\post	   hasCurrVertex()
	\return    void
	*/
		void findFirstEdge(double p)
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif

			#ifndef NDEBUG
				if(hasCurrEdge())
					assert(abs(currEdge().getItem() - p) < COTA_ERROR);
			#endif
		}

		void findNextEdge(double p)
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif

			#ifndef NDEBUG
				if(hasCurrEdge())
					assert(abs(currEdge().getItem() - p) < COTA_ERROR);
			#endif
		}

		void goToVertex(ed::Vertice v)
		{
			#ifndef NDEBUG
				assert(existeVertice(v));
			#endif
				for (int i = 0; i < (int)_vertices.size(); ++i)
				{
					if(v.getLabel() == _vertices[i].getLabel())
						_curVertex = i;
				}
			#ifndef NDEBUG
				assert((abs(currVertex().getDataX() - v.getDataX()) < COTA_ERROR) 
					&& (abs(currVertex().getDataY() - v.getDataY()) < COTA_ERROR));
			#endif
		}

		void goToEdge(ed::Vertice u, ed::Vertice v)
		{
			#ifndef NDEBUG
				assert(existeVertice(u));
				assert(existeVertice(v));				
			#endif
				bool xd;
				for (int i = 0; i < (int)_lados.size(); ++i)
				{
					if(_lados[i].first() == u && _lados[i].second() == v)
					{
						_curEdge = i;
						xd = true;
					}
				}
				if(xd == false)
					_curEdge = -1;
			#ifndef NDEBUG
				if(hasCurrEdge())
					assert(currVertex() == u
						&& currEdge().first() == u
						&& currEdge().second() == v);
			#endif
		}

		inline void goToFirstVertex()
		{
			if(!isEmpty())
				_curVertex = 0;
			else
				_curVertex = -1;
			#ifndef NDEBUG
				if(isEmpty())
					assert(!hasCurrVertex());
			#endif
		}
		inline void nextVertex()
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif
				if (_curVertex < _vertices.size() -1)
					_curVertex++;
				else
					_curVertex = -1;
		}

		inline void goToFirstEdge()
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif
			_curEdge = 0;
			_curVertex = currEdge().first().getLabel() -1;
			#ifndef NDEBUG
				if(hasCurrEdge() && isDirected())
					assert(currVertex() == currEdge().first());
			#endif
		}

		inline void nextEdge()
		{
			#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif
				_curEdge++;
				_curVertex = currEdge().first().getLabel() - 1;
			#ifndef NDEBUG
				if(hasCurrEdge() && isDirected())
					assert(currVertex() == currEdge().first());
				if(hasCurrEdge() && !isDirected())
					assert(currEdge().has(currVertex()));
			#endif
		}

}; //class Grafo
} //namespace

#endif