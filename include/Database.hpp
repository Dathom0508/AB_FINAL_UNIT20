#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <sqlite3.h>
#include <string>

class Database {
private:
    sqlite3* db;
    std::string dbName;

public:
    Database(const std::string& dbName);
    ~Database();

    bool open();
    void close();
    bool executeQuery(const std::string& query);
    sqlite3_stmt* prepareQuery(const std::string& query);

 bool addPatient(int dni, const std::string& nombre, const std::string& apellidos, const std::string& fecha_nacimiento,
                    const std::string& genero, const std::string& direccion, const std::string& telefono,
                    const std::string& contacto_emergencia, int medico_cabecera_id, const std::string& estado_salud, int edad);
    
    bool updatePatient(int dni, const std::string& nombre, const std::string& apellidos, const std::string& fecha_nacimiento,
                       const std::string& genero, const std::string& direccion, const std::string& telefono,
                       const std::string& contacto_emergencia, int medico_cabecera_id, const std::string& estado_salud, int edad);
    
    bool deletePatient(int dni);

    bool addDoctor(const std::string& nombre, const std::string& apellido, const std::string& especialidad,
                   const std::string& direccion, const std::string& telefono, const std::string& correo_electronico,
                   const std::string& estado, const std::string& licencia_profesional, const std::string& turno_trabajo,
                   const std::string& observaciones);
    
    bool addAppointment(int paciente_id, int medico_id, const std::string& fecha, const std::string& hora,
                        const std::string& motivo, const std::string& estado, const std::string& observaciones);
    
    bool addAdditionalData(int dni, const std::string& historial_clinico, const std::string& tipo_sangre,
                           const std::string& alergias, const std::string& enfermedades, const std::string& observaciones);
};

#endif 
