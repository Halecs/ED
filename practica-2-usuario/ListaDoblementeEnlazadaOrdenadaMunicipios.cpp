/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead()
{
	#ifndef NDEBUG
		assert(isEmpty() == false);
	#endif
    
    setCurrent(getHead());

	#ifndef NDEBUG
		assert(isFirstItem() == true);
	#endif
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast()
{
	#ifndef NDEBUG
		assert(isEmpty() == false);
	#endif

	// ed::NodoDoblementeEnlazadoMunicipio *aux = getCurrent();
	while(isLastItem() == false)
		setCurrent(getCurrent()->getNext());
	
	#ifndef NDEBUG
		assert(isLastItem() == true);
	#endif
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious()
{
	#ifndef NDEBUG
		assert(isEmpty() == false);
		assert(isFirstItem() == false);
	#endif	
	setCurrent(getCurrent()->getPrevious());
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext()
{
	#ifndef NDEBUG
		assert(isEmpty() == false);
		assert(isLastItem() == false);
	#endif
	setCurrent(getCurrent()->getNext());
}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(const ed::Municipio &item){

    if(isEmpty())
    	return false;
    ed::NodoDoblementeEnlazadoMunicipio *it=getHead();
    ed::Municipio aux;
    if(nItems()==1) 
    {
    	setCurrent(_head);
        if(_head->getItem()==item) 
        	return true;
        else 
        	return false;
    }
    
    while((it->getNext()!=NULL)){
        if(item==it->getItem())
        {
            setCurrent(it);
            return true;
        }
        if(item<it->getItem())
        {
        	setCurrent(it);
            return false; 
        }
        it=it->getNext();    
    }
     setCurrent(it);
     if(_current->getItem()==item)
     	return true;	
     return false;   

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(const ed::Municipio &item)
{
       int n=nItems();
       ed::NodoDoblementeEnlazadoMunicipio *nodo= new ed::NodoDoblementeEnlazadoMunicipio(item,NULL,NULL);

      	if(!find(item)){
       	if(isEmpty())
          setHead(nodo); 
      	else{     
       		if(n==1){
           		if(_head->getItem()<nodo->getItem())
           		{
            		//Insertar al final
            		_current->setNext(nodo);
            		nodo->setPrevious(_current);
            	}
            	else
           		{
            	//Insertar al principio
           		_current->setPrevious(nodo);
           		nodo->setNext(_current);
           		setHead(nodo);
           		}
           	}
          	
         	else{    
          		if(isLastItem()){
            		if(item<_current->getItem())
            			//Insertar enmedio
            		{
          				ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getPrevious();            			
            			aux->setNext(nodo);
            			_current->setPrevious(nodo);
            			nodo->setPrevious(aux);
            			nodo->setNext(_current);
            		}
            		else
            		{
            			//Insertar al final
            			_current->setNext(nodo);
            			nodo->setPrevious(_current);
            		}
		        }
          	else{
            	if(isFirstItem())
            	{
            		//Insertar al principio
            		_current->setPrevious(nodo);
            		nodo->setNext(_current);
            		setHead(nodo);	
              	}
             	else{
             		//insertar enmedio
          			ed::NodoDoblementeEnlazadoMunicipio *aux=_current->getPrevious();            			
            		aux->setNext(nodo);
            		_current->setPrevious(nodo);
           			nodo->setPrevious(aux);
           			nodo->setNext(_current);
             	}
           	}
        }
    }
       setCurrent(nodo);
       _nItems=_nItems+1;

    #ifndef NDEBUG
		assert(n+1==nItems());
        assert(!isEmpty()); 
	#endif //NDEBUG

} //find

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove()
{
	#ifndef NDEBUG
		assert(isEmpty() == false);
	#endif
		ed::ListaDoblementeEnlazadaOrdenadaMunicipios old = *this;
		if(nItems() == 1)
		{
			delete getCurrent();
			setCurrent(NULL);
			setHead(NULL);
		}
		else
		{
			if (isFirstItem())
			{
				setHead(getHead()->getNext());
				delete getCurrent();
				setCurrent(getHead());
				getCurrent()->setPrevious(NULL);
			}
			else
			{ 
				if(isLastItem())
				{
					setCurrent(getCurrent()->getPrevious());
					delete getCurrent()->getNext();
					getCurrent()->setNext(NULL);
				}
				else
				{
					getCurrent()->getNext()->setPrevious(getCurrent()->getPrevious());
					gotoNext();
					delete getCurrent()->getPrevious()->getNext();
					getCurrent()->getPrevious()->setNext(getCurrent());
					
				}
			}
		}
		_nItems--;
	#ifndef NDEBUG
		assert(nItems() == old.nItems()-1);
	#endif
}

