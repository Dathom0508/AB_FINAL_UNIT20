#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Paciente {
    string dni;
    string nombre;
    string apellidos;
    string fechaRegistro;
    char sexo;
    int edad;
    string codigoPaciente;
    string medicoCabecera;
    string direccionCalle;
    string direccionCiudad;
    string direccionCodigoPostal;
    string condicionesMedicas;
    string alergias;
};

void menuPrincipal();
void gestionarPacientes();
void darAltaPaciente(vector<Paciente>& pacientes);

string generarCodigoUnico(const string& dni);

int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int opcion;
    vector<Paciente> pacientes;

    do {
        cout << "\n=== Gestor de Hospital ===" << endl;
        cout << "1. Pacientes" << endl;
        cout << "2. Médicos" << endl;
        cout << "3. Citas Médicas" << endl;
        cout << "4. Historial Clínico" << endl;
        cout << "5. Farmacia" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarPacientes();
                break;
            case 2:
                cout << "Opción Médicos en desarrollo." << endl;
                break;
            case 3:
                cout << "Opción Citas Médicas en desarrollo." << endl;
                break;
            case 4:
                cout << "Opción Historial Clínico en desarrollo." << endl;
                break;
            case 5:
                cout << "Opción Farmacia en desarrollo." << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);
}

void gestionarPacientes() {
    vector<Paciente> pacientes;
    int opcion;

    do {
        cout << "\n=== Gestión de Pacientes ===" << endl;
        cout << "1. Dar de alta a un paciente" << endl;
        cout << "2. Dar de baja a un paciente (En desarrollo)" << endl;
        cout << "3. Modificar datos de un paciente (En desarrollo)" << endl;
        cout << "4. Buscar paciente por DNI o nombre (En desarrollo)" << endl;
        cout << "5. Consultar registro clínico (En desarrollo)" << endl;
        cout << "6. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                darAltaPaciente(pacientes);
                break;
            case 6:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "Opción no válida o en desarrollo." << endl;
        }
    } while (opcion != 6);
}

void darAltaPaciente(vector<Paciente>& pacientes) {
    Paciente nuevoPaciente;
    string telefono;

    cout << "\nIngrese el DNI del paciente: ";
    cin >> nuevoPaciente.dni;
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore();
    getline(cin, nuevoPaciente.nombre);
    cout << "Ingrese los apellidos del paciente: ";
    getline(cin, nuevoPaciente.apellidos);
    cout << "Ingrese la fecha de registro (DD/MM/AAAA): ";
    cin >> nuevoPaciente.fechaRegistro;
    cout << "Ingrese el sexo del paciente (M/F): ";
    cin >> nuevoPaciente.sexo;
    cout << "Ingrese la edad del paciente: ";
    cin >> nuevoPaciente.edad;
    cout << "Ingrese el teléfono del paciente: ";
    cin >> telefono;
    cout << "Ingrese la dirección (calle y número): ";
    cin.ignore();
    getline(cin, nuevoPaciente.direccionCalle);
    cout << "Ingrese la ciudad: ";
    getline(cin, nuevoPaciente.direccionCiudad);
    cout << "Ingrese el código postal: ";
    getline(cin, nuevoPaciente.direccionCodigoPostal);
    cout << "Ingrese condiciones médicas preexistentes (si no hay, escriba 'Ninguna'): ";
    getline(cin, nuevoPaciente.condicionesMedicas);
    cout << "Ingrese alergias (si no hay, escriba 'Ninguna'): ";
    getline(cin, nuevoPaciente.alergias);
    nuevoPaciente.codigoPaciente = generarCodigoUnico(nuevoPaciente.dni + telefono);
    cout << "Ingrese el nombre del médico de cabecera: ";
    getline(cin, nuevoPaciente.medicoCabecera);

    pacientes.push_back(nuevoPaciente);

    cout << "\nPaciente registrado exitosamente." << endl;
    cout << "Código del paciente: " << nuevoPaciente.codigoPaciente << endl;
}

string generarCodigoUnico(const string& dniTelefono) {
    srand(time(0));
    string codigo;

    for (int i = 0; i < 5; ++i) {
        codigo += 'A' + rand() % 26;
    }

    for (int i = 0; i < 5; ++i) {
        codigo += '0' + rand() % 10;
    }

    return codigo;
}
