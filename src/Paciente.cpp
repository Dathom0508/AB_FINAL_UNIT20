#include "../include/Paciente.hpp"
#include <iostream>
#include <fstream>
#include "../include/CSVcontrol.hpp" 

Paciente::Paciente(int dni, const std::string& nombre, const std::string& apellidos,
                   const std::string& fechaIngreso, const std::string& genero,
                   const std::string& direccion, const std::string& telefono,
                   const std::string& estadoSalud, int medicoCabeceraId, int edad)
    : dni(dni), nombre(nombre), apellidos(apellidos), fechaIngreso(fechaIngreso),
      genero(genero), direccion(direccion), telefono(telefono),
      estadoSalud(estadoSalud), medicoCabeceraId(medicoCabeceraId), edad(edad) {}

void Paciente::guardarEnCSV(CSVcontrol& controlCSV) { 
    std::vector<std::string> datosPaciente = {
        std::to_string(dni), nombre, apellidos, fechaIngreso, genero, direccion, telefono, estadoSalud, std::to_string(medicoCabeceraId), std::to_string(edad)
    };
    controlCSV.escribirDatosPaciente("pacientes.csv", datosPaciente);
}

void Paciente::mostrarTodos(CSVcontrol& controlCSV) {  
    auto datos = controlCSV.leerDatosPaciente("pacientes.csv");
    std::cout << "\nLista de Pacientes:\n";
    std::cout << "DNI\tNombre\tApellidos\tFecha de Ingreso\tGénero\tDirección\tTeléfono\tEstado\tMedico ID\tEdad\n";
    for (const auto& fila : datos) {
        for (const auto& dato : fila) {
            std::cout << dato << "\t";
        }
        std::cout << "\n";
    }
}

void Paciente::buscarPaciente(CSVcontrol& controlCSV, const std::string& criterio) {
    auto datos = controlCSV.leerDatosPaciente("pacientes.csv");
    for (const auto& fila : datos) {
        if (fila[0] == criterio || fila[1] == criterio || fila[3] == criterio) { // Busca por DNI, nombre o fecha de ingreso
            std::cout << "Paciente encontrado: ";
            for (const auto& dato : fila) {
                std::cout << dato << "\t";
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado con criterio: " << criterio << "\n";
}

void Paciente::modificarPaciente(CSVcontrol& controlCSV, int dni) {
    auto datos = controlCSV.leerDatosPaciente("pacientes.csv");
    bool encontrado = false;

    for (auto& fila : datos) {
        if (std::stoi(fila[0]) == dni) {
            encontrado = true;
            std::cout << "Modificando paciente con DNI: " << dni << "\n";
            std::string nombre, apellidos, fechaIngreso, genero, direccion, telefono, estadoSalud;
            int medicoCabeceraId, edad;

            std::cout << "Nuevo Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Nuevos Apellidos: ";
            std::getline(std::cin, apellidos);
            std::cout << "Nueva Fecha de Ingreso (YYYY-MM-DD): ";
            std::getline(std::cin, fechaIngreso);
            std::cout << "Nuevo Género: ";
            std::getline(std::cin, genero);
            std::cout << "Nueva Dirección: ";
            std::getline(std::cin, direccion);
            std::cout << "Nuevo Teléfono: ";
            std::getline(std::cin, telefono);
            std::cout << "Nuevo Estado Salud: ";
            std::getline(std::cin, estadoSalud);
            std::cout << "Nuevo Médico Cabecera ID: ";
            std::cin >> medicoCabeceraId;
            std::cout << "Nueva Edad: ";
            std::cin >> edad;

            fila[1] = nombre;
            fila[2] = apellidos;
            fila[3] = fechaIngreso;
            fila[4] = genero;
            fila[5] = direccion;
            fila[6] = telefono;
            fila[7] = estadoSalud;
            fila[8] = std::to_string(medicoCabeceraId);
            fila[9] = std::to_string(edad);
            break;
        }
    }

    if (encontrado) {
        std::ofstream outFile("pacientes.csv");
        for (const auto& fila : datos) {
            for (const auto& dato : fila) {
                outFile << dato << ",";
            }
            outFile << "\n";
        }
        outFile.close();
        std::cout << "Paciente modificado exitosamente.\n";
    } else {
        std::cout << "Paciente no encontrado con DNI: " << dni << "\n";
    }
}

void Paciente::eliminarPaciente(CSVcontrol& controlCSV, int dni) {
    auto datos = controlCSV.leerDatosPaciente("pacientes.csv");
    bool encontrado = false;

    std::vector<std::vector<std::string>> nuevosDatos;
    for (const auto& fila : datos) {
        if (std::stoi(fila[0]) == dni) {
            encontrado = true;
            std::cout << "Paciente con DNI " << dni << " ha sido eliminado.\n";
            continue; 
        }
        nuevosDatos.push_back(fila); 
    }

    if (encontrado) {
        std::ofstream outFile("pacientes.csv");
        for (const auto& fila : nuevosDatos) {
            for (const auto& dato : fila) {
                outFile << dato << ",";
            }
            outFile << "\n";
        }
        outFile.close();
    } else {
        std::cout << "Paciente no encontrado con DNI: " << dni << "\n";
    }
}