#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include "Database.hpp"
#include "Cita.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"

void mostrarMenu();

void menuPrincipal(Database &db);
void menuPaciente(Database &db);
void menuMedico(Database &db);
void programarCita(Database &db);
void verPacientes(Database &db);
void verMedicos(Database &db);
void verCitas(Database &db);

#endif