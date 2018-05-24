#include <cassert>
#include "Funcionesauxiliares.hpp"

#include "Grafo.hpp"
#include "Vertice.hpp"
#include "Lado.hpp"

int main(int argc, char const *argv[])
{
	ed::Grafo g;
	cargarGrafoDesdeFichero("vertices.txt", g);
	g.printMatriz();
	return 0;
}