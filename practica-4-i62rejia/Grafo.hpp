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
#include <cmath>
#include <algorithm>
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
		std::vector< std::vector<double> > _Matrix;	//!< Matrix de adyacencia
		int padre[100];

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
		inline const ed::Vertice & currVertex() const
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
		inline const ed::Lado & currEdge() const
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
		bool existeLado(ed::Lado l) const
		{
			for (int i=0; i<(int)_lados.size();i++){
				if(_lados[i] == l )
					return true;
			 }
			return false;
		}

		ed::Lado findLado(ed::Vertice v, ed::Vertice u) const
		{
			for (int i = 0; i <(int) _lados.size(); ++i)
			{
				if(_lados[i].first() == v && _lados[i].second() == u)
					return _lados[i];
			}
		}

	/*!		
	\brief     Comprueba el numero de vertices del Grafo
	\note      Función inline
	\pre   	   ninguna
	\post	   Ninguna
	\return    Devuelve un entero que representa el numero de elementos en el vector
	*/
		inline int nVertices() const
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
					std::cout<< _Matrix[i][j]<<"\t";
				}
				std::cout<<std::endl;
			}	
		}

		inline const double getElement(int i, int j) const
		{
			return _Matrix[i][j];
		}

	/*!		
	\brief     Calcula el peso del lado
	\note      Función inline
	\param 	   u: primer vertice del lado
	\param 	   v: segundo vertice del lado
	\pre   	   ninguna
	\post	   Ninguna
	\return    void
	*/
		inline double calcularPeso(ed::Vertice u, ed::Vertice v) const
		{
			double resultado;
			double totalx = pow(u.getDataX() - v.getDataX(),2);
			double totaly = pow(u.getDataY() - v.getDataY(),2);
			resultado = sqrt(totalx + totaly);
			return resultado;
		}

		inline static bool sortLados(Lado a, Lado b){return a.getItem() < b.getItem();}
		inline void makep()
		{
			for (int i = 0; i < nVertices()+1; ++i)
			{
				padre[i] = i;
			}
		}
		inline int find(int x)
		{
			if(x == padre[x])
				return x;
			else
				return find(padre[x]);
		}

		inline void Union(int x, int y)
		{
			int a = find(x);
			int b = find(y);
			padre[a] = b;
		}

		inline bool same(int x, int y)
		{
				if(find(x) == find(y))
					return true;
				return false;
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
				if(!isEmpty())
					assert(!existeVertice(u));
			#endif
			u.setLabel(_vertices.size() + 1);
			_vertices.push_back(u);
			ajustarAdyacencias();

			for (int i = 0; i < nVertices(); ++i)
			{
				if(u.getLabel() != _vertices[i].getLabel())
				{
					addEdge(u, _vertices[i]);
				}
			}

			_curVertex =(int) _vertices.size() - 1 ;
			#ifndef NDEBUG
				assert(hasCurrVertex());
				assert(currVertex().getDataX() == u.getDataX() && currVertex().getDataY() == u.getDataY());
			#endif
		}

		void addVertexN(float x, float y)
		{
			ed::Vertice a;
			/*if(!isEmpty() && existeVertice(a))
			{
				std::cout<<BIRED<<"Ya existe el vertice a introducir, error"<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}*/

			a.setData(x, y);
			a.setLabel(_vertices.size() + 1);
			_vertices.push_back(a);
			ajustarAdyacencias();

			_curVertex =(int) _vertices.size() - 1 ;
			#ifndef NDEBUG
				assert(hasCurrVertex());
				assert(currVertex().getDataX() == a.getDataX() && currVertex().getDataY() == a.getDataY());
			#endif
		}

	/*!
	\brief Añade un lado al grafo a partir del data
	\note Aumentamos el numero de lados en 1.
	\param v: dato tipo vertice
	\param u: dato tipo vertice
	\pre existeVertice(u)
	\post hasCurrEdge()
	*/
		void addEdge(ed::Vertice v, ed::Vertice u)
		{
			#ifndef NDEBUG
				 // assert(existeVertice(v));
				 // assert(existeVertice(u));				
			#endif
			ed::Lado l;
			l.setItem(calcularPeso(v, u));
			l.setFirst(v);
			l.setSecond(u);
			_lados.push_back(l);
			_Matrix[l.first().getLabel()-1][l.second().getLabel()-1] = l.getItem();
			_Matrix[l.second().getLabel()-1][l.first().getLabel()-1] = l.getItem();

			_curEdge = (int) _lados.size() - 1;
			#ifndef NDEBUG
				assert((hasCurrEdge() && currEdge().has(v))
					&& (currEdge().other(v) == u)
					&& (abs(currEdge().getItem() - l.getItem()) < COTA_ERROR));
				if(isDirected())
					assert(currEdge().first() == v && currEdge().second() == u);
			#endif
		}

	/*!
	\brief Borra un vertice del grafo, señalado por el cursor
	\note funcion inline
	\pre existeVertice(u)
	\post hasCurrEdge()
	*/
		inline void removeVertex()
		{
			#ifndef NDEBUG
				assert(hasCurrVertex());
			#endif
			int ref = _curVertex;
			_vertices.erase(_vertices.begin() + _curVertex);

			for (; ref <nVertices(); ++ref)
				_vertices[ref].setLabel(_vertices[ref].getLabel() -1);

			for (int i = 0; i < (int)_lados.size(); ++i)
			{
				if(_lados[i].first().getLabel() == _curVertex +1)
				{
					int et = _lados[i].first().getLabel();
					_lados[i].first().setLabel(et);
				}

				if(_lados[i].second().getLabel() == _curVertex +1)
					_lados[i].second().setLabel(_lados[i].second().getLabel() -1);
			}
			ajustarAdyacencias();
		}

		inline void removeEdge()
		{
			#ifndef NDEBUG
				assert(hasCurrEdge());
			#endif
			_Matrix[currEdge().first().getLabel()-1][currEdge().second().getLabel()-1] = std::numeric_limits<double>::infinity();
			_Matrix[currEdge().second().getLabel()-1][currEdge().first().getLabel()-1] = std::numeric_limits<double>::infinity();
			_lados.erase(_lados.begin() + _curEdge);
			// ajustarAdyacencias();
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
					if((_lados[i].first() == u && _lados[i].second() == v)
						or (_lados[i].second() == u && _lados[i].first() == v))
					{
						_curEdge = i;
						xd = true;
					}
				}
				if(xd == false)
					_curEdge = -1;
			#ifndef NDEBUG
				/*if(hasCurrEdge())
					assert(currVertex() == v
						&& currEdge().first() == u
						&& currEdge().second() == v);*/
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
				if (_curVertex < (int)_vertices.size() -1)
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

		/*! 
			\name Algoritmos de Arbol Abarcador
		*/

		ed::Grafo kruskal();
		ed::Grafo prim();


		/*!
			\name Operador de salida de Grafo
		*/

		friend std::ostream &operator<<(std::ostream &o, const Grafo &g)
		{
			int i,j;
			for(i=0; i< g.nVertices(); i++){
				for(j=0; j< g.nVertices(); j++){
					o<<g.getElement(i,j)<<"\t";
				}
				o<<"\n";
			}
			return o;	
		}
}; //class Grafo
} //namespace

#endif