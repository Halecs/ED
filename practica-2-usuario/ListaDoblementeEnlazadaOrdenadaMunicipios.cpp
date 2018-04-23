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

/*bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const & item)
{
	if(isEmpty())
	{
		return false;
	}
	ed::Municipio aux;
	while(isLastItem() == false)
	{
		aux=getCurrentItem();
		if(aux == m)
		{
			assert(getCurrentItem() == item);
			return true;
		}
		if(comparar(aux, item))
			aux->setCurrent(getCurrent());
		gotoNext();
	}
	setCurrent(aux->getCurrent());
	return false;
}*/
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



/*void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const & item)
{
	#ifndef NDEBUG
		assert(find(item) == false);
	#endif
	find(item);
	//ed::Municipio aux;
	ed::ListaDoblementeEnlazadaOrdenadaMunicipios old = *this;
	ed::NodoDoblementeEnlazadoMunicipio *nodo = new ed::NodoDoblementeEnlazadoMunicipio(item, NULL, NULL);
	//aux = getCurrentItem();
	//0
	//1
	//+
	if(isEmpty())
	{
		setHead(nodo);
		setCurrent(nodo);
		getCurrent()->setNext(NULL);
		getCurrent()->setPrevious(NULL);

	}
	if(nItems() == 1)
	{
		if(getCurrentItem() < item)
		{
			//Se pone delante
			nodo->setNext(getCurrent());
			nodo->setPrevious(NULL);
			getCurrent()->setPrevious(nodo);
			setHead(nodo);
		}
		else
		{
			//Se pone detras
			nodo->setNext(NULL);
			nodo->setPrevious(getCurrent());
			getCurrent()->setNext(nodo);
			gotoNext();
		}
	}
	if(nItems() > 2)
	{
		//Insertamos en medio
		nodo->setNext(getCurrent()->getNext());
		getCurrent()->setNext(nodo);
		nodo->setPrevious(getCurrent());
		nodo->getNext()->setPrevious(nodo);
		setCurrent(nodo);
	}
	_nItems++;
	#ifndef NDEBUG
		assert(getCurrentItem() == item);
		assert(nItems() == old.nItems()+1);
	#endif
}*/

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
			/*ed::NodoDoblementeEnlazadoMunicipio *aux=_head;
			_head = NULL;
			_current = NULL;
			delete aux;*/
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
			/*ed::NodoDoblementeEnlazadoMunicipio *aux= _current->getNext();
			aux->setPrevious(NULL);
			delete _current;
				if (!isEmpty())
				{
					setCurrent(aux);
					setHead(aux);
				}*/
			}
			else
			{ 
				if(isLastItem())
				{
					setCurrent(getCurrent()->getPrevious());
					delete getCurrent()->getNext();
					getCurrent()->setNext(NULL);
				/*ed::NodoDoblementeEnlazadoMunicipio *aux= _current->getPrevious();
				aux->setNext(NULL);
				delete _current;
				if(!isEmpty())
					setCurrent(aux);*/
				}
				else
				{
					getCurrent()->getNext()->setPrevious(getCurrent()->getPrevious());
					gotoNext();
					delete getCurrent()->getPrevious()->getNext();
					getCurrent()->getPrevious()->setNext(getCurrent());
					
                	/*ed::NodoDoblementeEnlazadoMunicipio *auxP=_current->getPrevious();
                	ed::NodoDoblementeEnlazadoMunicipio *auxN=_current->getNext();
					auxP->setNext(auxN);
					auxN->setPrevious(auxP);
					delete _current;
					setCurrent(auxN);*/
				}
			}
		}
		_nItems--;
	#ifndef NDEBUG
		assert(nItems() == old.nItems()-1);
	#endif
}

// void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll()
// {
	//gotoHead();
	/*ed::NodoDoblementeEnlazadoMunicipio *aux = getHead();
	while(aux != NULL)
	{
		aux = getCurrent()->getNext();
		delete getCurrent();
		setCurrent(aux);
	}
	setHead(NULL);
	setCurrent(NULL);
	_nItems = 0;*/
	/*if(!isEmpty())
	{
		setCurrent(getHead());
		while(!(_current == NULL))
			remove();
	}
	_nItems=0;
	#ifndef NDEBUG
		assert(isEmpty() == true);
	#endif 
}*/
