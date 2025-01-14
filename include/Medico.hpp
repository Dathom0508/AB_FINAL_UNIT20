#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "Database.hpp"
#include <string>

class Medico {
public:
    int id;
    std::string nombre;
    std::string apellido;
    std::string especialidad;
    std::string direccion;
    std::string telefono;
    std::string correoElectronico;
    std::string estado;
    std::string licenciaProfesional;
    std::string turnoTrabajo;
    std::string observaciones;

    Medico(int id, const std::string& nombre, const std::string& apellido,
           const std::string& especialidad, const std::string& direccion,
           const std::string& telefono, const std::string& correoElectronico,
           const std::string& estado, const std::string& licenciaProfesional,
           const std::string& turnoTrabajo, const std::string& observaciones);

    void guardarEnDB(Database& db);
    static void mostrarTodos(Database& db);
};

#endif 