#include "../include/CSVcontrol.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include "CSVcontrol.hpp"

void CSVcontrol::escribirDatosPaciente(const std::string &archivo, const std::vector<std::string> &datos) {
    std::ofstream outFile(archivo, std::ios::app); 
    if (outFile.is_open()) {
        for (const auto &dato : datos) {
            outFile << dato << ","; 
        }
        outFile << "\n"; 
        outFile.close(); 
    } else {
        std::cerr << "Error al abrir el archivo: " << archivo << "\n"; 
    }
}

void CSVcontrol::escribirDatosCita(const std::string &archivo, const std::vector<std::string> &datos) {
    std::ofstream outFile(archivo, std::ios::app);
    if (outFile.is_open()) {
        for (const auto &dato : datos) {
            outFile << dato << ","; 
        }
        outFile << "\n"; 
        outFile.close(); 
    } else {
        std::cerr << "Error al abrir el archivo: " << archivo << "\n"; 
    }
}

std::vector<std::vector<std::string>> CSVcontrol::leerDatosPaciente(const std::string &archivo) {
    std::vector<std::vector<std::string>> datos;
    std::ifstream inFile(archivo); 
    std::string linea;

    if (!inFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo << "\n"; 
        return datos;                                                  
    }

    while (std::getline(inFile, linea)) { 
        std::stringstream ss(linea);
        std::string dato;
        std::vector<std::string> fila;

        while (std::getline(ss, dato, ',')) { 
            fila.push_back(dato);
        }
        datos.push_back(fila); 
    }
    inFile.close();
    return datos;   
}

std::vector<std::vector<std::string>> CSVcontrol::leerDatosCita(const std::string &archivo) {
    std::vector<std::vector<std::string>> datos;
    std::ifstream inFile(archivo); 
    std::string linea;

    if (!inFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo << "\n"; 
        return datos;                                                 
    }

    while (std::getline(inFile, linea)) { 
        std::stringstream ss(linea);
        std::string dato;
        std::vector<std::string> fila;

        while (std::getline(ss, dato, ',')) { 
            fila.push_back(dato);
        }
        datos.push_back(fila); 
    }
    inFile.close(); 
    return datos;  
}

std::vector<std::vector<std::string>> CSVcontrol::leerDatosMedico(const std::string &archivo) {
    std::vector<std::vector<std::string>> datos;
    std::ifstream inFile(archivo); 
    std::string linea;

    if (!inFile.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo << "\n"; 
        return datos;                                                  
    }

    while (std::getline(inFile, linea)) { 
        std::stringstream ss(linea);
        std::string dato;
        std::vector<std::string> fila;

        while (std::getline(ss, dato, ',')) { 
            fila.push_back(dato);
        }
        datos.push_back(fila); 
    }
    inFile.close();
    return datos;   
}

void CSVcontrol::escribirDatosMedico(const std::string &archivo, const std::vector<std::string> &datos) {
    std::ofstream outFile(archivo, std::ios::app); 
    if (outFile.is_open()) {
        for (const auto &dato : datos) {
            outFile << dato << ","; 
        }
        outFile << "\n"; 
        outFile.close(); 
    } else {
        std::cerr << "Error al abrir el archivo: " << archivo << "\n"; 
    }
}

void CSVcontrol::mostrarTodosPacientes(const std::string &archivo) {
    auto datos = leerDatosPaciente(archivo);
    std::cout << "\nLista de Pacientes:\n";
    std::cout << "DNI\tNombre\tApellidos\tFecha de Ingreso\tGenero\tDireccion\tTelefono\tEstado Salud\tMedico ID\tEdad\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t"; 
        }
        std::cout << "\n"; 
    }
}

void CSVcontrol::mostrarTodosMedicos(const std::string &archivo) {
    auto datos = leerDatosMedico(archivo);
    std::cout << "\nLista de Medicos:\n";
    std::cout << "ID\tNombre\tApellido\tEspecialidad\tDireccion\tTelefono\tCorreo\tEstado\tLicencia\tTurno\tObservaciones\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t"; 
        }
        std::cout << "\n"; 
    }
}

void CSVcontrol::mostrarTodasCitas(const std::string &archivo) {
    auto datos = leerDatosCita(archivo);
    std::cout << "\nLista de Citas:\n";
    std::cout << "ID\tPaciente ID\tMedico ID\tFecha\tHora\tMotivo\tEstado\tObservaciones\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t"; 
        }
        std::cout << "\n"; 
    }
}