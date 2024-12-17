#include "../include/Paciente.hpp"
#include "../include/Database.hpp"
#include <iostream>

void menuPrincipal()
{
    std::cout << "\nSistema Hospitalario\n";
    std::cout << "1. Añadir Paciente\n";
    std::cout << "2. Mostrar Pacientes\n";
    std::cout << "3. Salir\n";
    std::cout << "Elige una opción: ";
}

int main()
{
    Database db("Hospital.db");

    if (!db.open())
    {
        return 1;
    }

    std::string createPacientes = "CREATE TABLE IF NOT EXISTS Pacientes ("
                                  "dni INTEGER PRIMARY KEY, "
                                  "nombre TEXT, "
                                  "apellidos TEXT, "
                                  "fecha_nacimiento DATE, "
                                  "genero TEXT, "
                                  "direccion TEXT, "
                                  "telefono TEXT);";
    db.executeQuery(createPacientes);

    int opcion = 0;
    while (opcion != 3)
    {
        menuPrincipal();
        std::cin >> opcion;

        if (opcion == 1)
        {
            int dni;
            std::string nombre, apellidos, fechaNacimiento, genero, direccion, telefono;

            std::cout << "DNI: ";
            std::cin >> dni;
            std::cout << "Nombre: ";
            std::cin >> nombre;
            std::cout << "Apellidos: ";
            std::cin >> apellidos;
            std::cout << "Fecha de Nacimiento (YYYY-MM-DD): ";
            std::cin >> fechaNacimiento;
            std::cout << "Genero: ";
            std::cin >> genero;
            std::cout << "Direccion: ";
            std::cin >> direccion;
            std::cout << "Telefono: ";
            std::cin >> telefono;

            Paciente p(dni, nombre, apellidos, fechaNacimiento, genero, direccion, telefono);
            p.guardarEnDB(db);
        }
        else if (opcion == 2)
        {
            Paciente::mostrarTodos(db);
        }
        else if (opcion == 3)
        {
            std::cout << "Saliendo del programa...\n";
        }
        else
        {
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }

    db.close();
    return 0;
}
