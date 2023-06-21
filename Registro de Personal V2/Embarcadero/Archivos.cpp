#include "Archivos.h"
#include "Fecha.h"
#include "Persona.h"
#include <iostream>
#include <fstream>

using namespace std;
void Archivos::guardarListaProdctos(ListaCircularDoble lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (int i = 0; i < lista.dimencion(); i++) {
            archivo << lista.getPosicion(i).getCedula() << ",";
            archivo << lista.getPosicion(i).getNombre() << ",";
            archivo << lista.getPosicion(i).getApellido() << endl;
        }
        archivo.close();
        cout << "\n Registro exitoso guardado exitosamente " << endl;
    }
    else {
        cerr << "\n No se pudo abrir el archivo " << nombreArchivo << " para escribir" << endl;
    }
}

ListaCircularDoble Archivos::leerListaTDAProductos(const string& nombreArchivo) {
    ListaCircularDoble lista;
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            Persona objeto;
            string cedula, nombre, apellido;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            if (coma_pos != string::npos) {
                cedula = linea.substr(0, coma_pos);
                nombre = stof(linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1));
                apellido = stoi(linea.substr(coma_pos2 + 1));
                Persona persona;
                persona.setCedula(cedula);
                persona.setNombre(nombre);
                persona.setApellido(apellido);
                lista.insertar(persona);
            }
        }
        archivo.close();
        cout << "\n Registros leidos exitosamente desde " << endl;
    }
    else {
        cerr << "\n No se pudo abrir el archivo " << nombreArchivo << " para leer" << endl;
    }
    return lista;
}