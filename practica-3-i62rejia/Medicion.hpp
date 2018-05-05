/*! 
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica 
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida 
#include <iostream>
#include "macros.hpp"

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Definición de la clase Fecha
#include "Fecha.hpp"
#include <cstdlib>

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion 
class Medicion
{
  //! \name Atributos privados de la clase Medicion
   private: 

   	ed::Fecha _fecha;	//!< Atributo de la clase fecha
   	double _precipitacion_de_lluvia;	//!< Cantidad de lluvia tipo double

   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion

	/*! 
		\brief     Constructor que crea una medicion
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   Los parámetros tienen valores por defecto
		\param     fecha: fecha en el calendario; valor por defecto: 1,1,1
		\param     precipitacion: cantidad de lluvia; valor por defecto: 0.0
		\pre       Ninguna
		\post      La fecha y precipitacion creadas deben ser iguales a las recibidas
		\sa        setDia, setMes(), setAgno(), esCorrecta
	*/
   	inline Medicion(Fecha fecha = Fecha(1,1,1), double precipitacion= 0.0)
   	{
   		_fecha = fecha;
   		_precipitacion_de_lluvia = precipitacion;

   		#ifndef NDEBUG
   			assert(getFecha() == fecha);
   			assert((abs(getPrecipitacion() - precipitacion)) < COTA_ERROR);
   		#endif
   	}

	/*! 
		\brief     Constructor de "copia" que crea una medicion a partir de otra medicion
		\attention Función sobrecargada        
		\note      Función inline
		\param     medicion: objeto de la clase Medicion utilizado para proporcionar los valores iniciales de la nueva medicion
		\post      Los atributos _fecha y precipitacion_de_lluvia deben tener los valores de los atributos del objeto pasado como argumento
		\sa        getFecha(), getPrecipitacion()
	*/
   	inline Medicion(Medicion const &medicion)
   	{
   		_fecha = medicion.getFecha();
   		_precipitacion_de_lluvia = medicion.getPrecipitacion();

   		#ifndef NDEBUG
   			assert(getFecha() == medicion.getFecha());
   			assert((abs(getPrecipitacion() - medicion.getPrecipitacion())) < COTA_ERROR);
   		#endif
   	}

	//! \name Observadores: funciones de consulta de la clase Medicion

	/*! 
		\brief   Función que devuelve una fecha
		\attention Se utiliza el modificador const en la definición de la función 
		\note    Función inline
		\return  Valor del atributo que representa la fecha (tipo Fecha)
		\pre     Ninguna
		\post    Ninguna
	*/
	inline ed::Fecha getFecha() const
	{
		return _fecha;
	}

	/*! 
		\brief   Función que devuelve una precipitacion
		\attention Se utiliza el modificador const en la definición de la función 
		\note    Función inline
		\return  Valor del atributo que representa la fecha (tipo Fecha)
		\pre     Ninguna
		\post    Ninguna
	*/

	inline double getPrecipitacion() const
	{
		return _precipitacion_de_lluvia;
	}

	//! \name Funciones de modificación de la clase Medicion

	/*! 
		\brief Función que asigna un nuevo valor a un objeto Fecha
		\note  Función inline
		\param fecha: nuevo valor de la fecha
		\pre   ninguna
		\post  El atributo _fecha de Fecha debe tener el valor "fecha" 
		\sa    setPrecipitacion()
	*/
	inline void setFecha(ed::Fecha fecha)
	{
		_fecha = fecha; //Esta sobrecargado

		#ifndef NDEBUG
			assert(getFecha() == fecha);
		#endif
	}

	/*! 
		\brief Función que asigna un nuevo valor a la precipitacion
		\note  Función inline
		\param precipitacion: nuevo valor de la precipitacion de una medicion
		\pre   precipitacion recibida > 0.0
		\post  El atributo precipitacion_de_lluvia de Medicion debe tener el valor "precipitacion" 
		\sa    setDia, setAgno
	*/
	inline void setPrecipitacion(const double &precipitacion)
	{
		#ifndef NDEBUG
			assert(precipitacion >= 0.0);
		#endif

		_precipitacion_de_lluvia = precipitacion;

		#ifndef NDEBUG
			assert((abs(getPrecipitacion() - precipitacion)) < COTA_ERROR);
		#endif
	}

	//! \name Operadores
  
	/*! 
		\brief     Operador de igualdad: compara si dos mediciones son iguales
		\attention Se sobrecarga el operador de asignación "=="
		\note      Función inline
		\param     medicion: Medicion pasada como referencia constante
		\pre       Ninguna
		\post      Ninguna
	*/
	inline bool operator == (Medicion const &medicion) const
	{
		if(medicion.getFecha() == getFecha())
			return true;
		return false;
	}

	/*! 
		\brief     Operador de asignación: operador que "copia" una medicion en otra medicion
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\warning   Se requiere que las funciones de acceso getPrecipitacion y getFecha tengan el modificador const
		\param     medicion: objeto de la clase Medicion pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
		\pre	   El objeto representa una medicion correcta
	*/
	inline Medicion & operator=(Medicion const &medicion)
	{
		if(this != &medicion)
		{
			setFecha(medicion.getFecha());
			setPrecipitacion(medicion.getPrecipitacion());

			#ifndef NDEBUG
				assert(getFecha() == medicion.getFecha());
				assert((abs(getPrecipitacion() - medicion.getPrecipitacion())) < COTA_ERROR);
			#endif
		}

		return *this;
	}
	//! \name Funciones de lectura y escritura de la clase Medicion

	/*! 
		\brief   Lee desde el teclado los nuevos valores de los atributos de una medicion
		\warning Se deben teclear números
		\note	 Funcion inline
		\pre     ninguna
		\post    ninguna
	*/
	inline void leerMedicion()
	{
		double prep;
		/*int dia, mes, agno;
		std::cout<<BIYELLOW<<"Introduzca dia"<<std::endl;
		std::cin>>dia;
		std::cout<<BIYELLOW<<"Introduzca mes"<<std::endl;
		std::cin>>mes;
		std::cout<<BIYELLOW<<"Introduzca agno"<<std::endl;
		std::cin>>agno;*/
		ed::Fecha *aux = new ed::Fecha();
		aux->leerFecha();
		while(!aux->esCorrecta())
		{
			std::cout << CLEAR_SCREEN;
			std::cout<<BIRED<<"Fecha incorrecta, introduzca una fecha valida"<<RESET<<std::endl;
			aux->leerFecha();
		}
		std::cout<<BIYELLOW<<"Introduzca precipitacion de lluvia"<<RESET<<std::endl;
		std::cin>>prep;
		while(prep < 0.0)
		{
			std::cout<<CLEAR_SCREEN;
			std::cout<<BIRED<<"Precipitacion incorrecta, introduzca una precipitacion valida"<<RESET<<std::endl;
			std::cout<<CYAN<<"Precipitacion --> "<<RESET;
			std::cin>>prep;
		}
		setFecha(*aux);
		setPrecipitacion(prep);
	}

	/*! 
		\brief Escribe por pantalla los valores de los atributos de una medicion
		\pre   Ninguna
		\post  Ninguna
	*/
	inline void escribirMedicion()
	{
		std::cout<<BIGREEN<<getFecha().getDia()<<"-"<<getFecha().getMes()<<"-"<<getFecha().getAgno()<<" "<<getPrecipitacion()<<std::endl;
	}


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

    /*!
  		\brief     Sobrecarga del operador de entrada o lectura ">>"
		\param     stream Flujo de entrada
		\param     medicion: pasada como referencia 
		\pre       Ninguna
		\post      Ninguna
		\sa        operator<<()
    */
	istream &operator>>(istream &stream, Medicion &medicion);

    /*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
				   \n Se escribe la medicion por pantalla con el formato (d)d-(m)m--aaaa precipitacion
		\param     stream Flujo de salida
		\param     medicion: pasada como referencia constante
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>()
    */
	ostream &operator<<(ostream &stream, Medicion const &medicion);


} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
