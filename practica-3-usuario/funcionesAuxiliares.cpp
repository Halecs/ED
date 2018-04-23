/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date   
*/


#include <iostream>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"

void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo) 
{
 	std::ifstream fich(nombreFichero.c_str());
 	ed::Medicion aux;
 	if(fich.is_open())
 	{
 		monticulo.removeAll();

 		while(fich >> aux)
 		{
 			if(aux.getFecha().esCorrecta())
 				monticulo.insert(aux);
 		}
		std::cout<<BIGREEN<<"Fichero cargado con exito"<<RESET<<std::endl;
 	}

 	else
 	{
 		std::cout<<BIRED<<"No existe el fichero"<<RESET<<std::endl;
 		std::cin.ignore();
 	}
 	fich.close();
	return;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, 
							      ed::MonticuloMediciones const & monticulo)
{
	ed::MonticuloMediciones aux = monticulo;
 	std::ofstream fich(nombreFichero.c_str());
 	if(fich.is_open())
 	{
 		// for (int i = 0; i < monticulo.size(); ++i)
 			// fich << monticulo.getMedicion(i);
 		while(!aux.isEmpty())
 		{
 			fich<<aux.top();
 			aux.remove();
 		}
 	}
 	fich.close();
	return;
}

 


int ed::menu()
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
}