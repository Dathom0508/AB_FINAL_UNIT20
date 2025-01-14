#include "ControlCSV.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void ControlCSV::escribirDatosPaciente(const std::string& nombreArchivo, const std::vector<std::string>& datosPaciente) {
    std::ofstream archivo(nombreArchivo, std::ios::app); 
    if (archivo.is_open()) {
        for (const auto& dato : datosPaciente) {
            archivo << dato << ",";
        }
        archivo << "\n"; 
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo para escribir: " << nombreArchivo << std::endl;
    }
}

std::vector<std::vector<std::string>> ControlCSV::leerDatosPaciente(const std::string& nombreArchivo) {
    std::vector<std::vector<std::string>> datos;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string item;
        std::vector<std::string> fila;

        while (std::getline(ss, item, ',')) {
            fila.push_back(item);
        }
        datos.push_back(fila);
    }
    archivo.close();
    return datos;
}
