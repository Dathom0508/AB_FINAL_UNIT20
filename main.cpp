#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

void menuPrincipal(vector<Paciente>& pacientes);
void gestionarPacientes(vector<Paciente>& pacientes);
void darAltaPaciente(vector<Paciente>& pacientes);
void darBajaPaciente(vector<Paciente>& pacientes);
void modificarDatosPaciente(vector<Paciente>& pacientes);
string generarCodigoUnico(const string& dniTelefono);

int main() {
    vector<Paciente> pacientes; 
    menuPrincipal(pacientes);
    return 0;
}

void menuPrincipal(vector<Paciente>& pacientes) {
    int opcion;

    do {
        cout << "\n=== Gestor de Hospital ===" << endl;
        cout << "1. Pacientes" << endl;
        cout << "2. Médicos (En desarrollo)" << endl;
        cout << "3. Citas Médicas (En desarrollo)" << endl;
        cout << "4. Historial Clínico (En desarrollo)" << endl;
        cout << "5. Farmacia (En desarrollo)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarPacientes(pacientes); 
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

void gestionarPacientes(vector<Paciente>& pacientes) {
    int opcion;

    do {
        cout << "\n=== Gestión de Pacientes ===" << endl;
        cout << "1. Dar de alta a un paciente" << endl;
        cout << "2. Dar de baja a un paciente" << endl;
        cout << "3. Modificar datos de un paciente" << endl;
        cout << "4. Buscar paciente por DNI o nombre (En desarrollo)" << endl;
        cout << "5. Consultar registro clínico (En desarrollo)" << endl;
        cout << "6. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                darAltaPaciente(pacientes);
                break;
            case 2:
                darBajaPaciente(pacientes);
                break;
            case 3:
                modificarDatosPaciente(pacientes);
                break;
            case 6:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
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

string generarCodigoUnico(const std:: string& dniTelefono) {
    unsigned seed = 0;
    for (char c : dniTelefono) {
        seed += c;
    }
    srand(seed + time(0)); 
    string codigo;
    codigo += dniTelefono.substr(0, min<size_t>(3, dniTelefono.size()));
    for (int i = 0; i < 3; ++i) {
        codigo += 'A' + rand() % 26;
    }
    for (int i = 0; i < 4; ++i) {
        codigo += '0' + rand() % 10;
    }

    return codigo;
}


void darBajaPaciente(vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "\nNo hay pacientes registrados." << endl;
        return;
    }

    string dni, motivo;
    cout << "\nIngrese el DNI del paciente que desea dar de baja: ";
    cin >> dni;

    auto it = find_if(pacientes.begin(), pacientes.end(), [&dni](const Paciente& p) {
        return p.dni == dni;
    });

    if (it != pacientes.end()) {
        cout << "Motivo de la baja: ";
        cin.ignore();
        getline(cin, motivo);

        pacientes.erase(it);
        cout << "Paciente con DNI " << dni << " dado de baja exitosamente." << endl;
        cout << "Motivo: " << motivo << endl;
    } else {
        cout << "No se encontró un paciente con el DNI proporcionado." << endl;
    }
}

void modificarDatosPaciente(vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "\nNo hay pacientes registrados." << endl;
        return;
    }

    string dni;
    cout << "\nIngrese el DNI del paciente cuyos datos desea modificar: ";
    cin >> dni;

    auto it = find_if(pacientes.begin(), pacientes.end(), [&dni](const Paciente& p) {
        return p.dni == dni;
    });

    if (it != pacientes.end()) {
        Paciente& paciente = *it;

        cout << "\nModificando datos del paciente: " << paciente.nombre << " " << paciente.apellidos << endl;
        cout << "Deje en blanco si no desea cambiar un campo." << endl;

        string input;
   
        cout << "Nueva fecha de registro (" << paciente.fechaRegistro << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.fechaRegistro = input;

        cout << "Nueva edad (" << paciente.edad << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.edad = stoi(input);

        cout << "Nueva dirección (calle y número) (" << paciente.direccionCalle << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.direccionCalle = input;

        cout << "Nueva ciudad (" << paciente.direccionCiudad << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.direccionCiudad = input;

        cout << "Nuevo código postal (" << paciente.direccionCodigoPostal << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.direccionCodigoPostal = input;

        cout << "Nuevas condiciones médicas (" << paciente.condicionesMedicas << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.condicionesMedicas = input;

        cout << "Nuevas alergias (" << paciente.alergias << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.alergias = input;

        cout << "Nuevo médico de cabecera (" << paciente.medicoCabecera << "): ";
        getline(cin, input);
        if (!input.empty()) paciente.medicoCabecera = input;

        cout << "Datos del paciente actualizados correctamente." << endl;
    } else {
        cout << "No se encontró un paciente con el DNI proporcionado." << endl;
    }
}
