#pragma once
#include "Persona.cpp"
class NodoDoble
{
private:
	Persona persona;
	NodoDoble* siguiente;
	NodoDoble* anterior;
public:
	NodoDoble(Persona);
	~NodoDoble();
	void setDato(Persona);
	Persona getDato();
	void setSiguiente(NodoDoble*);
	NodoDoble* getSiguiente();
	void setAnterior(NodoDoble*);
	NodoDoble* getAnterior();
};


