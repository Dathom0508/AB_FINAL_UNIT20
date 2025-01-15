#include "../include/Medico.hpp"
#include <iostream>
#include <fstream>
#include "../include/CSVcontrol.hpp"

Medico::Medico(int id, const std::string &nombre, const std::string &apellido,
               const std::string &especialidad, const std::string &direccion,
               const std::string &telefono, const std::string &correoElectronico,
               const std::string &estado, const std::string &licenciaProfesional,
               const std::string &turnoTrabajo, const std::string &observaciones)
    : id(id), nombre(nombre), apellido(apellido), especialidad(especialidad),
      direccion(direccion), telefono(telefono), correoElectronico(correoElectronico),
      estado(estado), licenciaProfesional(licenciaProfesional),
      turnoTrabajo(turnoTrabajo), observaciones(observaciones) {}

void Medico::guardarEnCSV(CSVcontrol &controlCSV)
{
    std::vector<std::string> datosMedico = {
        std::to_string(id), nombre, apellido, especialidad, direccion, telefono, correoElectronico, estado, licenciaProfesional, turnoTrabajo, observaciones};
    controlCSV.escribirDatosPaciente("medicos.csv", datosMedico);
}

void Medico::mostrarTodos(CSVcontrol &controlCSV)
{
    auto datos = controlCSV.leerDatosPaciente("medicos.csv");
    std::cout << "\nLista de Médicos:\n";
    std::cout << "ID\tNombre\tApellido\tEspecialidad\tDireccion\tTelefono\tCorreo\tEstado\tLicencia\tTurno\tObservaciones\n";
    for (const auto &fila : datos)
    {
        for (const auto &dato : fila)
        {
            std::cout << dato << "\t";
        }
        std::cout << "\n";
    }
}

void Medico::buscarMedico(CSVcontrol &controlCSV, const std::string &especialidad) {
    auto datos = controlCSV.leerDatosPaciente("medicos.csv");
    bool encontrado = false;

    std::cout << "Médicos con especialidad '" << especialidad << "':\n";
    std::cout << "ID\tNombre\tApellido\tEspecialidad\tDireccion\tTelefono\tCorreo\tEstado\tLicencia\tTurno\tObservaciones\n";

    for (const auto& fila : datos) {
        if (fila[3] == especialidad) {
            for (const auto& dato : fila) {
                std::cout << dato << "\t";
            }
            std::cout << "\n";
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron médicos con la especialidad: " << especialidad << "\n";
    }
}

void Medico::eliminarMedico(CSVcontrol &controlCSV, int id) {
    auto datos = controlCSV.leerDatosPaciente("medicos.csv");
    bool encontrado = false;

    std::vector<std::vector<std::string>> nuevosDatos;
    for (const auto& fila : datos) {
        if (std::stoi(fila[0]) == id) {
            encontrado = true;
            std::cout << "Medico con ID " << id << " ha sido eliminado.\n";
            continue;
        }
        nuevosDatos.push_back(fila);
    }

    if (encontrado) {
        std::ofstream outFile("medicos.csv");
        for (const auto& fila : nuevosDatos) {
            for (const auto& dato : fila) {
                outFile << dato << ",";
            }
            outFile << "\n";
        }
        outFile.close();
    } else {
        std::cout << "Medico no encontrado con ID: " << id << "\n";
    }
}