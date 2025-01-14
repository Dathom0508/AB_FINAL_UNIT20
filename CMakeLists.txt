cmake_minimum_required(VERSION 3.12)

project(AB_FINAL_UNIDAD20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
    src/main.cpp
    src/Database.cpp
    src/Paciente.cpp
    src/Medico.cpp
    src/Cita.cpp 
)
include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SQLite3 REQUIRED)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SQLite3_LIBRARIES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message(STATUS "Compilador configurado: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Versión del compilador: ${CMAKE_CXX_COMPILER_VERSION}")