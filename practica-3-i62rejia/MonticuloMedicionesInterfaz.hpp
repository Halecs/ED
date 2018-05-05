/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author Alejandro Reyes Jimenez
	\date  19/04/2018
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed
{

	/*!
  		\class MonticuloMedicionesInterfaz
  		\brief Definición de la clase abstracta MonticuloMedicionesInterfaz
	*/
	class MonticuloMedicionesInterfaz
	{
		public:

			/*!	
				\brief   Método público que permite conocer si el monticulo esta vacio
				\warning Función virtual pura: se debe redefinir en la clase heredera
				\pre     Ninguna
				\post    Ninguna
   				\return  Devuelve TRUE/FALSE
			*/
			virtual bool isEmpty() const = 0;

			/*!	
				\brief   Método público que permite conocer la cima del monticulo
				\warning Función virtual pura: se debe redefinir en la clase heredera
				\pre     El monticulo no puede estar vacio
				\post    Ninguna
   				\return  Devuelve un objeto de la clase medicion
			*/
			virtual ed::Medicion top() const = 0;

			/*!	
				\brief   Método público que inserta una medicion en el monticulo
				\warning Función virtual pura: se debe redefinir en la clase heredera
				\pre     El monticulo no puede estar vacio
				\post    Ninguna
   				\return  Devuelve void
			*/
			virtual void insert(Medicion &medicion) = 0;

			/*!	
				\brief   Método público que borra la cima del monticulo
				\warning Función virtual pura: se debe redefinir en la clase heredera
				\pre     El monticulo no puede estar vacio
				\post    Ninguna
   				\return  Devuelve void
			*/
			virtual void remove() = 0;

	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
