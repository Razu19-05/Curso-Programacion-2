cmake_minimum_required(VERSION 3.31)
project(Ejercio_SobreCargas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ejercio_SobreCargas main.cpp
        Estructuras.hpp
        utils.hpp
        SobreCargas.hpp
        SobreCargas.cpp
        Funciones.hpp
        Funciones.cpp)
