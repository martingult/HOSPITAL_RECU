﻿#include "Paciente.h"
#include "Medico.h"
#include "Informe.h"
#include <iostream>
#include <locale>

void menuPrincipal();
void menuPaciente();
void menuMedico();
void menuInformes();

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
        std::cout << "3. Informes\n";
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
        case 3:
            menuInformes();
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
        std::cout << "5. Asignar Cita\n";
        std::cout << "6. Ver Citas del Paciente\n";
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
        case 5:
            Paciente::asignarCita();
            break;
        case 6:
            Paciente::verCitasDelPaciente();
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

void menuInformes() {
    int opcion;
    do {
        std::cout << "\n--- Menú Informes ---\n";
        std::cout << "1. Listado de Pacientes Atendidos por Fechas\n";
        std::cout << "2. Médicos con sus Citas\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            Informe::listadoPacientesPorFechas();
            break;
        case 2:
            Informe::medicosConSusCitas();
            break;
        case 0:
            return;
        default:
            std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}
