/***********************************************************************
 * Module:  Ingreso.cpp
 * Author:  David Toapanta, Mateo Llumigusin, Carlos Torres
 * Modified: domingo, 04 de junio de 2023 21:45:32
 * Purpose: Registro Personal
 ***********************************************************************/

#if !defined(__RolDePagos_Validaciones_h)
#define __RolDePagos_Validaciones_h

#include <string>
using namespace std;

class Validaciones
{
public:
	
   int validarEnteros() ;
   int LongitudCadena(char *cedula); 
   bool verificarLongitud(char *p); 
   char* validarEnterosCedula(); 
   double validarDoubles(); 
 char* validarStrings(); 
   int* splitNumber(char* number); 
   bool verificacion1(char* numCedula); 
   bool verificacion2(char* numCedula); 
   bool verificacion3(char* numCedula);
   bool verificacionCedula(char* numCedula);
   int validarDia(int mes);
   Validaciones();
   ~Validaciones();

protected:
private:


};

#endif