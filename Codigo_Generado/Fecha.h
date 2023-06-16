/***********************************************************************
 * Module:  Fecha.h
 * Author:  MATEO
 * Modified: viernes, 16 de junio de 2023 8:39:57
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__Registro_Personal_Fecha_h)
#define __Registro_Personal_Fecha_h

class Persona;
class Registro;

class Fecha
{
public:
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getAnio(void);
   void setAnio(int newAnio);
   Fecha();
   ~Fecha();
   int getHora(void);
   void setHora(int newHora);
   int getMinutos(void);
   void setMinutos(int newMinutos);
   int getSegundos(void);
   void setSegundos(int newSegundos);

   Persona** persona;
   Registro** registro;

protected:
private:
   int dia;
   int mes;
   int anio;
   int hora;
   int minutos;
   int segundos;


};

#endif