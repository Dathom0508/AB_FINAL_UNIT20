cmake_minimum_required(VERSION 3.12)

project(AB_FINAL_UNIDAD20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
    src/main.cpp
    src/Paciente.cpp
    src/Medico.cpp
    src/Cita.cpp 
    src/CSVcontrol.cpp
    src/Reporte.cpp
)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message(STATUS "Compilador: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Versión: ${CMAKE_CXX_COMPILER_VERSION}")