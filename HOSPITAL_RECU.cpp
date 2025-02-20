#include "Paciente.h"
#include "Medico.h"
#include <iostream>
#include <locale>

void menuPrincipal();
void menuPaciente();
void menuMedico();

int main() {
    std::locale::global(std::locale(""));
    Paciente::inicializarArchivo();
    Medico::inicializarArchivo();
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int opcion;
    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Paciente\n";
        std::cout << "2. Médico\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            menuPaciente();
            break;
        case 2:
            menuMedico();
            break;
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
}

void menuPaciente() {
    int opcion;
    do {
        std::cout << "\n--- Menú Paciente ---\n";
        std::cout << "1. Registrar Paciente\n";
        std::cout << "2. Buscar Paciente\n";
        std::cout << "3. Eliminar Paciente\n";
        std::cout << "4. Modificar Paciente\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            Paciente::registrar();
            break;
        case 2:
            Paciente::buscar();
            break;
        case 3:
            Paciente::eliminar();
            break;
        case 4:
            Paciente::modificar();
            break;
        case 0:
            return;
        default:
            std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void menuMedico() {
    int opcion;
    do {
        std::cout << "\n--- Menú Médico ---\n";
        std::cout << "1. Registrar Médico\n";
        std::cout << "2. Buscar Médico\n";
        std::cout << "3. Eliminar Médico\n";
        std::cout << "4. Modificar Médico\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            Medico::registrar();
            break;
        case 2:
            Medico::buscar();
            break;
        case 3:
            Medico::eliminar();
            break;
        case 4:
            Medico::modificar();
            break;
        case 0:
            return;
        default:
            std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}