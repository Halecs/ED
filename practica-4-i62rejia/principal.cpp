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


int main(){

	ed::Grafo g;
	ed::Grafo kruskal;
	ed::Grafo prim;
	ed::Vertice v;

	double x, y;
	std::string a;
	int origen, destino, indice;
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
					std::cout<<BIYELLOW<<"Introduzca nombre del fichero de donde quiere cargar el grafo"<<RESET<<std::endl;
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
					std::cout<<BIYELLOW<<"Introduzca nombre del fichero donde quiere guardar el grafo"<<RESET<<std::endl;
				  	std::cin>>nombreFicheroSalida;			  	
				  	grabarGrafoaFichero(nombreFicheroSalida, g, kruskal, prim);
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
						std::cout<<BIRED<<"El grafo esta vacio, no se puede aplicar"<<RESET<<std::endl;
						break;
					}
					prim = g.prim();
					std::cout<<BIYELLOW<<"Matriz resultante:"<<RESET<<std::endl;
					prim.printMatriz();
					break;


			case 7: 
					std::cout << "[7] Longitud total del arbol abarcador" << std::endl;
					if (kruskal.isEmpty())
					{
						if(prim.isEmpty())
						{
							std::cout<<BIRED<<"No se ha aplicado ninguno de los dos algoritmos"<<RESET<<std::endl;
							break;
						}
						else
						{
							std::cout<<BIBLUE<<"La longitud del arbol abarcador es: "<<prim.longitudArbol()<<RESET<<std::endl;
							break;
						}
					}
					else
						std::cout<<BIBLUE<<"La longitud del arbol abarcador es: "<<kruskal.longitudArbol()<<RESET<<std::endl;					
					break;

			case 8:
					std::cout << "[8] Agregar un vertice al grafo" << std::endl;
					std::cout<<BIBLUE<< "Introduzca x del vertice"<<RESET<<std::endl;
					std::cin>>x;
					std::cout<<BIBLUE<< "Introduzca y del vertice"<<RESET<<std::endl;
					std::cin>>y;
					v.setData(x, y);
					g.findFirstVertex(x,y);
					if(g.hasCurrVertex())
					{
						std::cout<<BIRED<<"El grafo ya contiene ese vertice"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					std::cout<<BIYELLOW<<"Desea conectar el vertice con todos los demas?[y/n] --> "<<RESET;
					std::cin>>a;
					if(a == "y")
					{
						g.addVertex(v);
						std::cout<<BIGREEN<<"Vertice agregado correctamente"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					else
					{
						if(a == "n")
						{
							g.addVertexN(x,y);
							std::cout<<BIGREEN<<"Vertice agregado correctamente"<<RESET<<std::endl;
						}
						else
						{
							std::cout<<BIRED<<"Opcion no valida"<<std::endl;
						}
					}
					// g.addVertexN(x, y);
					// std::cout<<BIGREEN<<"Vertice agregado correctamente"<<RESET<<std::endl;
					std::cin.ignore();
					break;

			case 9:
					std::cout << "[9] Agregar lado al grafo" << std::endl;
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo no tiene vertices"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					std::cout<<BIBLUE<< "Introduzca vertice de origen entre los disponibles: (1 ~ "<<g.nVertices()<<")"<<RESET<<std::endl;
					std::cin>>origen;
					if(not((origen <= g.nVertices()) && (origen > 0.0)))
					{
						std::cout<<BIRED<<"Vertice 1 incorrecto"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					std::cout<<BIBLUE<< "Introduzca vertice de destino entre los disponibles: (1 ~ "<<g.nVertices()<<")"<<RESET<<std::endl;
					std::cin>>destino;
					if(not((destino <= g.nVertices() && destino > 0)) or (origen == destino))
					{
						std::cout<<BIRED<<"Vertice 2 incorrecto"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					g.goToEdge(g.getVertex(origen),g.getVertex(destino));
					if(g.hasCurrEdge())
					{
						std::cout<<BIRED<<"El grafo ya contiene ese lado"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}					
					g.addEdge(g.getVertex(origen),g.getVertex(destino));
					break;

			case 10:
					std::cout << "[10] Borrar vertice del grafo" << std::endl;
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo no tiene vertices"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					std::cout<<BIBLUE<< "Introduzca vertice a borrar entre los disponibles: (1 ~ "<<g.nVertices()<<")"<<RESET<<std::endl;
					std::cin>>indice;
					if(not((indice <= g.nVertices()) && (indice > 0.0)))
					{
						std::cout<<BIRED<<"No existe el vertice a borrar"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					g.goToVertex(g.getVertex(indice));
					if(!g.hasCurrVertex())
					{
						std::cout<<BIRED<<"El grafo no contiene este vertice"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					g.removeVertex();
					std::cout<<BIGREEN<<"Vertice borrado correctamente"<<RESET<<std::endl;
					std::cin.ignore();
					break;

			case 11:
					std::cout << "[11] Borrar lado del grafo" << std::endl;
					if(g.isEmpty())
					{
						std::cout<<BIRED<<"El grafo no tiene vertices"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					std::cout<<BIBLUE<< "Introduzca el primer vertice del lado a borrar entre los disponibles: (1 ~ "<<g.nVertices()<<")"<<RESET<<std::endl;
					std::cin>>origen;
					if(not((origen <= g.nVertices()) && (origen > 0.0)))
					{
						std::cout<<BIRED<<"Vertice 1 incorrecto"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					std::cout<<BIBLUE<< "Introduzca el segundo vertice del lado a borrar entre los disponibles: (1 ~ "<<g.nVertices()<<")"<<RESET<<std::endl;
					std::cin>>destino;
					if(not((destino <= g.nVertices() && destino > 0)) or (origen == destino))
					{
						std::cout<<BIRED<<"Vertice 2 incorrecto"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}
					g.goToEdge(g.getVertex(origen),g.getVertex(destino));
					if(!g.hasCurrEdge())
					{
						std::cout<<BIRED<<"El grafo no contiene ese lado"<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}	
					g.removeEdge();
					std::cout<<BIGREEN<<"Lado borrado correctamente"<<RESET<<std::endl;
					std::cin.ignore();
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