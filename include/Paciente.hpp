#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include "Database.hpp"
#include <string>

class Paciente {
public:
    int dni;
    std::string nombre;
    std::string apellidos;
    std::string fechaNacimiento;
    std::string genero;
    std::string direccion;
    std::string telefono;

    Paciente(int dni, const std::string& nombre, const std::string& apellidos,
             const std::string& fechaNacimiento, const std::string& genero,
             const std::string& direccion, const std::string& telefono);

    void guardarEnDB(Database& db);
    static void mostrarTodos(Database& db);
};

#endif