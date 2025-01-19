#include "../include/Cita.hpp"
#include <iostream>
#include "../include/CSVcontrol.hpp"
#include <fstream>
#include <sstream>

Cita::Cita(int id, int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
           const std::string& motivo, const std::string& estado, const std::string& observaciones)
    : id(id), paciente_id(paciente_id), medico_id(medico_id), fecha(fecha),
      hora(hora), motivo(motivo), estado(estado), observaciones(observaciones) {}

Cita::~Cita() {}

bool Cita::guardarEnCSV(CSVcontrol& csvControl) {
    std::vector<std::string> datos = {
        std::to_string(id),
        std::to_string(paciente_id),
        std::to_string(medico_id),
        fecha,
        hora,
        motivo,
        estado,
        observaciones
    };
    csvControl.escribirDatosCita("citas.csv", datos);
    return true; 
}

void Cita::mostrarTodas(CSVcontrol& csvControl) {
    auto datos = csvControl.leerDatosCita("citas.csv");
    std::cout << "\nLista de Citas:\n";
    std::cout << "ID\tPaciente ID\tMedico ID\tFecha\tHora\tMotivo\tEstado\tObservaciones\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t"; 
        }
        std::cout << "\n"; 
    }
}

void Cita::buscarCita(CSVcontrol& csvControl, int id) {
    auto datos = csvControl.leerDatosCita("citas.csv");
    for (const auto& fila : datos) {
        if (std::stoi(fila[0]) == id) { 
            std::cout << "Cita encontrada:\n";
            std::cout << "ID: " << fila[0] << ", Paciente ID: " << fila[1] << ", Medico ID: " << fila[2]
                      << ", Fecha: " << fila[3] << ", Hora: " << fila[4] << ", Motivo: " << fila[5]
                      << ", Estado: " << fila[6] << ", Observaciones: " << fila[7] << "\n";
            return;
        }
    }
    std::cout << "Cita no encontrada con ID: " << id << "\n";
}

void Cita::modificarCita(CSVcontrol& csvControl, int id) {
    auto datos = csvControl.leerDatosCita("citas.csv");
    bool encontrado = false;

    for (auto& fila : datos) {
        if (std::stoi(fila[0]) == id) { 
            encontrado = true;
            std::cout << "Cita encontrada. Ingrese nuevos datos:\n";
            std::cout << "Fecha: ";
            std::getline(std::cin, fila[3]);
            std::cout << "Hora: ";
            std::getline(std::cin, fila[4]);
            std::cout << "Motivo: ";
            std::getline(std::cin, fila[5]);
            std::cout << "Estado: ";
            std::getline(std::cin, fila[6]);
            std::cout << "Observaciones: ";
            std::getline(std::cin, fila[7]);
            break;
        }
    }

    if (encontrado) {
        std::ofstream outFile("citas.csv");
        for (const auto& fila : datos) {
            for (size_t i = 0; i < fila.size(); ++i) {
                outFile << fila[i];
                if (i < fila.size() - 1) outFile << ",";
            }
            outFile << "\n";
        }
        outFile.close();
        std::cout << "Cita modificada exitosamente.\n";
    } else {
        std::cout << "Cita no encontrada con ID: " << id << "\n";
    }
}