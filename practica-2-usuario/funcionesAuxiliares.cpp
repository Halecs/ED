/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author 
  \date   
*/

#include <iostream>
#include <string>  
#include <unistd.h>
// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


#include "macros.hpp"

int ed::menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

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


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
	// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	if (provincia.hayMunicipios())
		std::cout<<BIGREEN<<"La provincia tiene municipios"<<RESET<<std::endl;
	else
		std::cout<<BIRED<<"La provincia no tiene municipios"<<RESET<<std::endl;

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{
	// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	std::string nombrefich;
	std::cin>>nombrefich;
	if(provincia.cargarFichero(nombrefich))
		std::cout<<BIGREEN<<"Fichero cargado correctamente"<<RESET<<std::endl;
	else
		std::cout<<BIRED<<"Error al cargar el fichero"<<RESET<<std::endl;
	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	std::string nombrefich;
	std::cin>>nombrefich;
	if(provincia.grabarFichero(nombrefich))
		std::cout<<BIGREEN<<"Fichero grabado correctamente"<<RESET<<std::endl;
	else
		std::cout<<BIRED<<"Error al grabar el fichero"<<RESET<<std::endl;
	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	if(!provincia.hayMunicipios())
	{
		std::cout<<"No hay municipios"<<std::endl;
		return;
	}
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	/*std::cout<<BICYAN<<"NOMBRE | CODIGO | HOMBRES | MUJERES | PERSONAS | MUNICIPIOS"<<RESET<<std::endl;
	std::cout<<provincia.getNombre()<<" "<<provincia.getCodigo()<<" "<<provincia.getTotalHombres()<<" "<<provincia.getTotalMujeres()<<" "<<provincia.getTotalHabitantes()<<" "<<provincia.getNumeroMunicipios()<<std::endl;*/
	std::cout<<BIYELLOW<<"Datos de Provincia\t: Codigo: "<<provincia.getCodigo()<<",Nombre: "<<provincia.getNombre()<<std::endl;
	std::cout<<BIYELLOW<<"Numero de Municipios: "<<provincia.getNumeroMunicipios() <<" Numero de Habitantes de la provincia: "<<provincia.getTotalHabitantes()<<std::endl;
	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{
	// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	if(!provincia.hayMunicipios())
	{
		std::cout<<"No hay municipios"<<std::endl;
		return;
	}
	std::cout<<BICYAN<<"CODIGO POSTAL | NOMBRE | HOMBRES | MUJERES"<<RESET<<std::endl;
	provincia.escribirMunicipios();

	sleep(2);
	return;
}

////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{

// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

// QUITAR LOS COMENTARIOS CUANDO SE HAYA CODIFICADO LA CLASE Provincia


	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
	// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	provincia.borrarTodosLosMunicipios();
	std::cout<<BIGREEN<<"Todos los municipios borrados"<<RESET<<std::endl;
	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	// std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	char aux2[200];
	std::cout<<BIYELLOW<<"Introduzca nombre del municipio a consultar"<<std::endl;
	std::cin.getline(aux2,200);
	std::string aux = aux2;
	if(provincia.existeMunicipio(aux))
		std::cout<<BIGREEN<<"Existe el municipio"<<RESET<<std::endl;
	else
		std::cout<<BIRED<<"No existe el municipio"<<RESET<<std::endl;
	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	ed::Municipio mun;
	std::cout<<BIYELLOW<<"Codigo postal del municipio"<<RESET<<std::endl;
	int i;
	std::cin>>i;
	std::cin.ignore();
	mun.setCodigoPostal(i);
	std::cout<<BIYELLOW<<"Nombre del municipio"<<RESET<<std::endl;
	char aux2[200];
	std::cin>>aux2;
	std::string aux = aux2;
	mun.setNombre(aux);
	std::cout<<BIYELLOW<<"Numero de hombres del municipio"<<RESET<<std::endl;
	std::cin>>i;
	std::cin.ignore();
	mun.setHombres(i);
	std::cout<<BIYELLOW<<"Numero de mujeres del municipio"<<RESET<<std::endl;
	std::cin>>i;
	std::cin.ignore();
	mun.setMujeres(i);
	if(!provincia.existeMunicipio(aux))
		provincia.insertarMunicipio(mun);
	else
		std::cout<<BIRED<<"No se pudo insertar porque ya existe en la lista ese municipio"<<std::endl;
	return;
}

  


void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	
	std::cout<<BIYELLOW<<"Indique el nombre del municipio"<<RESET<<std::endl;
	char aux2[200];
	std::cin.getline(aux2,200);
	std::string aux = aux2;
	if(!provincia.existeMunicipio(aux))
	{
		std::cout<<"No existe el municipio a borrar"<<std::endl;
		return;
	}
	provincia.borrarMunicipio(aux);
	return;
}




