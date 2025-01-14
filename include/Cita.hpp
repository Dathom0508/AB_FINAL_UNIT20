#ifndef CITA_HPP
#define CITA_HPP
#include <string>
#include "../include/CSVcontrol.hpp"

class Cita {
private:
    int id; 
    int paciente_id; 
    int medico_id; 
    std::string fecha; 
    std::string hora;
    std::string motivo; 
    std::string estado; 
    std::string observaciones;

public:
    Cita(int id, int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
         const std::string& motivo, const std::string& estado, const std::string& observaciones);
    
    ~Cita();

    bool guardarEnCSV(ControlCSV& controlCSV); 
};

#endif