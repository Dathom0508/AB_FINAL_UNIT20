#include "../include/Medico.hpp"
#include <iostream>
#include "../include/CSVcontrol.hpp"

Medico::Medico(int id, const std::string& nombre, const std::string& apellido,
               const std::string& especialidad, const std::string& direccion,
               const std::string& telefono, const std::string& correoElectronico,
               const std::string& estado, const std::string& licenciaProfesional,
               const std::string& turnoTrabajo, const std::string& observaciones)
    : id(id), nombre(nombre), apellido(apellido), especialidad(especialidad),
      direccion(direccion), telefono(telefono), correoElectronico(correoElectronico),
      estado(estado), licenciaProfesional(licenciaProfesional),
      turnoTrabajo(turnoTrabajo), observaciones(observaciones) {}

void Medico::guardarEnCSV(ControlCSV& controlCSV) {
    std::vector<std::string> datosMedico = {
        std::to_string(id), nombre, apellido, especialidad, direccion, telefono, correoElectronico, estado, licenciaProfesional, turnoTrabajo, observaciones
    };
    controlCSV.escribirDatosPaciente("medicos.csv", datosMedico);
}

void Medico::mostrarTodos(ControlCSV& controlCSV) {
    auto datos = controlCSV.leerDatosPaciente("medicos.csv");
    std::cout << "\nLista de Médicos:\n";
    std::cout << "ID\tNombre\tApellido\tEspecialidad ```cpp
\tDirección\tTeléfono\tCorreo\tEstado\tLicencia\tTurno\tObservaciones\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t";
        }
        std::cout << "\n";
    }
}