#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include "../include/CSVcontrol.hpp"
#include <string>
#include <vector>

class Paciente {
public:
    int dni;
    std::string nombre;
    std::string apellidos;
    std::string fechaIngreso;
    std::string genero;
    std::string direccion;
    std::string telefono;
    std::string estadoSalud;
    int medicoCabeceraId;
    int edad;

    Paciente(int dni, const std::string& nombre, const std::string& apellidos,
             const std::string& fechaIngreso, const std::string& genero,
             const std::string& direccion, const std::string& telefono,
             const std::string& estadoSalud, int medicoCabeceraId, int edad);

    void guardarEnCSV(CSVcontrol& csvControl);
    static void mostrarTodos(CSVcontrol& csvControl);
    static void buscarPaciente(CSVcontrol& csvControl, const std::string& criterio);
    static void modificarPaciente(CSVcontrol& csvControl, int dni);
    static void eliminarPaciente(CSVcontrol& csvControl, int dni);
};

#endif