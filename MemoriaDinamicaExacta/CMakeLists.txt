cmake_minimum_required(VERSION 3.31)
project(MemoriaDinamicaExacta)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemoriaDinamicaExacta main.cpp
        Utils.hpp
        Funciones.cpp
        Funciones.hpp
)
