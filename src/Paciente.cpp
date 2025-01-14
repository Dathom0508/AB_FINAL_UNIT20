#include "../include/Paciente.hpp"
#include <iostream>
#include "../include/CSVcontrol.hpp"

Paciente::Paciente(int id, const std::string& nombre, const std::string& apellido,
                   const std::string& direccion, const std::string& telefono,
                   const std::string& correoElectronico, const std::string& estado,
                   const std::string& observaciones)
    : id(id), nombre(nombre), apellido(apellido), direccion(direccion),
      telefono(telefono), correoElectronico(correoElectronico), estado(estado),
      observaciones(observaciones) {}

void Paciente::guardarEnCSV(ControlCSV& controlCSV) {
    std::vector<std::string> datosPaciente = {
        std::to_string(id), nombre, apellido, direccion, telefono, correoElectronico, estado, observaciones
    };
    controlCSV.escribirDatosPaciente("pacientes.csv", datosPaciente);
}

void Paciente::mostrarTodos(ControlCSV& controlCSV) {
    auto datos = controlCSV.leerDatosPaciente("pacientes.csv");
    std::cout << "\nLista de Pacientes:\n";
    std::cout << "ID\tNombre\tApellido\tDirección\tTeléfono\tCorreo\tEstado\tObservaciones\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t";
        }
        std::cout << "\n";
    }
}