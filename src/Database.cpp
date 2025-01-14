#include "../include/Database.hpp"
#include <iostream>

Database::Database(const std::string& dbName) : db(nullptr), dbName(dbName) {}

Database::~Database() {
    close();
}

bool Database::open() {
    if (sqlite3_open(dbName.c_str(), &db) == SQLITE_OK) {
        return true;
    } else {
        std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::executeQuery(const std::string& query) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK) {
        return true;
    } else {
        std::cerr << "Error al ejecutar la consulta: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
}

sqlite3_stmt* Database::prepareQuery(const std::string& query) {
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
    }
    return stmt;
}

// Implementación de funciones para manejar Pacientes
bool Database::addPatient(int dni, const std::string& nombre, const std::string& apellidos, const std::string& fecha_nacimiento,
                          const std::string& genero, const std::string& direccion, const std::string& telefono,
                          const std::string& contacto_emergencia, int medico_cabecera_id, const std::string& estado_salud, int edad) {
    std::string query = "INSERT INTO Pacientes (dni, nombre, apellidos, fecha_nacimiento, genero, direccion, telefono, "
                        "contacto_emergencia, medico_cabecera_id, estado_salud, edad) VALUES (" +
                        std::to_string(dni) + ", '" + nombre + "', '" + apellidos + "', '" + fecha_nacimiento + "', '" +
                        genero + "', '" + direccion + "', '" + telefono + "', '" + contacto_emergencia + "', " +
                        std::to_string(medico_cabecera_id) + ", '" + estado_salud + "', " + std::to_string(edad) + ");";
    return executeQuery(query);
}

bool Database::updatePatient(int dni, const std::string& nombre, const std::string& apellidos, const std::string& fecha_nacimiento,
                             const std::string& genero, const std::string& direccion, const std::string& telefono,
                             const std::string& contacto_emergencia, int medico_cabecera_id, const std::string& estado_salud, int edad) {
    std::string query = "UPDATE Pacientes SET nombre = '" + nombre + "', apellidos = '" + apellidos + "', "
                        "fecha_nacimiento = '" + fecha_nacimiento + "', genero = '" + genero + "', "
                        "direccion = '" + direccion + "', telefono = '" + telefono + "', "
                        "contacto_emergencia = '" + contacto_emergencia + "', medico_cabecera_id = " +
                        std::to_string(medico_cabecera_id) + ", estado_salud = '" + estado_salud + "', edad = " +
                        std::to_string(edad) + " WHERE dni = " + std::to_string(dni) + ";";
    return executeQuery(query);
}

bool Database::deletePatient(int dni) {
    std::string query = "DELETE FROM Pacientes WHERE dni = " + std::to_string(dni) + ";";
    return executeQuery(query);
}

bool Database::addDoctor(const std::string& nombre, const std::string& apellido, const std::string& especialidad,
                         const std::string& direccion, const std::string& telefono, const std::string& correo_electronico,
                         const std::string& estado, const std::string& licencia_profesional, const std::string& turno_trabajo,
                         const std::string& observaciones) {
    std::string query = "INSERT INTO Medicos (nombre, apellido, especialidad, direccion, telefono, correo_electronico, "
                        "estado, licencia_profesional, turno_trabajo, observaciones) VALUES ('" +
                        nombre + "', '" + apellido + "', '" + especialidad + "', '" + direccion + "', '" +
                        telefono + "', '" + correo_electronico + "', '" + estado + "', '" + licencia_profesional + "', '" +
                        turno_trabajo + "', '" + observaciones + "');";
    return executeQuery(query);
}

bool Database::addAppointment(int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
                              const std::string& motivo, const std::string& estado, const std::string& observaciones) {
    std::string query = "INSERT INTO Citas (paciente_id, medico_id, fecha, hora, motivo, estado, observaciones) VALUES (" +
                        std::to_string(paciente_id) + ", " + std::to_string(medico_id) + ", '" + fecha + "', '" +
                        hora + "', '" + motivo + "', '" + estado + "', '" + observaciones + "');";
    return executeQuery(query);
}

bool Database::addAdditionalData(int dni, const std::string& historial_clinico, const std::string& tipo_sangre,
                                 const std::string& alergias, const std::string& enfermedades, const std::string& observaciones) {
    std::string query = "INSERT INTO DatosAdicionales (dni, historial_clinico, tipo_sangre, alergias, enfermedades, observaciones) VALUES (" +
                        std::to_string(dni) + ", '" + historial_clinico + "', '" + tipo_sangre + "', '" +
                        alergias + "', '" + enfermedades + "', '" + observaciones + "');";
    return executeQuery(query);
}
