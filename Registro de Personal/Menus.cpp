#include "Gestor.h"
//#include "Persona.cpp"
#include "ListaCircularDoble.cpp"
#include <iostream>
#include <conio.h>

// Definir códigos de escape ANSI para colores de texto
#define ANSI_COLOR_CYAN     "\x1b[94m"
#define ANSI_COLOR_RESET    "\x1b[0m"

class Menus {
private:
    ListaCircularDoble lista;

public:
    void regresarMenu();
    void mostrarMenu(int opcionActual);
    void menuBusqueda();
    int operarMenu();
    Persona ingresoPersona();
};

using namespace std;

void Menus::regresarMenu() {
    while (true) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) {
                break;
            }
        }
    }
}

void Menus::mostrarMenu(int opcionActual) {
    cout << "\t\t\t=== MENU ===" << endl;
    for (int i = 1; i <= 6; i++) {
        if (i == opcionActual) {
            cout << "\t> " << ANSI_COLOR_CYAN;
        }
        else {
            cout << "  ";
        }
        switch (i) {
            case 1:
                cout << "Registrar Nuevo Empleado" << ANSI_COLOR_RESET << endl;
                break;
            case 2:
                cout << "Buscar Registro de Empleado" << ANSI_COLOR_RESET << endl;
                break;
            case 3:
                cout << "Editar Registro de Empleado" << ANSI_COLOR_RESET << endl;
                break;
            case 4:
                cout << "Eliminar Registro de Empleado" << ANSI_COLOR_RESET << endl;
                break;
            case 5:
                cout << "Imprimir Todos los Registros" << ANSI_COLOR_RESET << endl;
                break;
            case 6:
                cout << "Salir" << ANSI_COLOR_RESET << endl;
                break;
        }
    }
}

int Menus::operarMenu() {
    int opcionActual = 1;
    //ListaCircularDoble lista;
    Gestor gestor;
    Persona persona1;

    while (true) {
        system("cls");

        mostrarMenu(opcionActual);

        char tecla = _getch();

        switch (tecla) {
            case 72:
                opcionActual = (opcionActual > 1) ? opcionActual - 1 : 6;
                break;
            case 80:
                opcionActual = (opcionActual < 6) ? opcionActual + 1 : 1;
                break;
            case 13:
                system("cls");
                switch (opcionActual) {
                    case 1:
                        cout << "\t === Registrar Nuevo Empleado ===" << endl;
                        persona1 = ingresoPersona();
                        //gestor.insertarDatos();
                        lista.insertar(persona1);
                        break;
                    case 2:
                        cout << "\t === Buscar Registro de Empleado Por Cedula===" << endl;
                        menuBusqueda();
                        break;
                    case 3:
                        cout << "\t === Editar Registro de Empleado ===" << endl;
                        break;
                    case 4:
                        cout << "\t === Eliminar Registro de Empleado ===" << endl;
                        //gestor.eliminarDatos();
                        break;
                    case 5:
                        cout << "\t === Imprimir Todos los Registros ===" << endl;
                        lista.mostrar();
                        break;
                    case 6:
                        cout << "Saliendo del programa..." << endl;
                        return 0;
                }
                _getch();
                regresarMenu();
                break;
        }
    }
    return 0;
}

Persona Menus::ingresoPersona() {
    Persona persona1;
    char cedula[50];
    char nombre[50];
    char apellido[50];

    cout << "Ingrese el Cedula:" << endl;
    cin >> cedula;

    cout << "Ingrese el nombre:" << endl;
    cin >> nombre;

    cout << "Ingrese el Apellido:" << endl;
    cin >> apellido;

    persona1.setCedula(cedula);
    persona1.setNombre(nombre);
    persona1.setApellido(apellido);

    return persona1;
}

void Menus::menuBusqueda(){
	string cedula;
	cout<<"Ingrese la cedula: "<<endl;
	cin>>cedula;
	lista.buscarCedula(cedula);
}