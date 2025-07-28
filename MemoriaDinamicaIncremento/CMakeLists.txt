cmake_minimum_required(VERSION 3.31)
project(MemoriaDinamicaIncremento)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemoriaDinamicaIncremento main.cpp
        utils.hpp
        Funciones.cpp
        Funciones.hpp)
