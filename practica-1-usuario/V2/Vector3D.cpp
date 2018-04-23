/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"


// using namespace std;

// OBSERVADORES

double ed::Vector3D::modulo()const{
	double modulo = sqrt(get1()*get1()+get2()*get2()+get3()*get3());

	#ifndef NDEBUG
		assert(abs(modulo - sqrt ( get1()*get1()
		+ get2()*get2()
		+ get3()*get3())) < COTA_ERROR);
	#endif //NDEBUG

	return modulo;
}

double ed::Vector3D::angulo(Vector3D v) const{
	#ifndef NDEBUG
		assert((modulo()*v.modulo()) > 0);
	#endif //NDEBUG

	double angulo = acos(((get1()*v.get1()) + (get2()*v.get2()) + (get3()*v.get3())) / (modulo()* v.modulo()));

	#ifndef NDEBUG
		assert(abs(angulo - (acos( dotProduct(v) / (modulo() * v.modulo()) ))) < COTA_ERROR);
	#endif //NDEBUG

	return angulo;
}

double ed::Vector3D::alfa() const {
	#ifndef NDEBUG
		assert((modulo()) > 0);
	#endif //NDEBUG

	double alfa = angulo(Vector3D(1,0,0));

	#ifndef NDEBUG
		assert(abs(alfa - angulo(Vector3D(1,0,0))) < COTA_ERROR);
	#endif //NDEBUG

	return alfa;
}

double ed::Vector3D::beta() const{
	#ifndef NDEBUG
		assert((modulo()) > 0);
	#endif //NDEBUG

	double beta = angulo(Vector3D(0,1,0));

	#ifndef NDEBUG
		assert(abs(beta - angulo(Vector3D(0,1,0))) < COTA_ERROR);
	#endif //NDEBUG

	return beta;
}

double ed::Vector3D::gamma() const{
	#ifndef NDEBUG
		assert((modulo()) > 0);
	#endif //NDEBUG

	double gamma = angulo(Vector3D(0,0,1));

	#ifndef NDEBUG
		assert(abs(gamma - angulo(Vector3D(0,0,1))) < COTA_ERROR);
	#endif //NDEBUG
	return gamma;
}

double ed::Vector3D::dotProduct(ed::Vector3D v) const{
	double escalar = get1()*v.get1() + get2()*v.get2()+
						get3()*v.get3();

	#ifndef NDEBUG
		assert(std::abs(escalar - (get1()*v.get1() + get2()*v.get2()+
						get3()*v.get3()))<= COTA_ERROR);
	#endif 
	return escalar;
}

ed::Vector3D ed::Vector3D::crossProduct(Vector3D v) const{

	#ifndef NDEBUG
		assert(angulo(v) > 0.0);
		assert(modulo()  > 0.0);
		assert(v.modulo() > 0.0);
	#endif
		
	ed::Vector3D vectorial;
	vectorial.set1(get2()*v.get3() - get3()*v.get2());  
	vectorial.set2(-get1()*v.get3() + get3()*v.get1());
	vectorial.set3(get1()*v.get2() - get2()* v.get1());

	#ifndef NDEBUG
		assert(abs(dotProduct(vectorial)) < COTA_ERROR); //perpendiculares
		assert(abs(v.dotProduct(vectorial)) < COTA_ERROR); //perpendiculares
		assert(abs(vectorial.modulo() - (modulo()*v.modulo()*sin(angulo(v)))) < COTA_ERROR);
	#endif
	return vectorial;
}

double ed::Vector3D::productoMixto(ed::Vector3D v, ed::Vector3D w) const{
	double mixto = dotProduct(v.crossProduct(w));

	#ifndef NDEBUG
		assert(abs(mixto - (dotProduct(v.crossProduct(w)))) < COTA_ERROR);
	#endif
	return mixto;
}


////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Vector3D::sumConst(double k){
	// ed::Vector3D old = *this;
	ed::Vector3D *old = new ed::Vector3D(*this);

	set1(get1()+k);
	set2(get2()+k);
	set3(get3()+k);

	#ifndef NDEBUG
		assert((abs(get1() - (old->get1()+k)) < COTA_ERROR) and 
			(abs(get2() - (old->get2()+k)) < COTA_ERROR) and 
			(abs(get3() - (old->get3()+k)) < COTA_ERROR));
	#endif
}

void ed::Vector3D::sumVect(ed::Vector3D v){
	ed::Vector3D old = *this;
	set1(get1()+v.get1());
	set2(get2()+v.get2());
	set3(get3()+v.get3());

	#ifndef NDEBUG
		assert((abs(get1() - (old.get1()+v.get1())) < COTA_ERROR) and
			(abs(get2() - (old.get2()+v.get2())) < COTA_ERROR) and
			(abs(get3() - (old.get3()+v.get3())) < COTA_ERROR));
	#endif
}

void ed::Vector3D::multConst(double k){
	ed::Vector3D old = *this;
	set1(get1()*k);
	set2(get2()*k);
	set3(get3()*k);

	#ifndef NDEBUG
		assert((abs(get1() - old.get1()*k) < COTA_ERROR) and
			(abs(get2() -  old.get2()*k) < COTA_ERROR)    and
			(abs(get3() -  old.get3()*k) < COTA_ERROR));
	#endif
}

void ed::Vector3D::multVect(ed::Vector3D v){
	ed::Vector3D old = *this;
	set1(get1()*v.get1());
	set2(get2()*v.get2());
	set3(get3()*v.get3());

	#ifndef NDEBUG
		assert((abs(get1() - old.get1()*v.get1()) < COTA_ERROR) and
			(abs(get2() - old.get2()*v.get2()) < COTA_ERROR) and
			(abs(get3() - old.get3()*v.get3()) < COTA_ERROR));
	#endif
}

////////////////////////////////////////////////////////////////////////////////

// OPERADORES
ed::Vector3D & ed::Vector3D::operator=(ed::Vector3D const &objeto){
	if(this!= &objeto)
	{
		set1(objeto.get1());
		set2(objeto.get2());
		set3(objeto.get3());

		#ifndef NDEBUG
			assert((abs(get1() - objeto.get1()) < COTA_ERROR) and 
				(abs(get2() -  objeto.get2()) < COTA_ERROR) and 
				(abs(get3() -  objeto.get3()) < COTA_ERROR));
		#endif
	}
	return *this;
}

bool ed::Vector3D::operator == (ed::Vector3D const &objeto) const{ //////////mirar
 return (    (std::abs(objeto.get1() - get1()) < COTA_ERROR)
		 and (std::abs(objeto.get2() - get2()) < COTA_ERROR)
		 and (std::abs(objeto.get3() - get3()) < COTA_ERROR)
		 );
}

ed::Vector3D & ed::Vector3D::operator+(ed::Vector3D const &objeto)const
{
	ed::Vector3D old = *this;
	ed::Vector3D *vectorResultado = new ed::Vector3D(*this);

	vectorResultado->set1(get1() + objeto.get1());
	vectorResultado->set2(get2() + objeto.get2());
	vectorResultado->set3(get3() + objeto.get3());

	#ifndef NDEBUG
		assert((abs(vectorResultado->get1() - (objeto.get1() + old.get1())) < COTA_ERROR) and 
			(abs(vectorResultado->get2() - (objeto.get2() + old.get2())) < COTA_ERROR) and
			(abs(vectorResultado->get3() - (objeto.get3() + old.get3()))  < COTA_ERROR));
	#endif

	return *vectorResultado;
}

ed::Vector3D & ed::Vector3D::operator+()const
{
	ed::Vector3D *vectorResultado = new ed::Vector3D(*this);

	vectorResultado->set1(get1());
	vectorResultado->set2(get2());
	vectorResultado->set3(get3());

	#ifndef NDEBUG
		assert((abs(vectorResultado->get1() - get1()) < COTA_ERROR) and
			   (abs(vectorResultado->get2() - get2()) < COTA_ERROR) and
			   (abs(vectorResultado->get3() - get3()) < COTA_ERROR));
	#endif 
		return *vectorResultado;
}

ed::Vector3D & ed::Vector3D::operator-(ed::Vector3D const &objeto)const
{
	// ed::Vector3D old = *this;
	ed::Vector3D *vectorResultado = new ed::Vector3D(*this);

	vectorResultado->set1(get1() - objeto.get1());
	vectorResultado->set2(get2() - objeto.get2());
	vectorResultado->set3(get3() - objeto.get3());

	#ifndef NDEBUG
		assert((abs(vectorResultado->get1() - (get1() - objeto.get1())) < COTA_ERROR) and 
			(abs(vectorResultado->get2() - (get2() - objeto.get2())) < COTA_ERROR) and
			(abs(vectorResultado->get3() - (get3() - objeto.get3())) < COTA_ERROR));
	#endif
		return *vectorResultado;
}

ed::Vector3D & ed::Vector3D::operator-()const
{
	ed::Vector3D *vectorResultado = new ed::Vector3D(*this);

	vectorResultado->set1((-1)*get1());
	vectorResultado->set2((-1)*get2());
	vectorResultado->set3((-1)*get3());

	#ifndef NDEBUG
		assert((abs((get1()*(-1)) - vectorResultado->get1()) < COTA_ERROR) and
			   (abs((get2()*(-1)) - vectorResultado->get2()) < COTA_ERROR) and
			   (abs((get3()*(-1)) - vectorResultado->get3()) < COTA_ERROR));
	#endif 
	return *vectorResultado;
}

ed::Vector3D & ed::Vector3D::operator*(double const k)const
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();
	vectorResultado->set1(get1()*k);
	vectorResultado->set2(get2()*k);
	vectorResultado->set3(get3()*k);

	#ifndef NDEBUG
		assert((abs(vectorResultado->get1() - k*get1())   < COTA_ERROR) and
			   (abs(vectorResultado->get2() - k*get2())   < COTA_ERROR) and
			   (abs(vectorResultado->get3() - k*get3())   < COTA_ERROR));
	#endif 

	return *vectorResultado;
}

double ed::Vector3D::operator*(ed::Vector3D const &v)const
{
	double escalar = ((get1()*v.get1()) + (get2()*v.get2()) + (get3()*v.get3()));

	#ifndef NDEBUG
		assert(abs(escalar - ((get1()*v.get1()) + (get2()*v.get2()) + (get3()*v.get3()))) < COTA_ERROR);
	#endif 
	return escalar;
}

ed::Vector3D ed::Vector3D::operator^(ed::Vector3D const &v)const
{
	ed::Vector3D *vectorResultado = new ed::Vector3D(*this);

	vectorResultado->set1(get2()*v.get3() - get3()*v.get2());
	vectorResultado->set2(-get1()*v.get3() + get3()*v.get1());
	vectorResultado->set3(get1()*v.get2() - get2()*v.get1());

	#ifndef NDEBUG
		assert(abs(dotProduct(*vectorResultado)) < COTA_ERROR); //perpendiculares
		assert(abs(v.dotProduct(*vectorResultado)) < COTA_ERROR); //perpendiculares
		assert(abs(vectorResultado->modulo() - (modulo()*v.modulo()*sin(angulo(v)))) < COTA_ERROR);
	#endif

	return *vectorResultado;
}

////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

void ed::Vector3D::leerVector3D(){
	double aux;
	std::cout<<"Introduzca componente 1 del vector"<<std::endl;
	std::cin>>aux;
	set1(aux);
	std::cout<<"Introduzca componente 2 del vector"<<std::endl;
	std::cin>>aux;
	set2(aux);
	std::cout<<"Introduzca componente 3 del vector"<<std::endl;
	std::cin>>aux;
	set3(aux);
	std::cout<<"Vector introducido con exito"<<std::endl;
}

void ed::Vector3D::escribirVector3D()const {
	std::cout<<"Las componentes del vector son: ("<<get1()<<","
	<<get2()<<","<<get3()<<")"<<std::endl;
}

////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();
	vectorResultado->set1(objeto.get1()*k);
	vectorResultado->set2(objeto.get2()*k);
	vectorResultado->set3(objeto.get3()*k);

	#ifndef NDEBUG
		assert((abs((vectorResultado->get1() - objeto.get1()*k)) < COTA_ERROR) and
			   (abs(vectorResultado->get2() - objeto.get2()*k)   < COTA_ERROR) and
			   (abs(vectorResultado->get3() - objeto.get3()*k))  < COTA_ERROR);
	#endif 

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	std::cout<<"(";
	stream<<objeto.get1();
	stream<<",";
	stream<<objeto.get2();
	stream<<",";
	stream<<objeto.get3();
	std::cout<<")";

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  double numero;

  stream>>numero;
  objeto.set1(numero);
  stream>>numero;
  objeto.set2(numero);
  stream>>numero;
  objeto.set3(numero);

  return stream;
} 

} // Fin del espacio de nombres ed
