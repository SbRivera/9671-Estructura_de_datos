//Prohibido Modificar este Código 
#include "ListaCircularDoble.h"
#include <iostream>
using namespace std;

ListaCircularDoble::ListaCircularDoble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

ListaCircularDoble::~ListaCircularDoble()
{
}

void ListaCircularDoble::insertar(Persona dato)
{
	NodoDoble* nuevo = new NodoDoble(dato);
	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cola = nuevo;
		this->cabeza->setSiguiente(this->cola);
		this->cabeza->setAnterior(this->cola);
		this->cola->setSiguiente(this->cabeza);
		this->cola->setAnterior(this->cabeza);
	}
	else
	{
		this->cola->setSiguiente(nuevo);
		nuevo->setAnterior(this->cola);
		nuevo->setSiguiente(this->cabeza);
		this->cabeza->setAnterior(nuevo);
		this->cola = nuevo;
	}
}

//void ListaCircularDoble::eliminar(string cedula)
//{
//	if (this->cabeza != nullptr)
//	{
//		Persona p1=this->cabeza->getDato();
//		if (p1.getCedula() == cedula)
//		{
//			NodoDoble* aux = this->cabeza;
//			this->cabeza = this->cabeza->getSiguiente();
//			this->cabeza->setAnterior(this->cola);
//			this->cola->setSiguiente(this->cabeza);
//			delete aux;
//		}
//		else
//		{
//			NodoDoble* aux = this->cabeza;
//			p1=aux->getDato();
//			while (aux->getSiguiente() != this->cabeza)
//			{
//				if (aux->getSiguiente()->getDato() == dato)
//				{
//					NodoDoble* aux2 = aux->getSiguiente();
//					aux->setSiguiente(aux2->getSiguiente());
//					aux2->getSiguiente()->setAnterior(aux);
//					delete aux2;
//					break;
//				}
//				aux = aux->getSiguiente();
//			}
//		}
//	}
//}


void ListaCircularDoble::mostrar()
{
	if (this->cabeza != nullptr)
	{
		NodoDoble* aux = this->cabeza;
		do
		{
			Persona p1= aux->getDato();
				cout << "Cedula: " << p1.getCedula() << endl;
				cout << "Nombre: " << p1.getNombre() << endl;
				cout << "Apellido: " << p1.getApellido() << endl;
				// Imprimir otros atributos de Persona si los hubiera
			aux = aux->getSiguiente();
		} while (aux != this->cabeza);
		cout << endl;
	}
}


void ListaCircularDoble::buscarCedula(string cedula)
{
	if (this->cabeza != nullptr)
	{
		NodoDoble* aux = this->cabeza;
		Persona p1= aux->getDato();
		do
		{
			if (p1.getCedula() == cedula)
			{
				Persona p1=aux->getDato();
				cout<<"Se encontro a la Persona "<<endl;
				cout<<"Nombre: "<<p1.getNombre()<<endl;
				cout<<"Apellido: "<<p1.getApellido()<<endl;
				cout<<"Cedula: "<<p1.getCedula()<<endl;
			}
			aux = aux->getSiguiente();
			p1 = aux->getDato();
		} while (aux != this->cabeza);
		//cout<<"No se encontro a la persona"<<endl;
	}else{
		cout<<"No se encontro a la persona"<<endl;
	}
	
}
void ListaCircularDoble::ordenarPorIntercambio(){	
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr)
        return;

    bool intercambioRealizado = false;
    NodoDoble* actual = cabeza;
    Persona p1=actual->getDato();
    NodoDoble* siguiente = actual->getSiguiente();
	Persona p2=siguiente->getDato();
    while (siguiente != nullptr) {
        if (p1.getNombre() > p2.getNombre()) {
            Persona aux = actual->getDato();
            actual->setDato(siguiente->getDato());
            siguiente->setDato(aux);
            intercambioRealizado = true;
        }
        actual = siguiente;
        p1=actual->getDato();
		siguiente = siguiente->getSiguiente();
		p2=siguiente->getDato();
    }

    if (intercambioRealizado)
        ordenarPorIntercambio();
}

//
//
//
//
