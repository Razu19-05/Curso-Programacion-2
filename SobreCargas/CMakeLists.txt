cmake_minimum_required(VERSION 3.31)
project(SobreCargas)

set(CMAKE_CXX_STANDARD 20)

add_executable(SobreCargas main.cpp
        Utils.h
        SobreCargas.cpp
        SobreCargas.hpp
        Persona.hpp)
