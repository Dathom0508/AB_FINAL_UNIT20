#include "../include/Cita.hpp"
#include <iostream>
#include "../include/ControlCSV.hpp"

Cita::Cita(int id, int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
           const std::string& motivo, const std::string& estado, const std::string& observaciones)
    : id(id), paciente_id(paciente_id), medico_id(medico_id), fecha(fecha), hora(hora),
      motivo(motivo), estado(estado), observaciones(observaciones) {}

Cita::~Cita() {}

bool Cita::guardarEnCSV(ControlCSV& controlCSV) {
    std::vector<std::string> datosCita = {
        std::to_string(paciente_id), std::to_string(medico_id), fecha, hora, motivo, estado, observaciones
    };
    controlCSV.escribirDatosCita("citas.csv", datosCita);
    return true;
}