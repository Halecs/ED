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