#include "Paciente.h"
#include <iostream>
#include <fstream>
#include <string>

void Paciente::inicializarArchivo() {
    std::ofstream archivo("pacientes.txt", std::ios::app);
    archivo.close();
}

void Paciente::registrar() {
    std::ofstream archivo("pacientes.txt", std::ios::app);
    std::string nombre, dni;
    std::cout << "Nombre del paciente: ";
    std::getline(std::cin, nombre);
    std::cout << "DNI del paciente: ";
    std::getline(std::cin, dni);
    archivo << nombre << "," << dni << "\n";
    archivo.close();
    std::cout << "Paciente registrado correctamente.\n";
}

void Paciente::buscar() {
    std::ifstream archivo("pacientes.txt");
    std::string nombre, linea;
    std::cout << "Ingrese el nombre a buscar: ";
    std::getline(std::cin, nombre);
    bool encontrado = false;
    while (std::getline(archivo, linea)) {
        if (linea.find(nombre) != std::string::npos) {
            std::cout << linea << "\n";
            encontrado = true;
        }
    }
    archivo.close();
    if (!encontrado) std::cout << "Paciente no encontrado.\n";
}

void Paciente::eliminar() {
    std::ifstream archivoEntrada("pacientes.txt");
    std::ofstream archivoSalida("temp.txt");
    std::string nombre, linea;
    std::cout << "Ingrese el nombre del paciente a eliminar: ";
    std::getline(std::cin, nombre);
    bool eliminado = false;
    while (std::getline(archivoEntrada, linea)) {
        if (linea.find(nombre) == std::string::npos) {
            archivoSalida << linea << "\n";
        }
        else {
            eliminado = true;
        }
    }
    archivoEntrada.close();
    archivoSalida.close();
    std::remove("pacientes.txt");
    std::rename("temp.txt", "pacientes.txt");
    std::cout << (eliminado ? "Paciente eliminado.\n" : "Paciente no encontrado.\n");
}

void Paciente::modificar() {
    std::ifstream archivoEntrada("pacientes.txt");
    std::ofstream archivoSalida("temp.txt");
    std::string nombre, nuevoNombre, nuevoDni, linea;
    std::cout << "Ingrese el nombre del paciente a modificar: ";
    std::getline(std::cin, nombre);
    bool modificado = false;
    while (std::getline(archivoEntrada, linea)) {
        if (linea.find(nombre) != std::string::npos) {
            std::cout << "Nuevo nombre: ";
            std::getline(std::cin, nuevoNombre);
            std::cout << "Nuevo DNI: ";
            std::getline(std::cin, nuevoDni);
            archivoSalida << nuevoNombre << "," << nuevoDni << "\n";
            modificado = true;
        }
        else {
            archivoSalida << linea << "\n";
        }
    }
    archivoEntrada.close();
    archivoSalida.close();
    std::remove("pacientes.txt");
    std::rename("temp.txt", "pacientes.txt");
    std::cout << (modificado ? "Paciente modificado.\n" : "Paciente no encontrado.\n");
}
void Paciente::asignarCita() {
    std::ofstream archivo("citas.txt", std::ios::app);
    std::string pacienteNombre, medicoNombre, fecha;

    std::cout << "Nombre del paciente: ";
    std::getline(std::cin, pacienteNombre);

    std::cout << "Nombre del médico: ";
    std::getline(std::cin, medicoNombre);

    std::cout << "Fecha de la cita (DD/MM/YYYY): ";
    std::getline(std::cin, fecha);

    archivo << pacienteNombre << "," << medicoNombre << "," << fecha << "\n";
    archivo.close();

    std::cout << "Cita asignada correctamente.\n";
}

void Paciente::verCitasDelPaciente() {
    std::ifstream archivo("citas.txt");
    std::string nombre, linea;
    std::cout << "Ingrese el nombre del paciente para ver sus citas: ";
    std::getline(std::cin, nombre);
    bool encontrado = false;

    std::cout << "\n--- Citas del Paciente ---\n";
    while (std::getline(archivo, linea)) {
        if (linea.find(nombre) != std::string::npos) {
            std::cout << linea << "\n";
            encontrado = true;
        }
    }
    archivo.close();

    if (!encontrado) {
        std::cout << "No hay citas registradas para este paciente.\n";
    }
}