/***********************************************************************
 * Module:  ListaCircularDoble.h
 * Author:  ronny
 * Modified: s�bado, 17 de junio de 2023 9:28:05
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/

#if !defined(__Registro_Personal2_ListaCircularDoble_h)
#define __Registro_Personal2_ListaCircularDoble_h

#include <NodoDoble.h>
#include <Persona.h>

class ListaCircularDoble
{
public:
   ListaCircularDoble();
   ~ListaCircularDoble();
   void insertar(Persona persona1);
   void eliminar(const char*);
   void mostrar(void);
   bool buscar(void);

protected:
private:
   NodoDoble* cabeza;
   NodoDoble* cola;


};

#endif