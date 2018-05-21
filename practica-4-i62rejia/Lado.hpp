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
	\name Constructor
	*/

	/*!		
	\brief     Constructor parametrizado 
	\note      Función inline
	\pre   	   Ninguna
	\post  	   Crea un nuevo objeto de la clase Lado, con un item, un vertice de origen y un vertice de destino
	\sa	   setItem,setPrimero,setSegundo	   
	*/
		Lado();
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
	\note      Función codificada en el fichero cpp
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



};	//clase lado
}	//namespace

#endif