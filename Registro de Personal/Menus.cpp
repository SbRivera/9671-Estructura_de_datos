#include "ListaCircularDoble.cpp"
#include <iostream>
#include <conio.h>
#include "Validaciones.cpp"

// Definir códigos de escape ANSI para colores de texto
#define ANSI_COLOR_CYAN     "\x1b[94m"
#define ANSI_COLOR_RESET    "\x1b[0m"

class Menus {
private:
    ListaCircularDoble lista;
	Validaciones v1;
public:
    void regresarMenu();
    void mostrarMenu(int opcionActual);
    void menuBusqueda();
    int operarMenu();
    Persona ingresoPersona();
    char* pedirCedula(void);
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
    Validaciones v2;
    string cedula;
    string nombre;
    string apellido;

    cedula= pedirCedula();

    cout << "\n Ingrese el nombre:" << endl;
    nombre=v2.validarStrings();

    cout << "\n Ingrese el Apellido:" << endl;
    apellido=v2.validarStrings();

    persona1.setCedula(cedula);
    persona1.setNombre(nombre);
    persona1.setApellido(apellido);

    return persona1;
}

void Menus::menuBusqueda(){
	string cedula;
	cedula=pedirCedula();
	lista.buscarCedula(cedula);
}

char* Menus::pedirCedula(void){
	Validaciones validacion;
	
	char *cedula;
	bool validar=false;
	int longitud;
	bool bandera=false;
	do{
		cout<<"\n*Cedula: ";
		cedula=validacion.validarEnterosCedula();
		bandera=validacion.verificacionCedula(cedula);
		if(bandera==validar){
			cout<<"\nIngrese una cedula valida"<<endl;
		}
	}while(bandera==validar);
	
	validacion.~Validaciones();
	
	return cedula;
}