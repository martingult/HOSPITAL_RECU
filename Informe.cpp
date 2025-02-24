#include "Informe.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

void Informe::listadoPacientesPorFechas() {
    std::ifstream archivo("citas.txt");
    std::string fechaInicio, fechaFin, linea;

    std::cout << "Ingrese la fecha de inicio (DD/MM/YYYY): ";
    std::getline(std::cin, fechaInicio);
    std::cout << "Ingrese la fecha de fin (DD/MM/YYYY): ";
    std::getline(std::cin, fechaFin);

    bool encontrado = false;
    std::cout << "\n--- Listado de Pacientes Atendidos ---\n";
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string paciente, medico, fecha;
        std::getline(ss, paciente, ',');
        std::getline(ss, medico, ',');
        std::getline(ss, fecha);

        if (fecha >= fechaInicio && fecha <= fechaFin) {
            std::cout << "Paciente: " << paciente << ", Médico: " << medico << ", Fecha: " << fecha << "\n";
            encontrado = true;
        }
    }
    archivo.close();

    if (!encontrado) {
        std::cout << "No hay pacientes atendidos en el rango de fechas especificado.\n";
    }
}

void Informe::medicosConSusCitas() {
    std::ifstream archivo("citas.txt");
    std::string linea;
    std::map<std::string, std::vector<std::string>> medicosCitas;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string paciente, medico, fecha;
        std::getline(ss, paciente, ',');
        std::getline(ss, medico, ',');
        std::getline(ss, fecha);

        medicosCitas[medico].push_back(paciente + " - " + fecha);
    }
    archivo.close();

    std::cout << "\n--- Médicos con sus Citas ---\n";
    for (const auto& [medico, citas] : medicosCitas) {
        std::cout << "Médico: " << medico << "\n";
        for (const auto& cita : citas) {
            std::cout << "  - " << cita << "\n";
        }
    }
}