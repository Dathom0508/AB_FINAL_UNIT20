CREATE TABLE Pacientes (
    dni INTEGER PRIMARY KEY NOT NULL,  
    nombre TEXT NOT NULL,
    apellidos TEXT NOT NULL,
    fecha_nacimiento DATE NOT NULL,
    genero TEXT,                     
    direccion TEXT,
    telefono TEXT,     
    contacto_emergencia VARCHAR(15),         
    medico_cabecera_id INTEGER,      
    estado_salud TEXT,
    edad INTEGER,
    FOREIGN KEY (medico_cabecera_id) REFERENCES Medicos(id)
);

CREATE TABLE DatosAdicionales (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    dni INTEGER NOT NULL,
    historial_clinico TEXT,    
    tipo_sangre TEXT(3),     
    alergias TEXT,    
    enfermedades TEXT,
    observaciones TEXT,
    FOREIGN KEY (dni) REFERENCES Pacientes(dni)
);


CREATE TABLE Medicos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,     
    nombre TEXT NOT NULL,
    apellido TEXT NOT NULL,
    especialidad TEXT NOT NULL,
    direccion TEXT,
    telefono TEXT,
    correo_electronico TEXT,
    estado TEXT,                              
    licencia_profesional TEXT NOT NULL,     
    turno_trabajo TEXT,                    
    observaciones TEXT
);


CREATE TABLE Citas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    paciente_id INTEGER NOT NULL,
    medico_id INTEGER NOT NULL,
    fecha DATE NOT NULL,
    hora TIME NOT NULL,
    motivo TEXT,
    estado TEXT,                       
    observaciones TEXT,
    FOREIGN KEY (paciente_id) REFERENCES Pacientes(dni),
    FOREIGN KEY (medico_id) REFERENCES Medicos(id)
);


