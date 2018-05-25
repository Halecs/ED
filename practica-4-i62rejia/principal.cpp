/*! 	
	\file    principal.cpp
	\brief   Menu principal Practica 4
	\author  Alejandro Reyes Jimenez
	\date 	 21-05-2018
	\version 1.0
*/

#include <cassert>
#include "Funcionesauxiliares.hpp"

#include "Grafo.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"

/*! 
	\brief   Programa principal de la práctica 4
	\return  int
*/
/*int main(int argc, char const *argv[])
{
	ed::Grafo g;
	cargarGrafoDesdeFichero("vertices.txt", g);
	g.printMatriz();
	grabarGrafoaFichero("salida.txt", g);

	ed::Grafo h = g.kruskal();
	h.printMatriz();
	std::cout<<std::endl;

	ed::Grafo j = g.prim();
	j.printMatriz();
	return 0;
}*/

int main(){

	ed::Grafo g;
	ed::Grafo kruskal;
	ed::Grafo prim;
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
					std::cout << "[1] Comprobar si el grafo esta vacio" << std::endl;
					estaVacio(g);
					break;

			case 2:
					std::cout << "[2] Mostrar matriz del grafo por pantalla" << std::endl;
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo esta vacio"<<std::endl;
						break;
					}
					g.printMatriz();
					break;					

			//////////////////////////////////////////////////////////////////////////////
			case 3: 
					std::cout << "[3] Cargar grafo desde fichero" << std::endl;
					std::cout<<BIYELLOW<<"Introduzca nombre del fichero de donde quiere cargar el monticulo"<<RESET<<std::endl;
				  	std::cin>>nombreFicheroEntrada;
				  	cargarGrafoDesdeFichero(nombreFicheroEntrada, g);
					break;

			case 4: 
					std::cout << "[4] Grabar grafo en fichero" << std::endl;
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo esta vacio"<<std::endl;
						break;
					}	
					std::cout<<BIYELLOW<<"Introduzca nombre del fichero donde quiere guardar el monticulo"<<RESET<<std::endl;
				  	std::cin>>nombreFicheroSalida;			  	
				  	grabarGrafoaFichero(nombreFicheroSalida, g);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 5: 
				  	std::cout << "[5] Aplicar algoritmo de Kruskal al grafo" << std::endl; 
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo esta vacio, no se puede aplicar"<<std::endl;
						break;
					}
					kruskal = g.kruskal();
					std::cout<<BIYELLOW<<"Matriz resultante:"<<RESET<<std::endl;
					kruskal.printMatriz();
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6: 
					std::cout << "[6] Aplicar el algoritmo de Prim al grafo" << std::endl;
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo esta vacio, no se puede aplicar"<<std::endl;
						break;
					}
					prim = g.prim();
					std::cout<<BIYELLOW<<"Matriz resultante:"<<RESET<<std::endl;
					prim.printMatriz();
					break;


			case 7: 
					std::cout << "[7] Longitud total del arbol abarcador" << std::endl;
					if(kruskal.isEmpty() && prim.isEmpty())
					{
						std::cout<<BIRED<<"No se ha aplicado ninguno de los dos algoritmos"<<std::endl;
						break;
					}
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