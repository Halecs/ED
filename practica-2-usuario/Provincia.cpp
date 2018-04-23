/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>
#include <cstdlib>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

int ed::Provincia::getTotalMujeres(){
    ed::Municipio aux;
    int sum=0;
   _listaMunicipios.gotoHead();
    while(!_listaMunicipios.isLastItem())
    {
        aux=_listaMunicipios.getCurrentItem();
        sum=sum+aux.getMujeres();
        _listaMunicipios.gotoNext();
    }

   aux=_listaMunicipios.getCurrentItem();
   sum=sum+aux.getMujeres();
   return sum;
 }


int ed::Provincia::getTotalHombres(){
    ed::Municipio aux;
    int sum=0;
   _listaMunicipios.gotoHead();
    while(!_listaMunicipios.isLastItem())
    {
        aux=_listaMunicipios.getCurrentItem();
        sum=sum+aux.getHombres();
        _listaMunicipios.gotoNext();
    }

   aux=_listaMunicipios.getCurrentItem();
   sum=sum+aux.getHombres();
   return sum;

 }


/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES




///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios()
{
	std::cout<<_nombre<<" "<<_codigo<<std::endl;
	if(!_listaMunicipios.isEmpty())
	{
		ed::Municipio aux;
		_listaMunicipios.gotoHead();
		while( !_listaMunicipios.isLastItem())
		{
			aux= _listaMunicipios.getCurrentItem();
			std::cout<<aux<<std::endl;
			_listaMunicipios.gotoNext();
		}
		aux=_listaMunicipios.getCurrentItem();
		std::cout<<aux<<std::endl;
	}
}

bool ed::Provincia::cargarFichero(std::string nombre)
{
	ed::Municipio aux;
	std::string got;
	std::ifstream fich(nombre.c_str());

	if(fich.is_open())
	{
		_listaMunicipios.removeAll();
		getline(fich, got,' ');
		setCodigo(atoi(got.c_str()));
		getline(fich, got, '\n');
		setNombre(got);
		while(fich>>aux)
			_listaMunicipios.insert(aux);
		fich.close();
		return true;
	}
	else
		return false;
}

bool ed::Provincia::grabarFichero(std::string nombre)
{
	ed::Municipio aux;
	std::string got;
	std::ofstream fich(nombre.c_str());

	if(fich.is_open())
	{
		fich<<getCodigo()<<' '<<getNombre()<<std::endl;
		_listaMunicipios.gotoHead();
		while(!_listaMunicipios.isLastItem())
		{
			aux=_listaMunicipios.getCurrentItem();
			fich<<aux;
			_listaMunicipios.gotoNext();
		}
		fich<<_listaMunicipios.getCurrentItem();
		fich.close();
		return true;
	}
	else 
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS


