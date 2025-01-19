#include "../include/Reporte.hpp"
#include <iostream>

void Reporte::generarHistorialClinico(const Paciente& paciente, const std::vector<Cita>& citas, const Medico& medico) {
    std::cout << "Historial Clinico de " << paciente.nombre << " " << paciente.apellidos << ":\n";
    std::cout << "Medico de Cabecera: " << medico.nombre << " " << medico.apellido << "\n";
    std::cout << "Enfermedad: " << paciente.enfermedad << "\n";
    std::cout << "Estado: " << paciente.estadoSalud << "\n";
    std::cout << "Citas Medicas:\n";
    std::cout << "ID\tFecha\tHora\tMotivo\tEstado\n";

    for (const auto& cita : citas) {
        if (cita.paciente_id == paciente.dni) { 
            std::cout << cita.id << "\t" << cita.fecha << "\t" << cita.hora << "\t" << cita.motivo << "\t" << cita.estado << "\n";
        }
    }
}

void Reporte::generarReporteMedico(const Medico& medico, const std::vector<Paciente>& pacientes) {
    std::cout << "Reporte del Medico: " << medico.nombre << " " << medico.apellido << "\n";
    std::cout << "Especialidad: " << medico.especialidad << "\n";
    std::cout << "Pacientes:\n";
    std::cout << "DNI\tNombre\tApellidos\tEstado\n";

    for (const auto &paciente : pacientes) {
        if (paciente.medicoCabeceraId == medico.id) {
            std::cout << paciente.dni << "\t" << paciente.nombre << "\t" << paciente.apellidos << "\t" << paciente.estadoSalud << "\n";
        }
    }
}

void Reporte::generarReportePacientes(CSVcontrol &csvControl) {
    auto pacientesData = csvControl.leerDatosPaciente("pacientes.csv");
    std::cout << "\nLista de Pacientes:\n";
    std::cout << "DNI\tNombre\tApellidos\tEstado Salud\n";
    for (const auto& fila : pacientesData) {
        std::cout << fila[0] << "\t" << fila[1] << "\t" << fila[2] << "\t" << fila[7] << "\n"; 
    }
}

void Reporte::generarReporteMedicos(CSVcontrol &csvControl) {
    auto medicosData = csvControl.leerDatosMedico("medicos.csv");
    std::cout << "\nLista de Medicos:\n";
    std::cout << "ID\tNombre\tApellido\tEspecialidad\n";
    for (const auto& fila : medicosData) {
        std::cout << fila[0] << "\t" << fila[1] << "\t" << fila[2] << "\t" << fila[3] << "\n"; 
    }
}