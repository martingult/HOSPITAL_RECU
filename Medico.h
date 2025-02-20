#ifndef MEDICO_H
#define MEDICO_H
#include <string>

class Medico {
public:
    static void inicializarArchivo();
    static void registrar();
    static void buscar();
    static void eliminar();
    static void modificar();
};

#endif