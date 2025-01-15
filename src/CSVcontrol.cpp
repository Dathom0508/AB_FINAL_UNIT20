#include "../include/CSVcontrol.hpp"
#include <fstream>
#include <sstream>


void CSVcontrol::escribirDatosPaciente(const std::string& archivo, const std::vector<std::string>& datos) {
    std::ofstream outFile(archivo, std::ios::app);
    if (outFile.is_open()) {
        for (const auto& dato : datos) {
            outFile << dato << ",";
        }
        outFile << "\n";
        outFile.close();
    }
}

void CSVcontrol::escribirDatosCita(const std::string& archivo, const std::vector<std::string>& datos) {
    std::ofstream outFile(archivo, std::ios::app);
    if (outFile.is_open()) {
        for (const auto& dato : datos) {
            outFile << dato << ",";
        }
        outFile << "\n";
        outFile.close();
    }
}

std::vector<std::vector<std::string>> CSVcontrol::leerDatosPaciente(const std::string& archivo) {
    std::vector<std::vector<std::string>> datos;
    std::ifstream inFile(archivo);
    std::string linea;
    while (std::getline(inFile, linea)) {
        std::stringstream ss(linea);
        std::string dato;
        std::vector<std::string> fila;
        while (std::getline(ss, dato, ',')) {
            fila.push_back(dato);
        }
        datos.push_back(fila);
    }
    return datos;
}

std::vector<std::vector<std::string>> CSVcontrol::leerDatosCita(const std::string& archivo) {
    std::vector<std::vector<std::string>> datos;
    std::ifstream inFile(archivo);
    std::string linea;
    while (std::getline(inFile, linea)) {
        std::stringstream ss(linea);
        std::string dato;
        std::vector<std::string> fila;
        while (std::getline(ss, dato, ',')) {
            fila.push_back(dato);
        }
        datos.push_back(fila);
    }
    return datos;
}