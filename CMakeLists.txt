# Mínima versión requerida de CMake
cmake_minimum_required(VERSION 3.12)

# Nombre del proyecto
Cmake "project"(AB_FINAL_UNIDAD20)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Forzar el uso de g++
set(CMAKE_CXX_COMPILER "g++")

# Verificar configuración del compilador
message(STATUS "Compilador configurado: ${CMAKE_CXX_COMPILER}")
message(STATUS "Versión del compilador: ${CMAKE_CXX_COMPILER_VERSION}")

# Archivos fuente
set(SOURCE_FILES
    src/main.cpp
    src/Database.cpp
    src/Paciente.cpp
)

# Incluir encabezados desde el directorio `include`
include_directories(${PROJECT_SOURCE_DIR}/include)

# Configurar el ejecutable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Directorio de salida para el ejecutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

