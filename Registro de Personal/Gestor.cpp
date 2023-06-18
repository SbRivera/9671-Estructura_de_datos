#include "gestor.h"
#include <iostream>
#include <fstream>

void Gestor::cargarDatos() {
    std::ifstream archivo;
    archivo.open("datos.txt", std::ios::in);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }
    std::string linea;
    while (getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }
    archivo.close();
}

void Gestor::guardarDatos() {
    std::ofstream archivo;
    archivo.open("datos.txt", std::ios::out);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }
    archivo << "Cedula: " << cedula << std::endl;
    archivo << "Nombre: " << nombre << std::endl;
    archivo << "Apellido: " << apellido << std::endl;
    archivo << "Fecha: " << fecha << std::endl;
    archivo.close();
}
//crea una funcion que busuqe los datos segun la cedula
void Gestor::buscarDatosConCedula(std::string cedula) {
    std::ifstream archivo;
    archivo.open("datos.txt", std::ios::in);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }
    std::string linea;
    while (getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }
    archivo.close();
}
void Gestor::buscarRegistroPersona(){
    std::string resultado;
    std::cout << "Ingrese la cedula de la persona que desea buscar: ";
    std::cin >> resultado;
    buscarDatosConCedula(resultado);
    this->getInformacion();
}
void Gestor::getInformacion(){
    std::cout << "Cedula: " << cedula << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << "Fecha: " << fecha << std::endl;
}
void Gestor::insertarDatos(){
    std::cout << "Ingrese la cedula: ";
    std::cin >> cedula;
    std::cout << "Ingrese el nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese el apellido: ";
    std::cin >> apellido;
    std::cout << "Ingrese la fecha: ";
    std::cin >> fecha;
    guardarDatos();
}