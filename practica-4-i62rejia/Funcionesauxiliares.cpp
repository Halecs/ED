/*! 	
	\file    Funcionesauxiliares.cpp
	\brief   Funcionesauxiliares Practica 4
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/

#include "Funcionesauxiliares.hpp"
#include "Vertice.hpp"

	void ed::cargarGrafoDesdeFichero(std::string const & nombreFichero, ed::Grafo & grafo)
	{
		ed::Vertice aux;
		std::ifstream fich( nombreFichero.c_str() );
		if(!fich)
		{
			std::cout<<BIRED<<"No existe el fichero"<<std::endl;
			std::cin.ignore();
			return;
		}
		while(fich>>aux)
		{
			if(!grafo.existeVertice(aux))
			grafo.addVertex(aux);
		}
		std::cout<<BIGREEN<<"Fichero cargado con exito"<<RESET<<std::endl;
		std::cin.ignore();
		fich.close();
	}

	void ed::grabarGrafoaFichero(std::string const & nombreFichero, ed::Grafo & grafo, ed::Grafo & kruskal, ed::Grafo & prim)
	{
		std::ofstream fich(nombreFichero.c_str());
		grafo.goToFirstVertex();
		fich<<"Vertices (x , y)\n";
		while(grafo.hasCurrVertex())
		{
			fich<<grafo.currVertex();
			grafo.nextVertex();
		}
		fich<<"\n"<<"Matriz de adyacencias"<<"\n";
		fich<<grafo;

		if(!kruskal.isEmpty())
		{
			fich<<"\n"<<"Matriz resultante de aplicar kruskal"<<"\n";
			fich<<kruskal;
		}

		if(!prim.isEmpty())
		{
			fich<<"\n"<<"Matriz resultante de aplicar prim"<<"\n";
			fich<<prim;	
		}	
		std::cout<<BIGREEN<<"Fichero guardado con exito"<<RESET<<std::endl;
		std::cin.ignore();
		fich.close();
	}


	void ed::estaVacio(ed::Grafo const & grafo)
	{
    	if(grafo.isEmpty())
    	{
       		std::cout<<BIRED<<"El grafo está vacio"<<RESET<<std::endl;
       		std::cin.ignore();
       		return;
    	}
		else
		{
      		std::cout<<BIGREEN<<"El grafo tiene "<<grafo.nVertices()<<" vertices"<<RESET<<std::endl;
       		std::cin.ignore();
      		return;
      	}
	}


int ed::menu()
{
	int opcion;
	int posicion;

	posicion=2;

	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIYELLOW;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	posicion++;
	PLACE(posicion++,10);
	std::cout<<BIBLUE<<"Observadores del grafo"<<RESET<<std::endl;
	PLACE(posicion++,10);
	std::cout << "[1] Comprobar si el grafo esta vacio" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[2] Mostrar matriz del grafo por pantalla\n" << std::endl;
////////////////////////////////////////////////////////////////////////////////
	posicion++;
	PLACE(posicion++,10);
	std::cout<<BIBLUE<<"Ficheros"<<RESET<<std::endl;
	PLACE(posicion++,10);
	std::cout << "[3] Cargar grafo desde fichero" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[4] Grabar grafo en fichero\n" << std::endl;
//////////////////////////////////////////////////////////////////////////////
	posicion++;
	PLACE(posicion++,10);
	std::cout<<BIBLUE<<"Algoritmos"<<RESET<<std::endl;
	PLACE(posicion++,10);
	std::cout << "[5] Aplicar algoritmo de Kruskal al grafo" << std::endl; 

	PLACE(posicion++,10);
	std::cout << "[6] Aplicar el algoritmo de Prim al grafo" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[7] Longitud total del arbol abarcador\n" << std::endl;

	posicion++;
	PLACE(posicion++,10);
	std::cout<<BIBLUE<<"Agregar y/o borrar en el grafo"<<RESET<<std::endl;
	PLACE(posicion++,10);
	std::cout << "[8] Agregar un vertice al grafo" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[9] Agregar un lado al grafo" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[10] Borrar vertice del grafo" << std::endl;

	PLACE(posicion++,10);
	std::cout << "[11] Borrar lado del grafo" << std::endl;

	posicion++;
	posicion++;
	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";


	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}
