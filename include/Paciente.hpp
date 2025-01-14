#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include "../include/CSVcontrol.hpp"
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
    std::string estadoSalud;
    int medicoCabeceraId;
    int edad;

    Paciente(int dni, const std::string& nombre, const std::string& apellidos,
             const std::string& fechaNacimiento, const std::string& genero,
             const std::string& direccion, const std::string& telefono,
             const std::string& estadoSalud, int medicoCabeceraId, int edad);

    void guardarEnCSV(ControlCSV& controlCSV);
    static void mostrarTodos(ControlCSV& controlCSV);
};

#endif 