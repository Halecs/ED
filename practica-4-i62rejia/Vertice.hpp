
#ifndef _VERTICEHPP_
#define _VERTICEHPP_

#define COTA_ERROR   1.0e-6
// Entrada y salida 
#include <iostream>
#include "macros.hpp"

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cstdlib>
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

/*!	
\namespace ed
\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed {

class Vertice
{
	private:
		float x_;
		float y_;
		int label_;

	public:
		Vertice();
		inline const & float getDataX(){ return x_;};
		inline const & float getDataY(){return y_;};
		inline const & int getLabel(){return label_;};
/*!	
	\brief  Método público que permite modificar el campo informativo del Vertice
	\note   Función inline
	\param  x: nuevo valor del campo x
	\param  y: nuevo valor del campo y
	\pre    Ninguna
	\post   El campo informativo del Vertice es igual al parámetro pasado como argumento
	\return void
*/
		inline void setData(float x, float y)
		{
			x_ = x;
			y_ = y;

			#ifndef NDEBUG
				assert((abs(x_ - x)) < COTA_ERROR);
				assert((abs(y_ - y)) < COTA_ERROR);
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
	\note   Función codificada en el fichero cpp
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
	\note      Función codificada en el fichero cpp
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
};





} //end namespace ed

#endif