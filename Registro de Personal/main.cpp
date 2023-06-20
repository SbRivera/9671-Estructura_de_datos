#include <iostream>
#include <conio.h>
#include "Menus.cpp"
#include "operacionesArchivo.cpp"

using namespace std;
int main() {
crearCarpetaYArchivo();
Menus menu;
menu.operarMenu();
}

