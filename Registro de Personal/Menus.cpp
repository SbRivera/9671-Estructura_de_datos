#include <iostream>
#include <conio.h>
#include "Gestor.h"
// Definir c\242digos de escape ANSI para colores de texto
#define ANSI_COLOR_CYAN     "\x1b[94m"
#define ANSI_COLOR_RESET    "\x1b[0m"

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
    std::cout << "\t\t\t=== MENU ===" << std::endl;
    for (int i = 1; i <= 5; i++) {
        if (i == opcionActual) {
            std::cout << "\t> " << ANSI_COLOR_CYAN ;
        }
        else {
            std::cout << "  ";
        }
        switch (i) {
            case 1:
                std::cout << "Registrar Nuevo Empleado" << ANSI_COLOR_RESET << std::endl;
                gestor.insertarDatos();
                break;
            case 2:
                std::cout << "Buscar Registro de Empleado" << ANSI_COLOR_RESET << std::endl;
                gestor.buscarRegistroPersona();
                break;
            case 3:
                std::cout << "Editar Registro de Empleado" << ANSI_COLOR_RESET << std::endl;
                break;
            case 4:
                std::cout << "Eliminar Registro de Empleado" << ANSI_COLOR_RESET << std::endl;
                break;
            case 5:
                std::cout << "Salir" << ANSI_COLOR_RESET << std::endl;
                break;
        }
    }
}

int moverMenu() {
    int opcionActual = 1;

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
                        std::cout << "\t === Registrar Nuevo Empleado ===" << std::endl;

                        break;
                    case 2:
                        std::cout << "\t === Buscar Registro de Empleado ===" << std::endl;

                        break;
                    case 3:
                        std::cout << "\t === Editar Registro de Empleado ===" << std::endl;
                        break;
                    case 4:
                        std::cout << "\t === Eliminar Registro de Empleado ===" << std::endl;
                        break;
                    case 5:
                        std::cout << "Saliendo del programa..." << std::endl;
                        return 0;
                }
                _getch();
                regresarMenu();
                break;
        }
    }
    return 0;
}




