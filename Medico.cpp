#include "Medico.h"
#include <iostream>
#include <fstream>

void Medico::inicializarArchivo() {
    std::ofstream archivo("medicos.txt", std::ios::app);
    archivo.close();
}

void Medico::registrar() {
    std::ofstream archivo("medicos.txt", std::ios::app);
    std::string nombre, especialidad;
    std::cout << "Nombre del m�dico: ";
    std::getline(std::cin, nombre);
    std::cout << "Especialidad del m�dico: ";
    std::getline(std::cin, especialidad);
    archivo << nombre << "," << especialidad << "\n";
    archivo.close();
    std::cout << "M�dico registrado correctamente.\n";
}

void Medico::buscar() {
    std::ifstream archivo("medicos.txt");
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
    if (!encontrado) std::cout << "M�dico no encontrado.\n";
}

void Medico::eliminar() {
    std::ifstream archivoEntrada("medicos.txt");
    std::ofstream archivoSalida("temp.txt");
    std::string nombre, linea;
    std::cout << "Ingrese el nombre del m�dico a eliminar: ";
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
    std::remove("medicos.txt");
    std::rename("temp.txt", "medicos.txt");
    std::cout << (eliminado ? "M�dico eliminado.\n" : "M�dico no encontrado.\n");
}

void Medico::modificar() {
    std::ifstream archivoEntrada("medicos.txt");
    std::ofstream archivoSalida("temp.txt");
    std::string nombre, nuevoNombre, nuevaEspecialidad, linea;
    std::cout << "Ingrese el nombre del m�dico a modificar: ";
    std::getline(std::cin, nombre);
    bool modificado = false;
    while (std::getline(archivoEntrada, linea)) {
        if (linea.find(nombre) != std::string::npos) {
            std::cout << "Nuevo nombre: ";
            std::getline(std::cin, nuevoNombre);
            std::cout << "Nueva especialidad: ";
            std::getline(std::cin, nuevaEspecialidad);
            archivoSalida << nuevoNombre << "," << nuevaEspecialidad << "\n";
            modificado = true;
        }
        else {
            archivoSalida << linea << "\n";
        }
    }
    archivoEntrada.close();
    archivoSalida.close();
    std::remove("medicos.txt");
    std::rename("temp.txt", "medicos.txt");
    std::cout << (modificado ? "M�dico modificado.\n" : "M�dico no encontrado.\n");
}
