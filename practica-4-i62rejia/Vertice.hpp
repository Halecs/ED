/*! 	
	\file    Vertice.hpp
	\brief   Clase vertice
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/
#ifndef _VERTICEHPP_
#define _VERTICEHPP_

#define COTA_ERROR   1.0e-6  //!< Cota de error
// Entrada y salida 
#include <iostream>
#include "macros.hpp"

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cstdlib>
#include <cmath>
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

/*!	
\namespace ed
\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed {

/*!
\class Vertice
\brief Definición de la clase Vertice
*/

class Vertice
{
	private:
	/*!		
	\name Atributos o métodos privados
	*/
		double x_;	//!< Coordenada x del vertice
		double y_;	//!< Coordenada y del vertice
		int label_; //!< Nombre del vertice (Unico)

	public:
	/*!
	\name Constructor de la clase Vertice
	*/
		//Vertice();

	/*!
	\name Observadores de la clase Vertice
	*/
/*!	
	\brief  Método público que devuelve la coordenada x del vertice
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
	\return const double, el valor de la coordenada
*/
		inline const double & getDataX()const { return x_;};

/*!	
	\brief  Método público que devuelve la coordenada y del vertice
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
	\return const double, el valor de la coordenada
*/
		inline const double & getDataY()const {return y_;};

/*!	
	\brief  Método público que devuelve el nombre del vertice
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
	\return const int, el nombre
*/
		inline const int & getLabel()const {return label_;};

	/*!
	\name Modificadores de la clase Vertice
	*/
/*!	
	\brief  Método público que permite modificar el campo informativo del Vertice
	\note   Función inline
	\param  x: nuevo valor del campo x
	\param  y: nuevo valor del campo y
	\pre    Ninguna
	\post   El campo informativo del Vertice es igual al parámetro pasado como argumento
	\return void
*/
		inline void setData(double x, double y)
		{
			x_ = x;
			y_ = y;

			#ifndef NDEBUG
				assert((std::abs(x_ - x)) < COTA_ERROR);
				assert((std::abs(y_ - y)) < COTA_ERROR);
			#endif
		}
/*!	
	\brief  Método público que permite modificar el campo informativo del Vertice
	\note   Función inline
	\param  x: nuevo valor del campo informativo
	\pre    Ninguna
	\post   El campo informativo del Vertice es igual al parámetro pasado como argumento
	\return void
*/
		inline void setLabel(int x)
		{
			label_ = x;

			#ifndef NDEBUG
				assert(getLabel() == x);
			#endif

		}
/*!		
	\brief  Operador de asignacion entre objetos de tipo Vertice
	\note   Función inline
	\attention Función sobrecargada
	\param  v: objeto de tipo Vertice
	\post   El objeto actual es igual al parámetro
	\return Devuelve una referencia al objeto actual
*/
		inline Vertice &operator=(const Vertice &v)
		{
			if(this != &v)
			{
				setData(v.getDataX(),v.getDataY());
				setLabel(v.getLabel());
			}
			return *this;
		}
/*!		
	\brief     Operador que compara el item y la etiqueta de dos vertices
	\note      Función inline
	\attention Función sobrecargada
	\param     v: objeto tipo Vertice
	\pre       Ambos vertices deben de tener valores en item y etiqueta
	\post      Ninguna
	\return    Devuelve true si el item y la etiqueta son iguales; false, en caso contrario
*/
		inline bool operator==(const Vertice &v) const
		{
			return ((getLabel() == v.getLabel()) 
				and (getDataX() == v.getDataX())
				and (getDataY() == v.getDataY()));
		}


	// friend std::ostream &operator<<(std::ostream &o, const Vertice &v);

	// friend std::istream &operator>>(istream &stream, Vertice &v);

};

/*!
	\brief  Operador de entrada  
	\param  stream: flujo de entrada
	\param  v: objeto de tipo Vertice  
	\pre    El vertice del parametro debe existir
	\post   Se escriben los valores de los atributos del Vertice en flujo de entrada
	\return Devuelve el stream de entrada
*/
	std::istream &operator>>(std::istream &stream, ed::Vertice &v);

/*!		
	\brief  Operador de extracción  
	\param  o: flujo de salida
	\param  v: objeto de tipo Vertice  
	\pre    El vertice del parametro debe existir
	\post   Se escriben los valores de los atributos del Vertice en flujo de salida
	\return Devuelve el stream de salida
*/
	std::ostream &operator<<(std::ostream &o, const ed::Vertice &v);
} //end namespace ed

#endif