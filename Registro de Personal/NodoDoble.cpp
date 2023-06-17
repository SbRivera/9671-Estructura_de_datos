/***********************************************************************
 * Module:  NodoDoble.cpp
 * Author:  ronny
 * Modified: sábado, 17 de junio de 2023 9:28:05
 * Purpose: Implementation of the class NodoDoble
 ***********************************************************************/

#include "ListaCircularDoble.h"
#include "NodoDoble.h"

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::getPersona()
// Purpose:    Implementation of NodoDoble::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona NodoDoble::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::setPersona(Persona newPersona)
// Purpose:    Implementation of NodoDoble::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoDoble::setPersona(Persona newPersona)
{
   persona = newPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::getSiguiente()
// Purpose:    Implementation of NodoDoble::getSiguiente()
// Return:     NodoDoble*
////////////////////////////////////////////////////////////////////////

NodoDoble* NodoDoble::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::setSiguiente(NodoDoble* newSiguiente)
// Purpose:    Implementation of NodoDoble::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoDoble::setSiguiente(NodoDoble* newSiguiente)
{
   siguiente = newSiguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::getAnterior()
// Purpose:    Implementation of NodoDoble::getAnterior()
// Return:     NodoDoble*
////////////////////////////////////////////////////////////////////////

NodoDoble* NodoDoble::getAnterior(void)
{
   return anterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::setAnterior(NodoDoble* newAnterior)
// Purpose:    Implementation of NodoDoble::setAnterior()
// Parameters:
// - newAnterior
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoDoble::setAnterior(NodoDoble* newAnterior)
{
   anterior = newAnterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::NodoDoble(Persona persona1)
// Purpose:    Implementation of NodoDoble::NodoDoble()
// Parameters:
// - persona1
// Return:     
////////////////////////////////////////////////////////////////////////

NodoDoble::NodoDoble(Persona persona1)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDoble::~NodoDoble()
// Purpose:    Implementation of NodoDoble::~NodoDoble()
// Return:     
////////////////////////////////////////////////////////////////////////

NodoDoble::~NodoDoble()
{
   // TODO : implement
}