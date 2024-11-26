#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>

using namespace std;

struct Paciente
{
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

struct Medico
{
    string dni;
    string nombre;
    string apellidos;
    string especializacion;
    int aniosExperiencia;
    string numeroColegiado;
    string telefono;
    string direccionCalle;
    string direccionCiudad;
    string direccionCodigoPostal;
};

void menuPrincipal(vector<Paciente> &pacientes, vector<Medico> &medicos);
void gestionarPacientes(vector<Paciente> &pacientes);
void gestionarMedicos(vector<Medico> &medicos);

void darAltaPaciente(vector<Paciente> &pacientes);
void darBajaPaciente(vector<Paciente> &pacientes);
void modificarDatosPaciente(vector<Paciente> &pacientes);

void darAltaMedico(vector<Medico> &medicos);
void darBajaMedico(vector<Medico> &medicos);
void modificarDatosMedico(vector<Medico> &medicos);

string generarCodigoUnico(const string &dniTelefono);

int main()
{
    vector<Paciente> pacientes;
    vector<Medico> medicos;

    menuPrincipal(pacientes, medicos);
    return 0;
}

void menuPrincipal(vector<Paciente> &pacientes, vector<Medico> &medicos)
{
    int opcion;

    do
    {
        cout << "\n=== Gestor de Hospital ===" << endl;
        cout << "1. Pacientes" << endl;
        cout << "2. Médicos" << endl;
        cout << "3. Citas Médicas (En desarrollo)" << endl;
        cout << "4. Historial Clínico (En desarrollo)" << endl;
        cout << "5. Farmacia (En desarrollo)" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            gestionarPacientes(pacientes);
            break;
        case 2:
            gestionarMedicos(medicos);
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

void gestionarPacientes(vector<Paciente> &pacientes)
{
    int opcion;

    do
    {
        cout << "\n=== Gestión de Pacientes ===" << endl;
        cout << "1. Dar de alta a un paciente" << endl;
        cout << "2. Dar de baja a un paciente" << endl;
        cout << "3. Modificar datos de un paciente" << endl;
        cout << "4. Buscar paciente por DNI o nombre (En desarrollo)" << endl;
        cout << "5. Consultar registro clínico (En desarrollo)" << endl;
        cout << "6. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
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

void darAltaPaciente(vector<Paciente> &pacientes)
{
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

void darBajaPaciente(vector<Paciente> &pacientes)
{
    if (pacientes.empty())
    {
        cout << "\nNo hay pacientes registrados." << endl;
        return;
    }

    string dni, motivo;
    cout << "\nIngrese el DNI del paciente que desea dar de baja: ";
    cin >> dni;

    auto it = find_if(pacientes.begin(), pacientes.end(), [&dni](const Paciente &p)
                      { return p.dni == dni; });

    if (it != pacientes.end())
    {
        cout << "Motivo de la baja: ";
        cin.ignore();
        getline(cin, motivo);

        pacientes.erase(it);
        cout << "Paciente con DNI " << dni << " dado de baja exitosamente." << endl;
        cout << "Motivo: " << motivo << endl;
    }
    else
    {
        cout << "No se encontró un paciente con el DNI proporcionado." << endl;
    }
}

void modificarDatosPaciente(vector<Paciente> &pacientes)
{
    if (pacientes.empty())
    {
        cout << "\nNo hay pacientes registrados." << endl;
        return;
    }

    string dni;
    cout << "\nIngrese el DNI del paciente cuyos datos desea modificar: ";
    cin >> dni;

    auto it = find_if(pacientes.begin(), pacientes.end(), [&dni](const Paciente &p)
                      { return p.dni == dni; });

    if (it != pacientes.end())
    {
        Paciente &paciente = *it;

        cout << "\nModificando datos del paciente: " << paciente.nombre << " " << paciente.apellidos << endl;
        cout << "Deje en blanco si no desea cambiar un campo." << endl;

        string input;

        cout << "Nueva fecha de registro (" << paciente.fechaRegistro << "): ";
        cin.ignore();
        getline(cin, input);
        if (!input.empty())
            paciente.fechaRegistro = input;

        cout << "Nueva edad (" << paciente.edad << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.edad = stoi(input);

        cout << "Nueva dirección (calle y número) (" << paciente.direccionCalle << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.direccionCalle = input;

        cout << "Nueva ciudad (" << paciente.direccionCiudad << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.direccionCiudad = input;

        cout << "Nuevo código postal (" << paciente.direccionCodigoPostal << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.direccionCodigoPostal = input;

        cout << "Nuevas condiciones médicas (" << paciente.condicionesMedicas << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.condicionesMedicas = input;

        cout << "Nuevas alergias (" << paciente.alergias << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.alergias = input;

        cout << "Nuevo médico de cabecera (" << paciente.medicoCabecera << "): ";
        getline(cin, input);
        if (!input.empty())
            paciente.medicoCabecera = input;

        cout << "Datos del paciente actualizados correctamente." << endl;
    }
    else
    {
        cout << "No se encontró un paciente con el DNI proporcionado." << endl;
    }
}

void gestionarMedicos(vector<Medico> &medicos)
{
    int opcion;

    do
    {
        cout << "\n=== Gestión de Médicos ===" << endl;
        cout << "1. Dar de alta a un médico" << endl;
        cout << "2. Dar de baja a un médico" << endl;
        cout << "3. Modificar datos de un médico" << endl;
        cout << "4. Buscar médico por especialidad (En desarrollo)" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            darAltaMedico(medicos);
            break;
        case 2:
            darBajaMedico(medicos);
            break;
        case 3:
            modificarDatosMedico(medicos);
            break;
        case 5:
            cout << "Volviendo al menú principal..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 5);
}

void darAltaMedico(vector<Medico> &medicos)
{
    Medico nuevoMedico;

    cout << "\nIngrese el DNI del médico: ";
    cin >> nuevoMedico.dni;
    cout << "Ingrese el nombre del médico: ";
    cin.ignore();
    getline(cin, nuevoMedico.nombre);
    cout << "Ingrese los apellidos del médico: ";
    getline(cin, nuevoMedico.apellidos);
    cout << "Ingrese la especialización: ";
    getline(cin, nuevoMedico.especializacion);
    cout << "Ingrese los años de experiencia: ";
    cin >> nuevoMedico.aniosExperiencia;
    cout << "Ingrese el número de colegiado: ";
    cin.ignore();
    getline(cin, nuevoMedico.numeroColegiado);
    cout << "Ingrese el teléfono del médico: ";
    getline(cin, nuevoMedico.telefono);
    cout << "Ingrese la dirección (calle y número): ";
    getline(cin, nuevoMedico.direccionCalle);
    cout << "Ingrese la ciudad: ";
    getline(cin, nuevoMedico.direccionCiudad);
    cout << "Ingrese el código postal: ";
    getline(cin, nuevoMedico.direccionCodigoPostal);

    medicos.push_back(nuevoMedico);

    cout << "\nMédico registrado exitosamente." << endl;
}

void darBajaMedico(vector<Medico> &medicos)
{
    if (medicos.empty())
    {
        cout << "\nNo hay médicos registrados." << endl;
        return;
    }

    string dni, motivo;
    cout << "\nIngrese el DNI del médico que desea dar de baja: ";
    cin >> dni;

    auto it = find_if(medicos.begin(), medicos.end(), [&dni](const Medico &m)
                      { return m.dni == dni; });

    if (it != medicos.end())
    {
        cout << "Motivo de la baja: ";
        cin.ignore();
        getline(cin, motivo);

        medicos.erase(it);
        cout << "Médico con DNI " << dni << " dado de baja exitosamente." << endl;
        cout << "Motivo: " << motivo << endl;
    }
    else
    {
        cout << "No se encontró un médico con el DNI proporcionado." << endl;
    }
}

void modificarDatosMedico(vector<Medico> &medicos)
{
    if (medicos.empty())
    {
        cout << "\nNo hay médicos registrados." << endl;
        return;
    }

    string dni;
    cout << "\nIngrese el DNI del médico cuyos datos desea modificar: ";
    cin >> dni;

    auto it = find_if(medicos.begin(), medicos.end(), [&dni](const Medico &m)
                      { return m.dni == dni; });

    if (it != medicos.end())
    {
        Medico &medico = *it;

        cout << "\nModificando datos del médico: " << medico.nombre << " " << medico.apellidos << endl;
        cout << "Deje en blanco si no desea cambiar un campo." << endl;

        string input;

        cout << "Nueva especialización (" << medico.especializacion << "): ";
        cin.ignore();
        getline(cin, input);
        if (!input.empty())
            medico.especializacion = input;

        cout << "Nuevos años de experiencia (" << medico.aniosExperiencia << "): ";
        getline(cin, input);
        if (!input.empty())
            medico.aniosExperiencia = stoi(input);

        cout << "Nuevo número de colegiado (" << medico.numeroColegiado << "): ";
        getline(cin, input);
        if (!input.empty())
            medico.numeroColegiado = input;

        cout << "Nuevo teléfono (" << medico.telefono << "): ";
        getline(cin, input);
        if (!input.empty())
            medico.telefono = input;

        cout << "Nueva dirección (calle y número) (" << medico.direccionCalle << "): ";
        getline(cin, input);
        if (!input.empty())
            medico.direccionCalle = input;

        cout << "Nueva ciudad (" << medico.direccionCiudad << "): ";
        getline(cin, input);
        if (!input.empty())
            medico.direccionCiudad = input;

        cout << "Nuevo código postal (" << medico.direccionCodigoPostal << "): ";
        getline(cin, input);
        if (!input.empty())
            medico.direccionCodigoPostal = input;

        cout << "Datos del médico actualizados correctamente." << endl;
    }
    else
    {
        cout << "No se encontró un médico con el DNI proporcionado." << endl;
    }
}

string generarCodigoUnico(const string &dniTelefono)
{
    unsigned seed = 0;
    for (char c : dniTelefono)
    {
        seed += c;
    }
    srand(seed + time(0));
    string codigo;
    codigo += dniTelefono.substr(0, min<size_t>(3, dniTelefono.size()));
    for (int i = 0; i < 3; ++i)
    {
        codigo += 'A' + rand() % 26;
    }
    for (int i = 0; i < 4; ++i)
    {
        codigo += '0' + rand() % 10;
    }

    return codigo;
}
