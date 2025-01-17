#include "../include/Paciente.hpp"
#include "../include/Medico.hpp"
#include "../include/Cita.hpp"
#include "../include/CSVcontrol.hpp"
#include <iostream>
#include <limits>
#include <fstream>

void menuPrincipal()
{
    std::cout << "\nSistema Hospitalario\n";
    std::cout << "1. Gestion de Pacientes\n";
    std::cout << "2. Gestion de Medicos\n";
    std::cout << "3. Gestion de Citas Medicas\n";
    std::cout << "4. Salir\n";
    std::cout << "Elige una opcion: ";
}

void menuPacientes(CSVcontrol &csvControl)
{
    int opcion = 0;

    while (opcion != 5)
    {
        std::cout << "\nMenu Pacientes\n";
        std::cout << "1. Anadir Paciente\n";
        std::cout << "2. Mostrar Pacientes\n";
        std::cout << "3. Buscar Paciente\n";
        std::cout << "4. Modificar Paciente\n";
        std::cout << "5. Volver al menu principal\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida. Intente de nuevo.\n";
            continue;
        }

        if (opcion == 1)
        {
            int dni, medicoCabeceraId, edad;
            std::string nombre, apellidos, fechaIngreso, genero, direccion, telefono, estadoSalud;

            std::cout << "DNI: ";
            std::cin >> dni;
            std::cin.ignore();
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Apellidos: ";
            std::getline(std::cin, apellidos);
            std::cout << "Fecha de Ingreso (YYYY-MM-DD): ";
            std::getline(std::cin, fechaIngreso);
            std::cout << "Genero: ";
            std::getline(std::cin, genero);
            std::cout << "Direccion: ";
            std::getline(std::cin, direccion);
            std::cout << "Telefono: ";
            std::getline(std::cin, telefono);
            std::cout << "Estado Salud: ";
            std::getline(std::cin, estadoSalud);
            std::cout << "Medico Cabecera ID: ";
            std::cin >> medicoCabeceraId;
            std::cout << "Edad: ";
            std::cin >> edad;

            Paciente p(dni, nombre, apellidos, fechaIngreso, genero, direccion, telefono, estadoSalud, medicoCabeceraId, edad);
            p.guardarEnCSV(csvControl);
        }
        else if (opcion == 2)
        {
            Paciente::mostrarTodos(csvControl);
        }
        else if (opcion == 3)
        {
            std::string criterio;
            std::cout << "Ingrese el criterio de busqueda (nombre, DNI, fecha de ingreso): ";
            std::cin.ignore();
            std::getline(std::cin, criterio);
            Paciente::buscarPaciente(csvControl, criterio);
        }
        else if (opcion == 4)
        {
            int dni;
            std::cout << "Ingrese el DNI del paciente a modificar: ";
            std::cin >> dni;
            Paciente::modificarPaciente(csvControl, dni);
        }
        else if (opcion == 5)
        {
            std::cout << "Volviendo al menu principal...\n";
        }
        else
        {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}
void menuMedicos(CSVcontrol &csvControl)
{
    int opcion = 0;

    while (opcion != 5)
    {
        std::cout << "\nMenu Medicos\n";
        std::cout << "1. Anadir Medico\n";
        std::cout << "2. Mostrar Medicos\n";
        std::cout << "3. Buscar Medico\n";
        std::cout << "4. Eliminar Medico\n";
        std::cout << "5. Volver al menu principal\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida. Intente de nuevo.\n";
            continue;
        }

        if (opcion == 1)
        {
            int id;
            std::string nombre, apellido, especialidad, direccion, telefono, correoElectronico, estado, licenciaProfesional, turnoTrabajo, observaciones;

            std::cout << "ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Apellido: ";
            std::getline(std::cin, apellido);
            std::cout << "Especialidad: ";
            std::getline(std::cin, especialidad);
            std::cout << "Direccion: ";
            std::getline(std::cin, direccion);
            std::cout << "Telefono: ";
            std::getline(std::cin, telefono);
            std::cout << "Correo Electronico: ";
            std::getline(std::cin, correoElectronico);
            std::cout << "Estado: ";
            std::getline(std::cin, estado);
            std::cout << "Licencia Profesional: ";
            std::getline(std::cin, licenciaProfesional);
            std::cout << "Turno de Trabajo: ";
            std::getline(std::cin, turnoTrabajo);
            std::cout << "Observaciones: ";
            std::getline(std::cin, observaciones);

            Medico m(id, nombre, apellido, especialidad, direccion, telefono, correoElectronico, estado, licenciaProfesional, turnoTrabajo, observaciones);
            m.guardarEnCSV(csvControl);
        }
        else if (opcion == 2)
        {
            Medico::mostrarTodos(csvControl);
        }
        else if (opcion == 3)
        {
            std::string criterio;
            std::cout << "Ingrese el criterio de busqueda (nombre, ID, especialidad): ";
            std::cin.ignore();
            std::getline(std::cin, criterio);
            Medico::buscarMedico(csvControl, criterio);
        }
        else if (opcion == 4)
        {
            int id;
            std::cout << "Ingrese el ID del medico a eliminar: ";
            std::cin >> id;
            Medico::eliminarMedico(csvControl, id);
        }
        else if (opcion == 5)
        {
            std::cout << "Volviendo al menu principal...\n";
        }
        else
        {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}

void menuCitas(CSVcontrol &csvControl)
{
    int opcion = 0;

    while (opcion != 4)
    {
        std::cout << "\nMenu Citas Medicas\n";
        std::cout << "1. Anadir Cita\n";
        std::cout << "2. Mostrar Citas\n";
        std::cout << "3. Buscar Cita\n";
        std::cout << "4. Modificar Cita\n";
        std::cout << "5. Volver al menu principal\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida. Intente de nuevo.\n";
            continue;
        }

        if (opcion == 1)
        {
            int idCita, dniPaciente, idMedico;
            std::string fecha, hora, motivo, estado = "Pendiente", observaciones = "Sin observaciones";

            std::cout << "ID de Cita: ";
            std::cin >> idCita;
            std::cout << "DNI del Paciente: ";
            std::cin >> dniPaciente;
            std::cout << "ID del Medico: ";
            std::cin >> idMedico;
            std::cout << "Fecha (YYYY-MM-DD): ";
            std::cin >> fecha;
            std::cout << "Hora (HH:MM): ";
            std::cin >> hora;
            std::cout << "Motivo: ";
            std::cin.ignore();
            std::getline(std::cin, motivo);

            Cita c(idCita, dniPaciente, idMedico, fecha, hora, motivo, estado, observaciones);
            c.guardarEnCSV(csvControl);
        }
        else if (opcion == 2)
        {
            Cita::mostrarTodos(csvControl);
        }
        else if (opcion == 3)
        {
            int idCita;
            std::cout << "Ingrese el ID de la cita a buscar: ";
            std::cin >> idCita;
            Cita::buscarCita(csvControl, idCita);
        }
        else if (opcion == 4)
        {
            int idCita;
            std::cout << "Ingrese el ID de la cita a modificar: ";
            std::cin >> idCita;
            Cita::modificarCita(csvControl, idCita);
        }
        else if (opcion == 5)
        {
            std::cout << "Volviendo al menu principal...\n";
        }
        else
        {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}


int main()
{
    CSVcontrol csvControl;
    int opcion = 0;

    while (opcion != 4)
    {
        menuPrincipal();
        std::cin >> opcion;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (opcion == 1)
        {
            menuPacientes(csvControl);
        }
        else if (opcion == 2)
        {
            menuMedicos(csvControl);
        }
        else if (opcion == 3)
        {
            menuCitas(csvControl);
        }
        else if (opcion == 4)
        {
            std::cout << "Saliendo del sistema...\n";
        }
        else
        {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }

    return 0;
}