#include "../include/Cita.hpp"
#include <iostream>

Cita::Cita(int id, int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
           const std::string& motivo, const std::string& estado, const std::string& observaciones)
    : id(id), paciente_id(paciente_id), medico_id(medico_id), fecha(fecha), hora(hora),
      motivo(motivo), estado(estado), observaciones(observaciones) {}

Cita::~Cita() {}

bool Cita::guardarEnDB(Database& db) {
    std::string query = "INSERT INTO Citas (paciente_id, medico_id, fecha, hora, motivo, estado, observaciones) VALUES (" +
                        std::to_string(paciente_id) + ", " + std::to_string(medico_id) + ", '" + fecha + "', '" +
                        hora + "', '" + motivo + "', '" + estado + "', '" + observaciones + "');";
    return db.executeQuery(query);
}

bool Cita::actualizarEnDB(Database& db) {
    std::string query = "UPDATE Citas SET paciente_id = " + std::to_string(paciente_id) +
                        ", medico_id = " + std::to_string(medico_id) +
                        ", fecha = '" + fecha + "', hora = '" + hora +
                        "', motivo = '" + motivo + "', estado = '" + estado +
                        "', observaciones = '" + observaciones + "' WHERE id = " + std::to_string(id) + ";";
    return db.executeQuery(query);
}

bool Cita::eliminarDeDB(Database& db) {
    std::string query = "DELETE FROM Citas WHERE id = " + std::to_string(id) + ";";
    return db.executeQuery(query);
}