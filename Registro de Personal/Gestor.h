#ifndef GESTOR_H
#define GESTOR_H

#include <string>

class Gestor {
public:
    void cargarDatos();
    void guardarDatos();
    void buscarDatosConCedula(std::string cedula);
    void buscarRegistroPersona();
    void getInformacion();
    void insertarDatos();
private:
    std::string cedula;
    std::string nombre;
    std::string apellido;
    std::string fecha;
};

#endif // GESTOR_H
