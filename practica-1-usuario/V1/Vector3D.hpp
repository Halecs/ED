/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>
#include<cstdlib>
// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private: 

	double x_;
	double y_;
	double z_;


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

	/*! 
		\brief     Constructor que crea un Vector3D por defecto
		\attention Funcion sobrecargada        
		\note      Funcion inline
	 	\warning   None
		\param     None
		\pre       Ninguna
		\post      (this->get1() == x) and (this->get2() == y) and (this->get3() == z)
	*/
	inline Vector3D(){
		this->set1(0);
		this->set2(0);
		this->set3(0);
		#ifndef NDEBUG
			// Se comprueba la postcondicion
			assert( (this->get1() == 0) and (this->get2() == 0) and (this->get3() == 0));
		#endif //NDEBUG
	}

	/*! 
		\brief     Constructor que crea un Vector3D a partir de tres puntos
		\attention Funcion sobrecargada        
		\note      Funcion inline
	 	\warning   Los parametros no tienen valores por defecto
		\param     v1: primer punto para el constructor
		\param     v2: segundo punto para el constructor
		\pre       Ninguna
		\post      (this->get1() == v3) and (this->get2() == v2) and (this->get3() == v3)
	*/

	inline Vector3D(double v1, double v2, double v3) {
		this->set1(v1);
		this->set2(v2);
		this->set3(v3);
		#ifndef NDEBUG
			assert((this->get1() == v1) and (this->get2() == v2) and (this->get3() == v3));
		#endif //NDEBUG
	}

	/*! 
		\brief     Constructor de copia que crea un Vector3D a partir de otro
		\attention Funcion sobrecargada        
		\note      Funcion inline
	 	\warning   Los parametros no tienen valores por defecto
		\param     v: Vector3D a copiar
		\pre       Ninguna
		\post      (this->get1() == v,get1()) and (this->get2() == v.get2()) and (this->get3() == v.get3())
	*/

	inline Vector3D(Vector3D const &v){
		this->set1(v.get1());
		this->set2(v.get2());
		this->set3(v.get3());
		#ifndef NDEBUG
			assert((this->get1() == v.get1()) and (this->get2() == v.get2()) and (this->get3() == v.get3()));
		#endif //NDEBUG
	}

	//! \name Observadores: funciones de consulta de Vector3D
	/*! 
		\brief   Funcion que devuelve la coordenada x del vector
		\warning Se utiliza el modificador const 
		\note    Funcion inline
		\return  Componente "x" del Vector3D (tipo double)
		\pre     Ninguna
		\post    Ninguna
	*/
	inline double get1() const{
		return x_;
	}

	/*! 
		\brief   Funcion que devuelve la coordenada y del vector
		\warning Se utiliza el modificador const 
		\note    Funcion inline
		\return  Componente "y" del Vector3D (tipo double)
		\pre     Ninguna
		\post    Ninguna
	*/
	inline double get2() const {
		return y_;
	}

	/*! 
		\brief   Funcion que devuelve la coordenada z del vector
		\warning Se utiliza el modificador const 
		\note    Funcion inline
		\return  Componente "z" del Vector3D (tipo double)
		\pre     Ninguna
		\post    Ninguna
	*/
	inline double get3() const {
		return z_;
	}

	//! \name Modificadores: funciones de modificación de Vector3D
	/*! 
		\brief   Funcion que asgina un valor a la coordenada x del vector
		\warning Se utiliza el modificador const 
		\param   x: dato a asignar
		\note    Funcion inline
		\return  None
		\pre     Ninguna
		\post    get1() == x
	*/
	inline void set1(double x){
		x_ = x;
		#ifndef NDEBUG
			// Se comprueba la postcondicion
			assert( (abs(this->get1() - x )) < COTA_ERROR);
		#endif //NDEBUG
	}

	/*! 
		\brief   Funcion que asgina un valor a la coordenada y del vector
		\warning Se utiliza el modificador const
		\param     y: dato a asignar
		\note    Funcion inline
		\return  None
		\pre     Ninguna
		\post    get2() == y
	*/
	inline void set2(double y){
		y_ = y;
		#ifndef NDEBUG
			assert((abs(this->get2() - y)) < COTA_ERROR);
		#endif //NDEBUG
	}

	/*! 
		\brief   Funcion que asgina un valor a la coordenada z del vector
		\warning Se utiliza el modificador const 
		\param     z: dato a asignar
		\note    Funcion inline
		\return  None
		\pre     Ninguna
		\post    get3() == z
	*/
	inline void set3(double z){
		z_ = z;
		#ifndef NDEBUG
			assert((abs(this->get3() - z)) < COTA_ERROR);
		#endif //NDEBUG
	}

	/*! 
		\brief   Funcion que calcula el modulo de un vector3D
		\warning Se utiliza el modificador const 
		\note    Funcion no inline
		\return  variable tipo dobule, modulo del vector
		\pre     Ninguna
		\post    valorDevuelto == sqrt ( get1()*get1() + get2()*get2() + get3()*get3()
)
	*/
	double modulo() const;

	/*! 
		\brief   Funcion que calcula el angulo entre dos vectores
		\warning Se utiliza el modificador const 
		\param     v: Vector3D con el que hacer el angulo
		\note    Funcion no inline
		\return  angulo entre los dos vectores, tipo double
		\pre     Ninguna
		\post    valorDevuelto == acos( dotProduct(v) / (modulo() * v.modulo()) )
	*/
	double angulo(Vector3D v) const;

	/*! 
		\brief   Funcion que calcula el angulo alfa del vector3D
		\warning Se utiliza el modificador const 
		\note    Funcion no inline
		\return  Angulo alfa del vector3D (tipo double)
		\pre     modulo()>0
		\post    valorDevuelto == angulo(Vector3D(1,0,0))
	*/
	double alfa() const;

	/*! 
		\brief   Funcion que calcula el angulo beta del vector3D
		\warning Se utiliza el modificador const 
		\note    Funcion no inline
		\return  Angulo beta del vector3D (tipo double)
		\pre     modulo()>0
		\post    valorDevuelto == angulo(Vector3D(0,1,0))
	*/
	double beta() const;

	/*! 
		\brief   Funcion que calcula el angulo gamma del vector3D
		\warning Se utiliza el modificador const 
		\note    Funcion no inline
		\return  Angulo gamma del vector3D (tipo double)
		\pre     modulo()>0
		\post    valorDevuelto == angulo(Vector3D(0,0,1))
	*/
	double gamma() const;

	/*! 
		\brief   Funcion que calcula el producto escalar de dos vector3D
		\warning Se utiliza el modificador const 
		\param     v: Vector3D con el que calcular el producto
		\note    Funcion no inline
		\return  Producto escalar (tipo double)
		\pre     None
		\post    valorDevuelto == get1() * v.get1()+ get2() * v.get2() + get3() * v.get3()
	*/
	double dotProduct(Vector3D v) const;

	/*! 
		\brief   Funcion que calcula el producto vectorial de dos vector3D
		\warning Se utiliza el modificador const 
		\param     v: Vector3D con el que calcular el producto
		\note    Funcion no inline
		\return  Vector3D resultado
		\pre     None
		\post   valorDevuelto.modulo() == modulo() * v.modulo()* sin(angulo(v))
		\post 	dotProduct(valorDevuelto) == 0 and v.dotProduct(valorDevuelto) == 0
	*/
	Vector3D crossProduct(Vector3D v) const;

	/*! 
		\brief   Funcion que calcula el producto mixto de dos vector3D
		\warning Se utiliza el modificador const 
		\param     v: Vector3D con el que calcular el producto
		\param 	   w: Vector3D con el que calcular el producto
		\note    Funcion no inline
		\return  Producto escalar (tipo double)
		\pre     None
		\post    valorDevuelto == dotProduct(crossProduct(v,w))
	*/
	double productoMixto(Vector3D v,Vector3D sw) const;
	/////////////////////////////////////
	/*! 
		\brief   Funcion que suma un numero a todas las coordenadas del Vector3D
		\param    k: numero a sumar
		\note    Funcion no inline
		\return  None
		\pre     None
		\post   (get1() == old.get1() + k) and (get2() == old.get2() + k) and (get3() == old.get3() + k)
	*/
	void sumConst(double k);

	/*! 
		\brief   Modifica el vector sumando a cada componente la componente equivalente de otro vector.
		\param    v: Vector3D 
		\note    Funcion no inline
		\return  None
		\pre     None
		\post   (get1() == old.get1() + v.get1()) and (get2() == old.get2() + v.get2()) and (get3() == old.get3() + v.get3())
	*/
	void sumVect(Vector3D v);

	/*! 
		\brief   Modifica el vector multiplicando cada componente por una constante: escala el vector
		\param    k: double 
		\note    Funcion no inline
		\return  None
		\pre     None
		\post   (get1() == old.get1() * k) and (get2() == old.get2() * k) and (get3() == old.get3() * k)
	*/
	void multConst(double k);

	/*! 
		\brief   Modifica el vector multiplicando, por separado, cada componente por la componente de otro vector.
		\param    v: Vector3D 
		\note    Funcion no inline
		\return  None
		\pre     None
		\post   (get1() == old.get1() * k) and (get2() == old.get2() * k) and (get3() == old.get3() * k)
	*/
	void multVect(Vector3D v);

    //! \name Operadores de la clase
   

	/*! 
		\brief     Operador de asignacion
		\attention Se sobrecarga el operador de asignacion "="
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     v: objeto de tipo Vector3D pasado como referencia constante
		\return    Vector3D igual al recibido
		\pre       El Vector3D v debe er diferente del vector actual
		\post      El vector actual debe ser igual al vector pasado como argumento
				   \n (this->getX() == v.getX()) and (this->getY() == v.getY())
		\sa        get1(), get2(),get3(), set1(), set2(), set3(), operator==()
	*/
    Vector3D & operator=(Vector3D const &objeto);

	/*! 
		\brief     Operador de igualdad
		\attention Se sobrecarga el operador de igualdad
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     v: objeto de tipo Vector3D pasado como referencia constante
		\return    booleana 
		\pre       None
		\post      valorDevuelto == (get1() == v.get1()) and (get2() == v.get2() )and (get3() == v.get3())
		\sa        get1(), get2(),get3(), set1(), set2(), set3(), operator==()
	*/
	bool operator == (Vector3D const &objeto) const;

	/*! 
		\brief     Devuelve otro vector que es la suma del vector actual y el vector pasado como parámetro.
		\attention Se sobrecarga el operador de suma
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     v: objeto de tipo Vector3D pasado como referencia constante
		\return    Vector3D que será la suma de los vectores 
		\pre       None
		\post      (valorDevuelto.get1() == get1() + v.get1()) and (valorDevuelto.get2() == get2() + v.get2()) and (valorDevuelto.get3() == get3() + v.get3())
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
	Vector3D & operator+(Vector3D const &objeto)const;

	/*! 
		\brief     Devuelve otro vector que es una copia del vector actual.
		\attention Se sobrecarga el operador de suma
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     None
		\return    Vector3D  
		\pre       None
		\post      (valorDevuelto.get1() == get1() + v.get1()) and (valorDevuelto.get2() == get2() + v.get2()) and (valorDevuelto.get3() == get3() + v.get3())
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
	Vector3D & operator+()const;

	/*! 
		\brief     Operador resta binario que realiza la operacion con dos vectores
		\attention Se sobrecarga el operador de resta
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     v: Vector3D
		\return    Devuelve otro vector que es la diferencia entre el vector actual y el vector pasado como parámetro.
		\pre       None
		\post      (valorDevuelto.get1() == get1() - v.get1()) and (valorDevuelto.get2() == get2() - v.get2()) and (valorDevuelto.get3() == get3() - v.get3())
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
	Vector3D & operator-(Vector3D const &objeto)const;

	/*! 
		\brief     Operador resta unario 
		\attention Se sobrecarga el operador de resta
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     None
		\return    Devuelve otro vector que es el opuesto al vector actual.
		\pre       None
		\post      (valorDevuelto.get1() == - get1()) and (valorDevuelto.get2() == - get2()) and (valorDevuelto.get3() == - get3())
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
	Vector3D & operator-()const;

	/*! 
		\brief     Operador producto
		\attention Se sobrecarga el operador de producto
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     k: double 
		\return    Devuelve otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector actual
		\pre       None
		\post      (valorDevuelto.get1() == - get1()) and (valorDevuelto.get2() == - get2()) and (valorDevuelto.get3() == - get3())
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
 	Vector3D & operator*(double const k)const;

	/*! 
		\brief     Operador producto escalar de dos vectores
		\attention Se sobrecarga el operador de producto
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     v: Vector3D
		\return    Devuelve el producto escalar de dos vectores.
		\post      valorDevuelto == get1() * v.get1() + get2() * v.get2() + get3() * v.get3()
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
 	double  operator*(Vector3D const &v)const;

	/*! 
		\brief     Operador producto vectorial de dos vectores
		\attention Se sobrecarga el operador de producto
		\note      Funcion no inline
		\warning   Se requiere que las funciones de acceso get tengan el modificador const
		\param     v: Vector3D
		\return    Devuelve el producto escalar de dos vectores.
		\post      valorDevuelto == dotProduct(crossProduct(v,w))
		\sa        get1(), get2(),get3(), set1(), set2(), set3()
	*/
	Vector3D operator^(Vector3D const &v)const;


	//! \name Funciones lectura y escritura de la clase Vector3D

	/*! 
		\brief   Asigna a un vector3D las coordenadas "x" e "y" e "z" leidas desde teclado
		\warning Se deben teclear numeros
		\pre     None
		\post    Los atributos _x e _y e z_ de Vertice2D deben tener valores numericos
		\sa      set1(), set2()
	*/
	void leerVector3D();

	/*! 
		\brief Escribe por pantalla las coordenadas de un vector3D de la forma (x,y,z)
		\pre   Ninguna
		\post  Ninguna
		\sa    get1(), get2()
	*/
	void escribirVector3D()const;

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
    Vector3D & operator* (double k, Vector3D const & objeto);


	/*!
  		\brief      Sobrecarga del operador de entrada o lectura ">>"
					\n Lee las coordenadas del vwctor separadas por espacios
		\attention  Funcion amiga de la clase Vertice3D
		\param      stream: flujo de entrada
		\param      v Vector3D al que se le van a asignar nuevos valores.
		\pre        Ninguna
		\post       Ninguna
		\sa         operator<<
    */
    istream &operator>>(istream &stream, Vector3D &objeto);

    /*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
				   \n Escribe por pantalla las coordenadas de un vector3D de la forma (x,y,z)
		\attention Funcion amiga de la clase Vector3D
		\param     stream: flujo de salida
		\param     v: Vector3D del cual se van a escribir sus coordenadas por pantalla
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>
    */ 
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
