#include "../include/Cita.hpp"
#include <iostream>
#include "../include/CSVcontrol.hpp"
#include <fstream>

Cita::Cita(int id, int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
           const std::string& motivo, const std::string& estado, const std::string& observaciones)
    : id(id), paciente_id(paciente_id), medico_id(medico_id), fecha(fecha),
      hora(hora), motivo(motivo), estado(estado), observaciones(observaciones) {}

Cita::~Cita() {}

bool Cita::guardarEnCSV(CSVcontrol& csvControl) {
    std::vector<std::string> datosCita = {
        std::to_string(id), std::to_string(paciente_id), std::to_string(medico_id), fecha, hora, motivo, estado, observaciones
    };
    csvControl.escribirDatosCita("citas.csv", datosCita);
    return true;
}

void Cita::mostrarTodos(CSVcontrol& csvControl) {
    auto datos = csvControl.leerDatosCita("citas.csv");
    std::cout << "\nLista de Citas:\n";
    std::cout << "ID\tPaciente ID\tMédico ID\tFecha\tHora\tMotivo\tEstado\tObservaciones\n";
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
            std::cout << "Cita encontrada: ";
            for (const auto& dato : fila) {
                std::cout << dato << "\t";
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Cita no encontrada con ID: " << id << "\n";
}