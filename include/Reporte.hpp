#ifndef REPORTE_HPP
#define REPORTE_HPP

#include "../include/Paciente.hpp"
#include "../include/Medico.hpp"
#include "../include/Cita.hpp"
#include "../include/CSVcontrol.hpp"
#include <vector>

class Reporte {
public:
    static void generarHistorialClinico(const Paciente& paciente, const std::vector<Cita>& citas, const Medico& medico);   
    static void generarReporteMedico(const Medico& medico, const std::vector<Paciente>& pacientes);   
    static void generarReportePacientes(CSVcontrol &csvControl); 
    static void generarReporteMedicos(CSVcontrol &csvControl);
};

#endif