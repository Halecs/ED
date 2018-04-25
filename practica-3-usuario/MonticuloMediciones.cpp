/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author 
	\date 
*/

//#include <vector>

#include <cassert>
#include <algorithm>
#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones

	void ed::MonticuloMediciones::shiftUp(int i)
	{
		ed::Medicion aux;
		ed::Medicion aux2;
		if((i > 0) && (getElement(i).getPrecipitacion() > getElement(getParent(i)).getPrecipitacion()))
		{
			std::swap(_mediciones[i],_mediciones[getParent(i)]);
			shiftUp(getParent(i));
		}
		/*#ifndef NDEBUG
			assert(getElement(i).getPrecipitacion() > getElement(getRightChild(i)).getPrecipitacion());
			assert(getElement(i) < getElement(getLeftChild(i)));
			assert(getElement(i) <= getElement(getParent(i)));
		#endif*/
	}

	void ed::MonticuloMediciones::shiftDown(int i)
	{
		int n = i;
		int lc = getLeftChild(i);
		int rc = getRightChild(i);
		ed::Medicion aux;
		ed::Medicion aux2;

		if((lc < size() - 1) && (getElement(lc).getPrecipitacion() > getElement(n).getPrecipitacion()))
			n = lc;
		if((rc < size() - 1) && (getElement(rc).getPrecipitacion() > getElement(n).getPrecipitacion()))
			n = rc;
		if(i != n)
		{
			aux = getElement(i);
			aux2 = getElement(n);
			setElement(i,aux2);
			setElement(n,aux);
			shiftDown(n);
		}
	}

	bool ed::MonticuloMediciones::has(ed::Medicion &medicion) const
	{
		if(isEmpty())
			return false;

		for (int i = 0; i < size(); ++i)
		{
			if(getElement(i) == medicion)
				return true;
		}
		return false;
	}
////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

	void ed::MonticuloMediciones::insert(ed::Medicion &medicion)
	{
		if(has(medicion))
		{
			std::cout<<BIRED<<"Esa medicion ya existe en el monticulo"<<RESET<<std::endl;
			std::cin.ignore();
			return;
		}

		if(size() == 0)
		{
			setElement(0, medicion);
			_size++;
		}
		else
		{
			if((size()>= 0) && (size()<366))
			{
				setElement(size(),medicion);
				shiftUp(size());
				_size++;
			}
			else
			{
				std::cout<<BIRED<<"No se puede insertar la medicion porque esta lleno el monticulo"<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}
		}

		#ifndef DEBUG
			assert(isEmpty() == false);
			assert(has(medicion) == true);
		#endif
	}

	void ed::MonticuloMediciones::remove()
	{
		#ifndef NDEBUG
			assert(isEmpty() == false);
		#endif
			
			if(isEmpty())
				return;

		if(size() == 1)
		{
			ed::Medicion aux2;
			setElement(0, aux2);
			_size--;
		}
		else
		{
			ed::Medicion aux = getElement(size() -1);
			setElement(0, aux);
			shiftDown(0);
			_size--;
		}

	}

	void ed::MonticuloMediciones::removeAll()
	{
		int xsize = size();
		int i;
		for (i = 0; i < xsize; ++i)
		{
			remove();
		}
		#ifndef NDEBUG
			assert(isEmpty() == true);
		#endif
	}

	void ed::MonticuloMediciones::modify(ed::Medicion &medicion)
	{
		#ifndef NDEBUG
			assert(isEmpty() == false);
		#endif

		setElement(0, medicion);
		shiftDown(0);

		#ifndef NDEBUG
			assert(has(medicion) == true);
		#endif
	}


