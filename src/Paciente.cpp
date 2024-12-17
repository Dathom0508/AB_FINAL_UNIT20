#include "Paciente.hpp"
#include <iostream>

Paciente::Paciente(int dni, const std::string &nombre, const std::string &apellidos,
                   const std::string &fechaNacimiento, const std::string &genero,
                   const std::string &direccion, const std::string &telefono)
    : dni(dni), nombre(nombre), apellidos(apellidos), fechaNacimiento(fechaNacimiento),
      genero(genero), direccion(direccion), telefono(telefono) {}

void Paciente::guardarEnDB(Database &db)
{
    std::string query = "INSERT INTO Pacientes (dni, nombre, apellidos, fecha_nacimiento, genero, direccion, telefono) "
                        "VALUES (" +
                        std::to_string(dni) + ", '" + nombre + "', '" + apellidos + "', '" +
                        fechaNacimiento + "', '" + genero + "', '" + direccion + "', '" + telefono + "');";

    if (db.executeQuery(query))
    {
        std::cout << "Paciente guardado correctamente." << std::endl;
    }
    else
    {
        std::cerr << "Error al guardar el paciente." << std::endl;
    }
}

void Paciente::mostrarTodos(Database &db)
{
    std::string query = "SELECT dni, nombre, apellidos FROM Pacientes;";
    sqlite3_stmt *stmt = db.prepareQuery(query);

    std::cout << "\nLista de Pacientes:\n";
    std::cout << "DNI\tNombre\tApellidos\n";
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int dni = sqlite3_column_int(stmt, 0);
        std::string nombre = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string apellidos = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

        std::cout << dni << "\t" << nombre << "\t" << apellidos << std::endl;
    }
    sqlite3_finalize(stmt);
}
