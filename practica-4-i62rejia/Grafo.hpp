#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

#include <iostream>
#include "macros.hpp"
#include "Vertice.hpp"
#include <cstdlib>
#include <vector>
using std::istream;
using std::ostream;


namespace ed {

class Grafo
{
	private:
		std::vector< std::vector<int> > Matrix;

	public:
		inline Grafo()
		{
			Matrix.resize(0);
		}

		inline bool isEmpty()
		{
			if(Matrix.size() == 0)
				return true;
			return false;
		}

		inline bool adjacent(Vertice u, Vertice v)
		{

		}

		inline bool hasCurrVertex()
		{

		}

		inline void addVertex(Vertice u)
		{
			Matrix.push_back(std::vector<int> (1,0));

		}



}; //class Grafo
} //namespace

#endif