/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author  Alejandro Reyes Jimenez
	\date    02/04/18
	\version 1.0

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//!	\name Constructor
    /*!
          \brief Constructor de la clase provincia
          \note Funcion inline
          \param nombre : Nombre de la provincia
          \param codigo : Codigo de la provincia
          \return No devuelve nada
    */
  	inline Provincia(std::string nombre="", int codigo = 0)
  	{
  		setNombre(nombre);
  		setCodigo(codigo);

  		#ifndef NDEBUG
  			assert(getNombre() == nombre);
  			assert(getCodigo() == codigo);
  			assert(hayMunicipios() == false);
  		#endif
  	}

	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores
    /*!
    \brief  Observador de nombre de la provincia
    \note   Función inline
    \note   Función de tipo "const": no puede modificar al objeto actual
    \return Nombre de la provincia
    */
  	inline std::string getNombre() const
  	{
  		return _nombre;
  	}

    /*!
    \brief  Observador codigo de la Provincia
    \note   Función inline
    \note   Función de tipo "const": no puede modificar al objeto actual
    \return Codigo de la provincia
    */
  	inline int getCodigo() const
  	{
  		return _codigo;
  	}

    /*!
    \brief  Comprueba si hay municipios en la provincia
    \note   Función inline
    \note   Función de tipo "const": no puede modificar al objeto actual
    \return True/False
    */
  	inline bool hayMunicipios() const 
  	{
  		if(_listaMunicipios.isEmpty() == true)
  			return false;
  		else
  			return true;
  	}

    /*!
    \brief  Cuenta cuantos municipios 
    \note   Función inline
    \note   Función de tipo "const": no puede modificar al objeto actual
    \return Numero de municipios
    */
  	inline int getNumeroMunicipios() const
  	{
  		 return _listaMunicipios.nItems();
  	}

    /*!
    \brief  Comprueba si existe un minicipio 
    \note   Función inline
    \param  nombre : Nombre del municipio
    \return true/false
    */
    inline bool existeMunicipio(std::string nombre)
    {
      ed::Municipio aux(nombre);
      return _listaMunicipios.find(aux);
    }

    /*!
    \brief  Devuelve el municipio que concuerde con el nombre
    \note   Función inline
    \param  nombre : Nombre del municipio
    \return Nombre de la provincia
    */
    inline ed::Municipio getMunicipio(std::string nombre)
    {
      #ifndef NBDEBUG
        assert(existeMunicipio(nombre) == true);
      #endif
        return _listaMunicipios.getCurrentItem();
    }

    /*!
    \brief  Busca el numero total de hombres de la provincia
    \note   Función en el cpp
    \return Numero de hombres
    */
    int getTotalHombres(); 

    /*!
    \brief  Calcula el numero total de mujeres de la provincia
    \note   Función en el cpp
    \return Numero de mujeres
    */
    int getTotalMujeres();

    /*!
    \brief  Calcula el numero total de habitantes en la provincia
    \note   Función inline
    \return Numero de hombres
    */
    inline int getTotalHabitantes()
    {
      return getTotalHombres()+getTotalMujeres();
    }

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

    /*!
    \brief  Modifica el nombre de la provincia
    \note   Función inline
    \return None
    */
  	inline void setNombre(std::string cadena){
  		_nombre = cadena;

  		#ifndef NDEBUG
  			assert(getNombre() == cadena);
  		#endif
  	}

    /*!
    \brief  Modifica el codigo de la provincia
    \note   Función inline
    \param  numero : tipo entero
    \return None
    */
  	inline void setCodigo(int numero){
  		_codigo = numero;

  		#ifndef NDEBUG
  			assert(getCodigo() == numero);
  		#endif
  	}

    /*!
    \brief  Inserta un municipio en la provincia
    \note   Función inline
    \param  municipio : clase municipio a insertar en la lista
    \return None
    */
    inline void insertarMunicipio(ed::Municipio const & municipio)
    {
      #ifndef NDEBUG
        assert(existeMunicipio(municipio.getNombre()) == false);
      #endif
      int old = getNumeroMunicipios();
        _listaMunicipios.insert(municipio);
      #ifndef NDEBUG
        assert(existeMunicipio(municipio.getNombre()) == true);
        assert(getNumeroMunicipios() == old + 1);
      #endif
    }

    /*!
    \brief  Borra un municipio de la provincia
    \note   Función inline
    \param  cadena : string que representa el nombre del municipio a borrar
    \return None
    */
    inline void borrarMunicipio(std::string cadena)
    {
      #ifndef NDEBUG
        assert(existeMunicipio(cadena) == true);
      #endif
      int old = getNumeroMunicipios();
      if(existeMunicipio(cadena))
          _listaMunicipios.remove();
      #ifndef NDEBUG
        assert(existeMunicipio(cadena) == false);
        assert(getNumeroMunicipios() == old - 1);
      #endif
    }

    /*!
    \brief  Borra todos los municipios
    \note   Función inline
    \return None
    */
    inline void borrarTodosLosMunicipios()
    {
      _listaMunicipios.removeAll();
      #ifndef NDEBUG
        assert(hayMunicipios() == false);
      #endif
    }

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia
    /*!
    \brief  Muestra por pantalla todos los municipios
    \note   Función en el cpp
    \return None
    */
    void escribirMunicipios();


	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros
    /*!
    \brief  Guarda en un fichero la provincia con sus municipios
    \note   Función en el cpp
    \param  nombre : string que representa el nombre del fichero
    \return True/False
    */
  bool grabarFichero(std::string nombre);

    /*!
    \brief  Inserta los datos de un fichero a una clase Provincia
    \note   Función en el cpp
    \param  nombre : string que representa el nombre del fichero
    \return True/False
    */
  bool cargarFichero(std::string nombre);



}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
