
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*! 
		\brief   Recibe tres vectores y los rellena por datos introducidos por teclado
		\warning None
		\note    Funcion no inline
		\param   v, u, w: vectores3D para rellenar
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*! 
		\brief   Recibe tres vectores y los imprime por pantalla
		\warning None
		\note    Funcion no inline
		\param   v, u, w: vectores3D para imprimir
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);


	/*! 
		\brief   Observadores de los vectores
		\warning None
		\note    Funcion no inline
		\param   v, u, w: vectores3D para trabajar
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);


	/*! 
		\brief   Llama a las funciones modifcadoras
		\warning None
		\note    Funcion no inline
		\param   v, u: vectores3D para trabajar
		\param   k: double 
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);


	/*! 
		\brief   Muestra por pantalla de manera visual el producto escalar
		\warning None
		\note    Funcion no inline
		\param   v, u: vectores3D para trabajar
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 


	/*! 
		\brief   Muestra por pantalla de manera visual el producto vectorial
		\warning None
		\note    Funcion no inline
		\param   v, u: vectores3D para trabajar
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief   Muestra por pantalla de manera visual el producto mixto
		\warning None
		\note    Funcion no inline
		\param   v, u, w : vectores3D para trabajar
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*! 
		\brief   Trabaja con los operadores 
		\warning None
		\note    Funcion no inline
		\param   v, u ,w: vectores3D para trabajar
		\param   k: double
		\return  None
		\pre     Ninguna
		\post    Ninguna
	*/
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);



} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

