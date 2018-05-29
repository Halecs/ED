/*! 	
	\file    Grafo.cpp
	\brief   Declaración del TAD Lado
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/
#include "Grafo.hpp"
//PONER OPCION DE HACER LADOS O NO

void ed::Grafo::ajustarAdyacencias()
{
	int i,j;
	_Matrix.resize(nVertices());
	for (i = 0; i < nVertices(); ++i)
		_Matrix[i].resize(nVertices(), std::numeric_limits<double>::infinity());

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
	//Declaramos un nuevo grafo que sera donde guardaremos el arbol
	ed::Grafo coste_minimo;
	//Ordenamos los lados del grafo actual de menor a mayor
	std::sort(_lados.begin(),_lados.end(), this->sortLados);

	//Llenamos el nuevo grafo con todos los vertices que tenemos actualmente
		for (int i = 0; i < nVertices(); ++i)
			coste_minimo.addVertexN(_vertices[i].getDataX(), _vertices[i].getDataY());

		//Inicializalizamos el vector padre que servira para comprobar que no haya ciclos y no se creen varios arboles
		coste_minimo.makep();

		//Recorremos el vector de lados
		for (int i = 0; i < (int)_lados.size(); ++i)
		{
			int x = _lados[i].first().getLabel() ;
			int y = _lados[i].second().getLabel() ;
			//Si este lado no causa un ciclo se añade y lo añado al subarbol
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
	std::vector<int> rev; //Guarda los nodos visitados
	std::vector<int> torev;	//Guarda los nodos no visitados

	//Añadimos al grafo todos los vertices
	for (int i = 0; i < nVertices(); ++i)
		coste_minimo.addVertexN(_vertices[i].getDataX(), _vertices[i].getDataY());

	rev.push_back(0);
	//Llenamos el vector de no visitados con los vertices (empezamos en i+1 porque mis etiquetas empiezan en 1 no en 0)
	for (int i = 0; i < nVertices(); ++i)
		torev.push_back(i+1);

	while(!torev.empty())
	{
		int old = -1;
		int _new = -1;
		std::vector<int>::iterator erase; //Se encarga de borrar un nodo que ya no se va a mover
		double peso = std::numeric_limits<double>::infinity();
		for (std::vector<int>::iterator it=torev.begin();it!=torev.end(); ++it)
		{
			for (std::vector<int>::iterator jt=rev.begin();jt!=rev.end(); ++jt)
			{
				//Para cada elementos del vector no visitados, comprobamos todos los visitados
				//Comprobamos que el vertice no visitado es adyacente con el visitado
				if(adjacent(_vertices[*it], _vertices[*jt]))
				{
					//Si son adyacentes vamos al lado que los une y comprobamos que el peso, que inicialmente es infinito,
					//Sea menor que infinito, asignamos el peso del lado a la variable peso, asi nos aseguramos de buscar siempre el menor peso posible			
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
		//Si se hubiera cambiado el valor del peso, se entra en este if 
		if (old != -1 && _new != -1)
		{
			//Metemos el lado de coste minimo en el grafo nuevo
			coste_minimo.addEdge(_vertices[old],_vertices[_new]);
			//Borramos el nodo de la lista de no visitados
			torev.erase(erase);
			//Y lo metemos en visitados
			rev.push_back(_new);
		}
		else //Se mete aqui si no ha encontrado un lado de coste minimo
		{
			//Incluimos el primer vertice sin visitar a la lista de visitados
			rev.push_back(torev[0]);
			//Y borramos de la lista de pendientes el nodo que hemos metido visitados, asi no se tendra en cuenta 
			torev.erase(torev.begin());
		}
	}
	return coste_minimo;
}

ed::Grafo ed::Grafo::floyd()
{
	#ifndef NDEBUG
		assert(!isEmpty());
	#endif
		ed::Grafo floyd;
		floyd._Matrix.resize(nVertices());
		for (int i = 0; i < nVertices(); ++i)
			floyd._Matrix[i].resize(nVertices(), 0);

		for (int i = 0; i < nVertices(); ++i)
		floyd.addVertexN(_vertices[i].getDataX(), _vertices[i].getDataY());

		for (int k = 0; k <nVertices() ; ++k)
			for (int i = 0; i < nVertices(); ++i)
				for (int j = 0; j < nVertices(); ++j)
				{
					int dt = _Matrix[i][k] + _Matrix[k][j];
					if(_Matrix[i][j] > dt)
						floyd._Matrix[i][j] = dt;
				}

		return floyd;
		
}
