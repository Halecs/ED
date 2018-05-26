/*! 	
	\file    Grafo.cpp
	\brief   Declaración del TAD Lado
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/
#include "Grafo.hpp"


void ed::Grafo::ajustarAdyacencias()
{
	int i,j;
	_Matrix.resize(nVertices());

	for (i = 0; i < nVertices(); ++i)
		_Matrix[i].resize(nVertices());

	for (i = 0; i < nVertices(); ++i)
	{
		for (j = 0; j < nVertices(); ++j)
		{
			goToEdge(_vertices[i],_vertices[j]);
			if(i == j)
				_Matrix[i][j] = 0;
			else
			{
			 	if(!hasCurrEdge())
			 		_Matrix[i][j] = std::numeric_limits<double>::infinity();
			}
		}
	}
}

ed::Grafo ed::Grafo::kruskal()
{
	ed::Grafo coste_minimo;
	std::sort(_lados.begin(),_lados.end(), this->sortLados);
		for (int i = 0; i < nVertices(); ++i)
			coste_minimo.addVertexN(_vertices[i].getDataX(), _vertices[i].getDataY());

		coste_minimo.makep();
		for (int i = 0; i < (int)_lados.size(); ++i)
		{
			int x = _lados[i].first().getLabel() ;
			int y = _lados[i].second().getLabel() ;
			if(!coste_minimo.same(x,y))
			{
				coste_minimo.addEdge(_lados[i].first(),_lados[i].second());
				coste_minimo.Union(x,y);
			}
		}

	return coste_minimo;
}

ed::Grafo ed::Grafo::prim()
{
	#ifndef NDEBUG
		assert(!isEmpty());
	#endif
	ed::Grafo coste_minimo;
	std::vector<int> rev;
	std::vector<int> torev;
	for (int i = 0; i < nVertices(); ++i)
		coste_minimo.addVertexN(_vertices[i].getDataX(), _vertices[i].getDataY());

	rev.push_back(0);
	for (int i = 0; i < nVertices(); ++i)
		torev.push_back(i+1);

	while(!torev.empty())
	{
		int old = -1;
		int _new = -1;
		std::vector<int>::iterator erase;
		double peso = std::numeric_limits<double>::infinity();
		for (std::vector<int>::iterator it=torev.begin();it!=torev.end(); ++it)
		{
			for (std::vector<int>::iterator jt=rev.begin();jt!=rev.end(); ++jt)
			{
				if(adjacent(_vertices[*it], _vertices[*jt]))
				{
					goToEdge(_vertices[*it], _vertices[*jt]);
					if(currEdge().getItem() < peso)
					{
						peso = currEdge().getItem();
						old = *jt;
						erase = it;
						_new = *it;
					}
				}
			}
		}
		if (old != -1 && _new != -1)
		{
			coste_minimo.addEdge(_vertices[old],_vertices[_new]);
			torev.erase(erase);
			rev.push_back(_new);
		}
		else
		{
			rev.push_back(torev[0]);
			torev.erase(torev.begin());
		}
	}
	return coste_minimo;
}

