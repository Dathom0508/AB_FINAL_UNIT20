#ifndef CONTROLCSV_HPP
#define CONTROLCSV_HPP

#include <string>
#include <vector>

class ControlCSV {
public:
    void escribirDatosPaciente(const std::string& nombreArchivo, const std::vector<std::string>& datosPaciente);
    std::vector<std::vector<std::string>> leerDatosPaciente(const std::string& nombreArchivo);
    void escribirDatosCita(const std::string& nombreArchivo, const std::vector<std::string>& datosCita);
    std::vector<std::vector<std::string>> leerDatosCita(const std::string& nombreArchivo);
};

#endif