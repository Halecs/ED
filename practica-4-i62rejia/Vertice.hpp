
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
		float v_[2];
		int label_;

	public:
		Vertice();
		inline float* getData(){ return v_;};
		inline int getLabel(){return label_;};
		inline void setData(float* v)
		{
			v_[0] = v[0];
			v_[1] = v[1];

			#ifndef NDEBUG
				assert((abs(v_[0] - v[0])) < COTA_ERROR);
				assert((abs(v_[1] - v[1])) < COTA_ERROR);
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