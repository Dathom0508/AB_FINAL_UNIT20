#include "../include/Medico.hpp"
#include <iostream>

Medico::Medico(int id, const std::string& nombre, const std::string& apellido,
               const std::string& especialidad, const std::string& direccion,
               const std::string& telefono, const std::string& correoElectronico,
               const std::string& estado, const std::string& licenciaProfesional,
               const std::string& turnoTrabajo, const std::string& observaciones)
    : id(id), nombre(nombre), apellido(apellido), especialidad(especialidad),
      direccion(direccion), telefono(telefono), correoElectronico(correoElectronico),
      estado(estado), licenciaProfesional(licenciaProfesional),
      turnoTrabajo(turnoTrabajo), observaciones(observaciones) {}

void Medico::guardarEnDB(Database& db) {
    std::string query = "INSERT INTO Medicos (nombre, apellido, especialidad, direccion, telefono, correo_electronico, estado, licencia_profesional, turno_trabajo, observaciones) "
                        "VALUES ('" + nombre + "', '" + apellido + "', '" + especialidad + "', '" +
                        direccion + "', '" + telefono + "', '" + correoElectronico + "', '" +
                        estado + "', '" + licenciaProfesional + "', '" + turnoTrabajo + "', '" +
                        observaciones + "');";

    if (db.executeQuery(query)) {
        std::cout << "Médico guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar el médico." << std::endl;
    }
}

void Medico::mostrarTodos(Database& db) {
    std::string query = "SELECT id, nombre, apellido, especialidad FROM Medicos;";
    sqlite3_stmt* stmt = db.prepareQuery(query);

    std::cout << "\nLista de Médicos:\n";
    std::cout << "ID\tNombre\tApellido\tEspecialidad\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string apellido = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string especialidad = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        std::cout << id << "\t" << nombre << "\t" << apellido << "\t" << especialidad << std::endl;
    }
    sqlite3_finalize(stmt);
}