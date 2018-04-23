/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author Alejandro Reyes Jimenez
  \date   02/04/18
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{
    /*!
    \brief  Menu del programa
    \note   Función en el cpp
    \return None
    */
  int menu();

	///////////////////////////////////////////////////////////////////

    /*!
    \brief  Comprueba que hay municipios en la provincia
    \note   Función en el cpp
    \param  provincia : tipo provincia donde comprobaremos
    \return None
    */
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

    /*!
    \brief  Carga los datos desde un fichero
    \note   Función en el cpp
    \note	El fichero tiene que estar normalizado
    \param  provincia : tipo provincia donde guardaremos los datos
    \return None
    */
	void cargarProvincia(ed::Provincia & provincia);

    /*!
    \brief  Graba los datos de la clase en un fichero
    \note   Función en el cpp
    \note	El fichero tiene que estar normalizado
    \param  provincia : tipo provincia de donde sacaremos los datos
    \return None
    */
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

    /*!
    \brief  Muestra los datos de la provincia por pantalla
    \note   Función en el cpp
    \param  provincia : tipo provincia de donde mostraremos los datos
    \return None
    */
	void consultarDatosDeProvincia(ed::Provincia & provincia);

    /*!
    \brief  
    \note   Función en el cpp
    \note	El fichero tiene que estar normalizado
    \param  provincia : tipo provincia donde guardaremos los datos
    \return None
    */
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

    /*!
    \brief  Modifica los datos de provincia
    \note   Función en el cpp
    \param  provincia : tipo provincia de donde modificaremos los datos
    \return None
    */
	void modificarDatosDeProvincia(ed::Provincia & provincia);

    /*!
    \brief  Borra todos los municipios de la provincia
    \note   Función en el cpp
    \note	La lista tiene que quedar vacia despues de esta fn
    \param  provincia : tipo provincia de donde borraremos los municipios
    \return None
    */
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

    /*!
    \brief  Comprueba si existe un municipio determinado en la provincia
    \note   Función en el cpp
    \param  provincia : tipo provincia de donde comprobaremos los datos
    \return None
    */
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

    /*!
    \brief  Inserta un municipio en la lista de la provincia
    \note   Función en el cpp
    \note	Tiene que haber un elemento o mas despues de esta fn
    \param  provincia : tipo provincia donde insertaremos el municipio
    \return None
    */
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

    /*!
    \brief  Borra un municipio pedido por teclado de la provincia
    \note   Función en el cpp
    \pre	Tiene que haber al menos un elemento
    \param  provincia : tipo provincia de donde borraremos el municipio
    \return None
    */
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

