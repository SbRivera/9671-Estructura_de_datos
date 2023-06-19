/**
 * @file gestor.cpp
 * @version 1.0.4
 * @date 18/06/2023
 * @author Karla Ansatuña, Alexis Chimba, Matias Suarez
 * @brief Funciones base y uso de librerias estandar y para manipulacion del archivo txt
 */
#include "Gestor.h"
#include <iostream>
#include <fstream>

using namespace std;
void Gestor::cargarDatos() {
    ifstream archivo;
    archivo.open("datos.txt", ios::in);
    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void Gestor::guardarDatos() {
    ofstream archivo;
    archivo.open("datos.txt", ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    archivo << "Cedula: " << cedula << endl;
    archivo << "Nombre: " << nombre << endl;
    archivo << "Apellido: " << apellido << endl;
    archivo << "Fecha: " << fecha << endl;
    archivo.close();
}
//crea una funcion que busuqe los datos segun la cedula
void Gestor::buscarDatosConCedula(string cedula) {
    ifstream archivo;
    archivo.open("datos.txt", ios::in);
    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}
void Gestor::buscarRegistroPersona(){
    string resultado;
    cout << "Ingrese la cedula de la persona que desea buscar: ";
    cin >> resultado;
    buscarDatosConCedula(resultado);
    this->getInformacion();
}
void Gestor::getInformacion(){
    cout << "Cedula: " << cedula << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Fecha: " << fecha << endl;
}
void Gestor::insertarDatos(){
    cout << "Ingrese la cedula: ";
    cin >> cedula;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese la fecha: ";
    cin >> fecha;
    guardarDatos();
}
void Gestor::imprimirDatos() {
    std::ifstream archivo("datos.txt");  

    if (!archivo) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    archivo.close();
}

