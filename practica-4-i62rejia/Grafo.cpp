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
	_Matrix.clear();
	_Matrix.resize(nVertices());

	for (i = 0; i < nVertices(); ++i)
		_Matrix[i].resize(nVertices());

	for (i = 0; i < nVertices(); ++i)
	{
		for (j = 0; j < nVertices(); ++j)
		{
			if(i == j)
				_Matrix[i][j] = 0;
			else
			{
				goToEdge(_vertices[i], _vertices[j]);
				if(hasCurrEdge())		
					_Matrix[i][j] = _lados[_curEdge].getItem();
				else
					_Matrix[i][j] = 99;
			}
		}
	}
}