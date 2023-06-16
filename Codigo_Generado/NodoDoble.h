/***********************************************************************
 * Module:  NodoDoble.h
 * Author:  MATEO
 * Modified: viernes, 16 de junio de 2023 9:10:31
 * Purpose: Declaration of the class NodoDoble
 ***********************************************************************/

#if !defined(__Registro_Personal_NodoDoble_h)
#define __Registro_Personal_NodoDoble_h

class ListaCircularDoble;

#include <Persona.h>

class NodoDoble
{
public:
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   NodoDoble* getSiguiente(void);
   void setSiguiente(NodoDoble* newSiguiente);
   NodoDoble* getAnterior(void);
   void setAnterior(NodoDoble* newAnterior);
   NodoDoble(Persona persona1);
   ~NodoDoble();

   ListaCircularDoble** listaCircularDoble;

protected:
private:
   Persona persona;
   NodoDoble* siguiente;
   NodoDoble* anterior;


};

#endif