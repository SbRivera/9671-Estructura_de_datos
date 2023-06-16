/***********************************************************************
 * Module:  Persona.h
 * Author:  MATEO
 * Modified: viernes, 16 de junio de 2023 8:39:57
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Registro_Personal_Persona_h)
#define __Registro_Personal_Persona_h

class Registro;
class NodoDoble;
class ListaCircularDoble;

#include <Fecha.h>

class Persona
{
public:
   char* getCedula(void);
   void setCedula(char* newCedula);
   char* getNombre(void);
   void setNombre(char* newNombre);
   char* getApellido(void);
   void setApellido(char* newApellido);
   Fecha getFecha(void);
   void setFecha(Fecha newFecha);
   Persona();
   ~Persona();

   Registro** registro;
   NodoDoble** nodoDoble;
   ListaCircularDoble** listaCircularDoble;

protected:
private:
   char* cedula;
   char* nombre;
   char* apellido;
   Fecha fecha;


};

#endif