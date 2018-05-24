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
	if(isEmpty())
	{
		std::cout<<BIRED<<"No hay grafo al que aplicar el algoritmo"<<RESET<<std::endl;
		std::cin.ignore();
	}
	else
	{
		std::sort(_lados.begin(),_lados.end(), this->sortLados);
		std::vector<bool> test;
		test.resize(nVertices(), false);
		for (int i = 0; i < nVertices(); ++i)
			coste_minimo.addVertexN(_vertices[i].getDataX(), _vertices[i].getDataY());

		for (int i = 0; i < (int)_lados.size(); ++i)
		{
			int a = _lados[i].first().getLabel() -1;
			int b = _lados[i].second().getLabel() -1;
			if((test[a] == false)
				or (test[b] == false))
			{
				coste_minimo.addEdge(_lados[i].first(),_lados[i].second());
				// a = _lados[i].first().getLabel() -1;
				// b = _lados[i].second().getLabel() -1;
				test[a] = true;
				test[b] = true;
			}
		}
	}
	return coste_minimo;
}