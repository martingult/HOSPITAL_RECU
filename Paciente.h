#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>

class Paciente {
public:
    static void inicializarArchivo();
    static void registrar();
    static void buscar();
    static void eliminar();
    static void modificar();
};

#endif