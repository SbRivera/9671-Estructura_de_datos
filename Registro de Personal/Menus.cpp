#include <iostream>
#include <conio.h>
#include "Gestor.h"

// Definir c\242digos de escape ANSI para colores de texto
#define ANSI_COLOR_CYAN     "\x1b[94m"
#define ANSI_COLOR_RESET    "\x1b[0m"

using namespace std;
void regresarMenu() {
    while (true) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) {
                break;
            }
        }
    }
}

void mostrarMenu(int opcionActual) {
    Gestor gestor;
    cout << "\t\t\t=== MENU ===" << endl;
    for (int i = 1; i <= 5; i++) {
        if (i == opcionActual) {
            cout << "\t> " << ANSI_COLOR_CYAN ;
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
                cout << "Salir" << ANSI_COLOR_RESET << endl;
                break;
        }
    }
}

int operarMenu() {
    int opcionActual = 1;
	Gestor gestor;
    while (true) {
        system("cls");

        mostrarMenu(opcionActual);

        char tecla = _getch();

        switch (tecla) {
            case 72:
                opcionActual = (opcionActual > 1) ? opcionActual - 1 : 5;
                break;
            case 80:
                opcionActual = (opcionActual < 5) ? opcionActual + 1 : 1;
                break;
            case 13:
                system("cls");
                switch (opcionActual) {
                    case 1:
                        cout << "\t === Registrar Nuevo Empleado ===" << endl;
						gestor.insertarDatos();
                        break;
                    case 2:
                        cout << "\t === Buscar Registro de Empleado ===" << endl;
						gestor.buscarRegistroPersona();
                        break;
                    case 3:
                        cout << "\t === Editar Registro de Empleado ===" << endl;
                        break;
                    case 4:
                        cout << "\t === Eliminar Registro de Empleado ===" << endl;
                        break;
                    case 5:
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




