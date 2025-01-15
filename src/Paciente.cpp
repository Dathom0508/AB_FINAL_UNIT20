#include "../include/Paciente.hpp"
#include <iostream>
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
}

void Paciente::modificarPaciente(CSVcontrol& controlCSV, int dni) { 
}

void Paciente::eliminarPaciente(CSVcontrol& controlCSV, int dni) { 
}