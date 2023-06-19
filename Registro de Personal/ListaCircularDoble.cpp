/***********************************************************************
 * Module:  ListaCircularDoble.cpp
 * Author:  ronny
 * Modified: s�bado, 17 de junio de 2023 9:28:05
 * Purpose: Implementation of the class ListaCircularDoble
 ***********************************************************************/

#include "ListaCircularDoble.h"

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble::ListaCircularDoble()
// Purpose:    Implementation of ListaCircularDoble::ListaCircularDoble()
// Return:     
////////////////////////////////////////////////////////////////////////

ListaCircularDoble::ListaCircularDoble()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble::~ListaCircularDoble()
// Purpose:    Implementation of ListaCircularDoble::~ListaCircularDoble()
// Return:     
////////////////////////////////////////////////////////////////////////

ListaCircularDoble::~ListaCircularDoble()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble::insertar(Persona persona1)
// Purpose:    Implementation of ListaCircularDoble::insertar()
// Parameters:
// - persona1
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaCircularDoble::insertar(Persona persona1)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble::eliminar(Persona persona1)
// Purpose:    Implementation of ListaCircularDoble::eliminar()
// Parameters:
// - persona1
// Return:     void
////////////////////////////////////////////////////////////////////////

void eliminar(const char* valor) {

    if (cabeza == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    NodoDoble* actual = cabeza;
    NodoDoble* anterior = nullptr;
    bool encontrado = false;

    do {
        if (strcmp(actual->getPersona().getCedula(), valor) == 0) {
            encontrado = true;
            break;
        }

        anterior = actual;
        actual = actual->getSiguiente();
    } while (actual != cabeza);

    if (!encontrado) {
        std::cout << "El valor " << valor << " no se encontró en la lista." << std::endl;
        return;
    }

    if (actual == cabeza && actual->getSiguiente() == cabeza) {
        cabeza = nullptr;
    }
    else if (actual == cabeza) {
        cabeza = actual->getSiguiente();
        actual->getAnterior()->setSiguiente(cabeza);
        cabeza->setAnterior(actual->getAnterior());
    }
    else {
        actual->getAnterior()->setSiguiente(actual->getSiguiente());
        actual->getSiguiente()->setAnterior(actual->getAnterior());
    }

    delete actual;
    std::cout << "Se eliminó el valor " << valor << " de la lista." << std::endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble::mostrar()
// Purpose:    Implementation of ListaCircularDoble::mostrar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaCircularDoble::mostrar(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaCircularDoble::buscar()
// Purpose:    Implementation of ListaCircularDoble::buscar()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool ListaCircularDoble::buscar(void)
{
   // TODO : implement
}