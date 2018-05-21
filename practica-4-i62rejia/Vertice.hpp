
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

namespace ed {

class Vertice
{
	private:
		float x_;
		float y_;
		int label_;

	public:
		Vertice();
		inline float getDataX(){ return x_;};
		inline float getDataY(){return y_;};
		inline int getLabel(){return label_;};
		inline void setData(float x, float y)
		{
			x_ = x;
			y_ = y;

			#ifndef NDEBUG
				assert((abs(x_ - x)) < COTA_ERROR);
				assert((abs(y_ - y)) < COTA_ERROR);
			#endif
		}
		inline void setLabel(int x)
		{
			label_ = x;

			#ifndef NDEBUG
				assert(getLabel() == x);
			#endif

		}
};





} //end namespace ed

#endif