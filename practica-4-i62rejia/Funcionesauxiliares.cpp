/*! 	
	\file    Funcionesauxiliares.hpp
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

	void ed::grabarGrafoaFichero(std::string const & nombreFichero, ed::Grafo & grafo)
	{
		if(grafo.isEmpty())
		{
			std::cout<<BIRED<<"El grafo esta vacio, no hay nada que guardar"<<RESET<<std::endl;
			std::cin.ignore();
			return;
		}
		std::ofstream fich(nombreFichero.c_str());
		grafo.goToFirstVertex();
		while(grafo.hasCurrVertex())
		{
			fich<<grafo.currVertex();
			grafo.nextVertex();
		}
		std::cout<<BIGREEN<<"Fichero guardado con exito"<<RESET<<std::endl;
		fich.close();
	}


	void ed::estaVacio(ed::Grafo const & grafo)
	{
    	if(grafo.isEmpty())
    	{
       		std::cout<<BIRED<<"El grafo está vacio"<<RESET<<std::endl;
       		return;
    	}
		else
		{
      		std::cout<<BIGREEN<<"El grafo tiene "<<grafo.nVertices()<<" vertices"<<RESET<<std::endl;
      		return;
      	}
	}

//Menu de la p3, queda modificarlo
/*int ed::menu()
{
	int opcion;
	int posicion;

	posicion=2;

	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Insertar una medicion";

	//////////////////////////////////////////////////////////////////////////////

	PLACE(posicion++,10);
	std::cout << "[2] Borrar la cabeza del monticulo";

	PLACE(posicion++,10);
	std::cout << "[3] Imprimir monticulo";

	//////////////////////////////////////////////////////////////////////////////

	PLACE(posicion++,10);
	std::cout << "[4] Borrar todos los elementos del monticulo";

	posicion++;
	PLACE(posicion++,10);
	std::cout <<  "[5] Cargar desde fichero";

	PLACE(posicion++,10);
	std::cout << "[6] Grabar fichero";

	posicion++;
	PLACE(posicion++,10);
	std::cout << "[7] Modificar cabeza del monticulo";

	PLACE(posicion++,10);
	std::cout << "[8] Mostrar cabeza del monticulo";

	PLACE(posicion++,10);
	std::cout<<"[9] Mostrar numero de elementos en el monticulo";

	posicion++;

	PLACE(posicion++,10);
	std::cout<<"[10] Media de precipitaciones por mes";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";


	//////////////////////////////////////////////////////////////////////////////
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
}*/