#include "../include/Paciente.hpp"
#include "../include/Medico.hpp"
#include "../include/CSVcontrol.hpp"
#include <iostream>

void menuPrincipal() {
    std::cout << "\n Sistema Hospitalario \n";
    std::cout << "1. Añadir Paciente\n";
    std::cout << "2. Mostrar Pacientes\n";
    std::cout << "3. Añadir Medico\n";
    std::cout << "4. Mostrar Medicos\n";
    std::cout << "5. Salir\n";
    std::cout << "Elige una opcion: ";
}

void menuPaciente(ControlCSV &controlCSV) {
    int opcion = 0;

    while (opcion != 3) {
        std::cout << "\nMenu Pacientes\n";
        std::cout << "1. Añadir Paciente\n";
        std::cout << "2. Mostrar Pacientes\n";
        std::cout << "3. Volver al menu principal\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            int dni;
            std::string nombre, apellidos, fechaNacimiento, genero, direccion, telefono, estadoSalud;
            int medicoCabeceraId, edad;

            std::cout << "DNI: ";
            std::cin >> dni;
            std::cin.ignore(); 
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Apellidos: ";
            std::getline(std::cin, apellidos);
            std::cout << "Fecha de Nacimiento (YYYY-MM-DD): ";
            std::getline(std::cin, fechaNacimiento); 
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

            Paciente p(dni, nombre, apellidos, fechaNacimiento, genero, direccion, telefono, estadoSalud, medicoCabeceraId, edad);
            p.guardarEnCSV(controlCSV);
        } else if (opcion == 2) {
            Paciente::mostrarTodos(controlCSV); 
        } else if (opcion == 3) {
            std::cout << "Volviendo al menu principal...\n";
        } else {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}

int main() {
    ControlCSV controlCSV;

    int opcion = 0;
    while (opcion != 3) {
        menuPrincipal();
        std::cin >> opcion;

        if (opcion == 1) {
            menuPaciente(controlCSV);
        } else if (opcion == 2) {
            Paciente::mostrarTodos(controlCSV);
        } else if (opcion == 3) {
            std::cout << "Saliendo del programa...\n";
        } else {
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }

    return 0;
}