/***********************************************************************
 * Module:  ListaCircularDoble.h
 * Author:  MATEO
 * Modified: viernes, 16 de junio de 2023 9:10:31
 * Purpose: Declaration of the class ListaCircularDoble
 ***********************************************************************/

#if !defined(__Registro_Personal_ListaCircularDoble_h)
#define __Registro_Personal_ListaCircularDoble_h

#include <NodoDoble.h>
#include <Persona.h>

class ListaCircularDoble
{
public:
   ListaCircularDoble();
   ~ListaCircularDoble();
   void insertar(Persona persona1);
   void eliminar(Persona persona1);
   void mostrar(void);
   bool buscar(void);

protected:
private:
   NodoDoble* cabeza;
   NodoDoble* cola;


};

#endif