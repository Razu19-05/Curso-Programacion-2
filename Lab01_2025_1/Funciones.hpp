//
// Created by Huarote on 22/07/2025.
//

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"
#include "Estructuras.hpp"
void LeerDatos(ifstream &, int *&, CadenaDeCaracteres *&, CadenaDeCaracteres *&,int &);
void leerNombre(ifstream &, CadenaDeCaracteres &);
void insertarDatos(int *, int , CadenaDeCaracteres *& , CadenaDeCaracteres ,CadenaDeCaracteres *&, const char *,int &);
void ImprimirReporte(ofstream &, int*, CadenaDeCaracteres *, CadenaDeCaracteres *,int);
#endif //FUNCIONES_HPP
