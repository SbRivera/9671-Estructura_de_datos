#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaCircularDoble.h"

class Archivos {
public:
    void guardarListaProdctos(ListaCircularDoble lista, const std::string& nombreArchivo);
    ListaCircularDoble leerListaTDAProductos(const std::string& nombreArchivo);
};

