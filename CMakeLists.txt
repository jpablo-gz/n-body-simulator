cmake_minimum_required(VERSION 3.28)

project(NBodySimulator LANGUAGES C CXX)

# Compilar únicamente los módulos de SFML que necesitamos.
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_GRAPHICS ON CACHE BOOL "" FORCE)
set(SFML_BUILD_WINDOW ON CACHE BOOL "" FORCE)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)

# Incorporar nuestra copia local de SFML.
add_subdirectory(external/SFML-3.1.0)

# Crear nuestro ejecutable.
add_executable(nbody
    src/main.cpp
    src/3Dmath.cpp
    src/Rasterizer.cpp
)

# Utilizar C++17.
target_compile_features(nbody PRIVATE cxx_std_17)

# Conectar el ejecutable con SFML.
target_link_libraries(nbody PRIVATE SFML::Graphics)