/*! 	
	\file    Lado.hpp
	\brief   Declaración del TAD Lado
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/
#ifndef _LADOHPP_
#define _LADOHPP_

#include "Vertice.hpp"

#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <iostream>

/*!	
\namespace ed
\brief Espacio de nombres para la asignatura Estructuras de Datos
*/

namespace ed{


/*!
\class Lado
\brief Definición de la clase Lado
\note  Hereda de la clase LadoInterfaz
*/

class Lado:
{

/*!		
\name Atributos o métodos privados
*/

	private:
	
	double			_item;		//!< \brief longitud del lado
	ed::Vertice		_origen;	//!< \brief Vertice origen
	ed::Vertice		_destino;       //!< \brief Vertice destino
		
	
	public:
	/*!
	\name Constructor de la clase Lado
	*/

	/*!		
	\brief     Constructor  
	\note      Función inline
	\pre   	   Ninguna
	\post  	   Crea un nuevo objeto de la clase Lado, con un item, un vertice de origen y un vertice de destino
	\sa	   	   setItem,setPrimero,setSegundo	   
	*/
		Lado();

	/*!
	\name Observadores de la clase Lado
	*/
	/*!		
	\brief     Observador del item del lado
	\note      Función inline
	\pre   	   Ninguna
	\post	   Ninguna
	\return    Devuelve la longitud del lado
	*/
		inline const double getItem() const
		{
			return _item;
		}

	/*!		
	\brief     Comprueba si el vertice pasado es el extremo de un lado
	\note      Función codificada inline
	\param	   v objeto de la clase Vertice
	\pre   	   Ninguna
	\post  	   Ninguna
	\return	   Devuelve true si el vertice v es un extremo del lado, false en caso contrario
	\sa    	   getPrimero, getSegundo
	*/
		inline bool has(ed::Vertice v)
		{
			if( v == getPrimero() || v==getSegundo())
				return true;
			return false;
		}

	/*!		
	\brief	   Comprueba cual es el vertice del otro extremo al del vertice v     
	\note      Función codificada inline
	\pre   	   Debe tener al vertice v en un extremo del lado, es decir, tiene(v)= true
	\post  	   Se debe de comprobar que existe el vertice en el otro extremo y devolverlo. 
	\return	   Devuelve el vertice que se encuentra en el extremo opuesto a v
	\sa    	   tiene,getPrimero,getSegundo
	*/
		inline ed::Vertice other(ed::Vertice v)
		{
			#ifndef NDEBUG
				assert(has(v));
			#endif
				if(v == _origen)
					return _destino;
				else
					return _origen;
		}

	/*!		
	\brief     Observador del primer vertice o del vertice origen del lado
	\note      Función inline
	\pre   	   Ninguna
	\post  	   Ninguna
	\return	   Devuelve el vertice origen o primer vertice del lado
	*/
		inline const ed::Vertice first() const
		{
			#ifndef NDEBUG
				assert(other(_origen) == _destino);
			#endif
			return _origen;
		}

	/*!		
	\brief     Observador del segundo vertice o del vertice destino del lado
	\note      Función inline
	\pre   	   Ninguna
	\post  	   Ninguna
	\return	   Devuelve el vertice destino o segundo vertice del lado
	*/
		inline const ed::Vertice second() const
		{
			#ifndef NDEBUG
				assert(other(_destino) == _origen);
			#endif
			return _destino;
		}

	/*!
	\name Modificadores de la clase lado
	*/

	/*!		
	\brief     Modifica el valor del item del lado
	\note      Función inline
	\param	   item, variable tipo double que almacena el nuevo valor del item del lado 
	\pre   	   Ninguna
	\post  	   Ninguna
	\return	   void
	*/
		inline void setItem(const double & item)
		{
			getItem() = item;
			#ifndef NDEBUG
				assert(getItem() == item);
			#endif
		}

	/*!		
	\brief     Modifica el vertice origen o primer vertice del lado
	\note      Función inline
	\param	   v, objeto de la clase Vertice que almacena el nuevo valor del vertice origen del lado 
	\pre   	   Ninguna
	\post  	   Ninguna
	\return	   void
	*/
		inline void setFirst(const ed::Vertice &v)
		{
			first() = v;
			#ifndef NDEBUG
				assert(first() == v);
			#endif
		}

	/*!		
	\brief     Modifica el vertice destino o segundo vertice del lado
	\note      Función inline
	\param	   v, objeto de la clase Vertice que almacena el nuevo valor del vertice destino del lado 
	\pre   	   Ninguna
	\post  	   Ninguna
	\return	   void
	*/
		inline void setSecond(const ed::Vertice &v)
		{
			second() = v;
			#ifndef NDEBUG
				assert(second() == v);
			#endif
		}


};	//clase lado
}	//namespace

#endif