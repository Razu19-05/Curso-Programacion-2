cmake_minimum_required(VERSION 4.0)
project(ProyectoFuncional)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoFuncional main.cpp
        src/Utils.hpp
        src/Overloads.cpp
        src/Overloads.hpp
        structs/CadenaDeCaracteres.hpp)
