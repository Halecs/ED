/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Alejandro Reyes Jimenez
	\date 19/04/2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed
{
//!  Definición de la clase MonticuloMediciones
class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:

		//! \name Atributos privados de la clase MonticuloMediciones
		ed::Medicion _mediciones[366];	//!< Vector de mediciones
		int _size;						//!< Tamaño del vector de mediciones 

		//! \name Métodos privados de la clase MonticuloMediciones

	/*! 
		\brief   Función que devuelve el elemento i del monticulo
		\note    Función inline
		\return  Valor del atributo que representa la posicion (tipo int)
		\pre     (i>=0) && (i<366)
		\post    Ninguna
	*/
		inline ed::Medicion getElement(int i) const
		{
			#ifndef NDEBUG
				assert((i>=0) && (i<366));
			#endif
			return _mediciones[i];
		}

	/*! 
		\brief   Función asigna a un elemento i una medicion
		\note    Función inline
		\param	 i: entero, posicion del vector
		\param	 medicion: elemento a asignar
		\return  void
		\pre     (i>=0) && (i<366)
		\post    getElement(i) == medicion
	*/
		inline void setElement(int i, ed::Medicion &medicion)
		{
			#ifndef NDEBUG
				assert((i>=0) && (i<366));
			#endif
			_mediciones[i].setFecha(medicion.getFecha());
			_mediciones[i].setPrecipitacion(medicion.getPrecipitacion());

			#ifndef NDEBUG
				getElement(i) == medicion;
			#endif		
		}

	/*! 
		\brief   Función que devuelve el el hijo izquierdo
		\note    Función inline
		\return  Posicion en el vector del hijo izquierdo
		\pre     i=>0
		\post    lc == 2*i +1
	*/
		inline int getLeftChild(int i) const
		{
			#ifndef NDEBUG
				assert(i >= 0);
			#endif

			int leftchild = 2*i + 1;

			#ifndef NDEBUG
				assert(leftchild == 2* i +1);
			#endif
			return leftchild;
		}

	/*! 
		\brief   Función que devuelve el hijo derecho
		\note    Función inline
		\return  Posicion en el vector del hijo derecho
		\pre     i>=0
		\post    lc == 2*i +2
	*/
		inline int getRightChild(int i) const
		{
			#ifndef NDEBUG
				assert(i >= 0);
			#endif

			int rightchild = 2*i + 2;

			#ifndef NDEBUG
				assert(rightchild == 2*i +2);
			#endif
			return rightchild;
		}

	/*! 
		\brief   Función que devuelve el padre
		\note    Función inline
		\return  Posicion en el vector del padre
		\pre     i>=1
		\post    parent = (i-1) / 2
	*/
		inline int getParent(int i) const
		{
			#ifndef NDEBUG
				assert(i >= 1);
			#endif

			int  parent = (i-1)/2;

			#ifndef NDEBUG
				 assert(parent == (i-1)/2);
			#endif
			return (int)parent;						
		}
		void shiftUp(int i);
		void shiftDown(int i);
		bool has(ed::Medicion &medicion) const;
	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

	/*! 
		\brief     Constructor que crea un monticulo     
		\note      Función inline
	 	\warning   Los parámetros no tienen valores por defecto
		\pre       Ninguna
		\post      El monticulo debe estar vacio
	*/
		inline MonticuloMediciones()
		{
			ed::Medicion *aux = new ed::Medicion();
			_mediciones[0] = *aux;
			_size = 0;
			#ifndef NDEBUG
				assert(isEmpty() == true);
			#endif
		}

		//! \name Observadores

	/*! 
		\brief     Función que comprueba si el monticulo esta vacio
		\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\return    bool: true, si el monticulo esta vacio; false, en caso contrario
		\pre       Ninguna
		\post      Ninguna
	*/
		inline bool isEmpty() const
		{
			if(_size == 0)
				return true;
			return false;
		}

	/*! 
		\brief     Función que devuelve el tamaño del monticulo
		\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\return    Tamaño del monticulo (int)
		\pre       Ninguna
		\post      Ninguna
	*/
		inline int size() const
		{
			return _size;
		}

	/*! 
		\brief     Función que devuelve la medicion primera del monticulo
		\attention Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\return    Objeto de tipo medicion
		\pre       Ninguna
		\post      Ninguna
	*/
		inline ed::Medicion top() const
		{
			#ifndef NDEBUG
				assert(isEmpty() == false);
			#endif
			return getElement(0);
		}

		inline ed::Medicion getMedicion(int i) const
		{
			return getElement(i);
		}
		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

	/*! 
		\brief     Función que insertar una medicion en el monticulo
		\return    void
		\param	   medicion: objeto a introducir en el monticulo
		\pre       Ninguna
		\post      isEmpty() == false
	*/
		void insert(ed::Medicion &medicion);

	/*! 
		\brief     Función que borrar la primera medicion del monticulo
		\return    void
		\pre       isEmpty() == false
		\post      size() == old.size() - 1
	*/
		void remove();

	/*! 
		\brief     Función que borrar todas las mediciones del monticulo
		\return    void
		\pre       isEmpty() == false
		\post      size() == 0
	*/
		void removeAll();

	/*! 
		\brief     Función que modifica la cima del monticulo
		\return    void
		\param	   medicion: objeto con el que modificar en el monticulo
		\pre       isEmpty() == true
		\post      old.top() != top()
 	*/
		void modify(ed::Medicion &medicion);

		//! \name Operadores

	/*! 
		\brief     Operador de asignación: operador que "copia" un monticulo en otro monticulo
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\warning   Se requiere que las funciones tengan el modificador const
		\param     objeto: objeto de la clase MonticuloMediciones pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
	*/
   		inline MonticuloMediciones & operator=(MonticuloMediciones const &objeto)
   		{
   			if (this != &objeto)
   			{
   				for (int i = 0; i < size(); ++i)
   					getElement(i) = objeto.getElement(i);
   				_size = objeto.size();
   			}

   			return *this;
   		} 

		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

	/*! 
		\brief Escribe por pantalla los valores de los atributos de todas las mediciones
		\pre   No puede estar vacio
		\post  Ninguna
	*/
   		inline void print()
   		{
   			 int contador = 0;
   			if(isEmpty())
   			{
   				std::cout<<BIRED<<"No hay elementos introducidos en el monticulo"<<RESET<<std::endl;
   				return;
   			}
   			
			std::cout<<BIYELLOW<<"DIA - MES - AGNO  PRECIPITACIONES"<<std::endl;
   			for (int i = 0; i < size(); ++i)
   			{
   				getElement(i).escribirMedicion();
   				contador++;
  				if(contador == 30)
  				{
  					std::cin.ignore();
  					contador = 0;
  				}
  			}
   		}
	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
