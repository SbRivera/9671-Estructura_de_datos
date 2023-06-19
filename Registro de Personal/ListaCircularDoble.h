#pragma once
#include "NodoDoble.cpp"
//#include "Persona.cpp"
class ListaCircularDoble
{
private:
	NodoDoble* cabeza;
	NodoDoble* cola;
public:
	ListaCircularDoble();
	~ListaCircularDoble();
	void insertar(Persona);
	void eliminarCedula(string cedula);
	void mostrar();
	void buscarCedula(string cedula);
	void ordenarPorIntercambio();
};


