/*! 	
	\file    Funcionesauxiliares.hpp
	\brief   Funcionesauxiliares Practica 4
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/

#include "Funcionesauxiliares.hpp"


	void ed::cargarGrafoDesdeFichero(std::string const & nombreFichero, ed::Grafo & grafo)
	{
		ed::Vertice aux;
		std::ifstream fich( nombreFichero.c_str() );
		if(!fich)
		{
			std::cout<<"No existe el fichero"<<std::endl;
			return;
		}
		while(fich>>aux)
			grafo.addVertex(aux);

		fich.close();
	}

	void ed::grabarGrafoaFichero(std::string const & nombreFichero, ed::Grafo const & grafo)
	{
		std::ofstream fich(nombreFichero.c_str());
		for (int i = 0; i < grafo.nVertices(); ++i)
		{
			/* code */
		}
		fich.close();
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