// Cita.hpp
#ifndef CITA_HPP
#define CITA_HPP

#include <string>
#include <vector>
#include "../include/CSVcontrol.hpp"

class Cita {
public:
    int id;
    int paciente_id;
    int medico_id;
    std::string fecha;
    std::string hora;
    std::string motivo;
    std::string estado;
    std::string observaciones;

    Cita(int id, int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
         const std::string& motivo, const std::string& estado, const std::string& observaciones);

    ~Cita();

    bool guardarEnCSV(CSVcontrol& csvControl);
    static void mostrarTodas(CSVcontrol& csvControl); 
    static void buscarCita(CSVcontrol& csvControl, int id);
    static void modificarCita(CSVcontrol& csvControl, int id);
};

#endif