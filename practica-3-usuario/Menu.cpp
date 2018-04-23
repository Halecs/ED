/*!

	\file Menu.cpp
	\brief Programa principal de la práctica 3 de ED
	\author Alejandro Reyes Jimenez
	\date 
	\version 1.0
*/


// Para los flujos de entrada y salida y para usar locale
#include <iostream>


#include <string>

#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"



/*! 
	\brief   Programa principal de la práctica 3
	\return  int
*/
int main(){

	ed::MonticuloMediciones monticulo;
	ed::Medicion aux;
				  	std::string nombreFicheroEntrada;
				  						std::string nombreFicheroSalida;


	int opcion;

	do{
		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
			break;

		   ///////////////////////////////////////////////////////////////////

			case 1: 
					std::cout << "[1] Insertar una medicion en el monticulo" << std::endl;
					aux.leerMedicion();
					monticulo.insert(aux);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 2: 
					std::cout << "[2] Borrar la cabeza del monticulo" << std::endl;
					if(monticulo.isEmpty())
					{
						std::cout<<BIRED<<"No hay elementos en el monticulo que borrar"<<std::endl;
						break;
					}
					else monticulo.remove();
					std::cout<<BIGREEN<<"Cabeza borrada"<<std::endl;
					break;

			case 3: 
					std::cout << "[3] Imprimir monticulo" << std::endl;
					monticulo.print();
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 4: 
				  	std::cout << "[4] Borrar todos los elementos del monticulo" << std::endl; 
					monticulo.removeAll();
					std::cout<<BIGREEN<<"Todos los elementos borrados"<<std::endl;
					break;

			case 5: 
				  	std::cout << "[5] Cargar desde fichero" << std::endl;
					std::cout<<BIYELLOW<<"Introduzca nombre del fichero de donde quiere cargar el monticulo"<<std::endl;
				  	std::cin>>nombreFicheroEntrada;
					ed::cargarMonticuloDeFichero(nombreFicheroEntrada,monticulo);
					std::cout<<BIGREEN<<"Fichero cargado con exito"<<std::endl;
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6: 
					std::cout << "[6] Grabar fichero" 
							  << std::endl;

					std::cout<<BIYELLOW<<"Introduzca nombre del fichero donde quiere guardar el monticulo"<<std::endl;
				  	std::cin>>nombreFicheroSalida;
				  	ed::grabarMonticuloEnFichero(nombreFicheroSalida, monticulo);
					break;


			case 7: 
					std::cout << "[7] Modificar cabeza" << std::endl;
					if(monticulo.isEmpty())
					{
						std::cout<<BIRED<<"El monticulo esta vacio, introduzca un elemento primero para poder modifcarlo"<<std::endl;
						break;
					}
				 	aux.leerMedicion();
				 	monticulo.modify(aux);
					break;

			case 8:
					std::cout<<"[8] Mostrar cabeza del monticulo" << std::endl;
					if(monticulo.isEmpty())
					{
						std::cout<<BIRED<<"El monticulo esta vacio, introduzca un elemento primero para poder mostrarlo"<<std::endl;
						break;
					}
					std::cout<<BIGREEN<<monticulo.top()<<std::endl;
					break;
			//////////////////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		PLACE(25,1);
		std::cout << "Pulse ";
		std::cout << BIGREEN;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << INVERSE;
		std::cout << "menú"; 
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}
