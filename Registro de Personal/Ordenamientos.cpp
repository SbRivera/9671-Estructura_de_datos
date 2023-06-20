#include <iostream>
#include <conio.h>
#define ANSI_COLOR_CYAN     "\x1b[94m"
#define ANSI_COLOR_RESET    "\x1b[0m"

using namespace std;

void regresarMenuOrdenamiento() {
    while (true) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) {
                break;
            }
        }
    }
}

void menuOrdenamiento(int opcionActual) {
	cout << "\t\t\t=== Ordenamientos ===" << endl;
    for (int i = 1; i <= 7; i++) {
        if (i == opcionActual) {
            cout << "\t> " << ANSI_COLOR_CYAN;
        }
        else {
            cout << "  ";
        }
        switch (i) {
            case 1:
                cout << "Ordenamiento _________" << ANSI_COLOR_RESET << endl;
                break;
            case 2:
                cout << "Ordenamiento _________" << ANSI_COLOR_RESET << endl;
                break;
            case 3:
                cout << "Ordenamiento _________" << ANSI_COLOR_RESET << endl;
                break;
            case 4:
                cout << "Ordenamiento _________" << ANSI_COLOR_RESET << endl;
                break;
            case 5:
                cout << "Ordenamiento _________" << ANSI_COLOR_RESET << endl;
                break;
            case 6:
                cout << "Ordenamiento _________" << ANSI_COLOR_RESET << endl;
                break;
            case 7:
                cout << "Volver" << ANSI_COLOR_RESET << endl;
                break;
        }
    }
}

operarMenuOrdenamiento() {
    int opcionActual = 1;

    while (true) {
        system("cls");

        menuOrdenamiento(opcionActual);

        char tecla = _getch();

        switch (tecla) {
            case 72:
                opcionActual = (opcionActual > 1) ? opcionActual - 1 : 7;
                break;
            case 80:
                opcionActual = (opcionActual < 7) ? opcionActual + 1 : 1;
                break;
            case 13:
                system("cls");
                switch (opcionActual) {
                    case 1:
                        cout << "\t === Ordenamiento _________ ===" << endl;
                        break;
                    case 2:
                        cout << "\t === Ordenamiento _________ ===" << endl;
                        
                        break;
                    case 3:
                        cout << "\t === Ordenamiento _________===" << endl;
                        break;
                    case 4:
                        cout << "\t === Ordenamiento _________ ===" << endl;

                        break;
                    case 5:
                        cout << "\t === Ordenamiento _________ ===" << endl;
                        
                        break;
  					 case 6:
                		cout << "\t === Ordenamiento _________ ===" << endl;
                		
                		break;
                    case 7:        
					cout << "\t === Presione Esc para volver ===" << endl;            
                        return 0;
                }
                _getch();
                regresarMenuOrdenamiento();
                break;
        }
    }
    return 0;
}

//Ingresar Las Funciones de Ordenamiento (Deber)



/*void ordenarPorIntercambio(){	
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr)
        return;

    bool intercambioRealizado = false;
    NodoDoble* actual = cabeza;
    Persona p1=actual->getDato();
    NodoDoble* siguiente = actual->getSiguiente();
	Persona p2=siguiente->getDato();
    while (siguiente != nullptr) {
        if (p1.getNombre() > p2.getNombre()) {
            Persona aux = actual->getDato();
            actual->setDato(siguiente->getDato());
            siguiente->setDato(aux);
            intercambioRealizado = true;
        }
        actual = siguiente;
        p1=actual->getDato();
		siguiente = siguiente->getSiguiente();
		p2=siguiente->getDato();
    }

    if (intercambioRealizado)
        ordenarPorIntercambio();
}  */

