cmake_minimum_required(VERSION 4.0)
project(CLASE3)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASE3 main.cpp
        scr/Overloads.cpp
        scr/Overloads.hpp
        scr/Utils.hpp
        scr/AuxiliaryFunctions.cpp
        scr/AuxiliaryFunctions.hpp
        scr/Review.hpp
        scr/Reviews.hpp)
