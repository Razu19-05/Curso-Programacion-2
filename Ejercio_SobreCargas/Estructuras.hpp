//
// Created by Huarote on 21/07/2025.
//

#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP
#include "utils.hpp"
struct Falta {
    char* codigo;
    int fecha;
    double monto;
    char* gravedad;
    char* descripcion;
};

struct Conductor {
    int dni;
    char* nombre;
    Falta faltas[MAX_FALTAS];
    int n_faltas = 0;
};

#endif //ESTRUCTURAS_HPP
