//
// Created by Huarote on 21/07/2025.
//

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
#include "Estructuras.hpp"
void leerConductores(ifstream &,struct Conductor*,int&);
void leerYLlenarFaltas(ifstream &,struct Conductor*,int);
int buscarPosicionDni(struct Conductor* ,int ,int );
void imprimirConductores(ofstream &,Conductor*,int);
#endif //FUNCIONES_HPP
