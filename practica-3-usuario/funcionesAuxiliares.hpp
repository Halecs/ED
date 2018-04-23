/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Alejandro Reyes Jimenez
  \date  19/04/2018
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include "MonticuloMediciones.hpp"


namespace ed
{

    /*!
    \brief  Menu del programa
    \note   Función en el cpp
    \return None
    */
	int menu();

    /*!
    \brief  Carga los datos de la clase desde un fichero
    \note   Función en el cpp
    \note	El fichero tiene que estar normalizado
    \param  monticulo : tipo MonticuloMediciones de donde sacaremos los datos
    \param	nombreFichero: tipo string, nombre del fichero de donde cargar
    \return None
    */
	void cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo); 

    /*!
    \brief  Graba los datos de la clase en un fichero
    \note   Función en el cpp
    \note	El fichero tiene que estar normalizado
    \param  monticulo : tipo MonticuloMediciones donde guardaremos los datos
    \param	nombreFichero: tipo string, nombre del fichero de donde cargar
    \return None
    */
	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo); 


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_
#endif

