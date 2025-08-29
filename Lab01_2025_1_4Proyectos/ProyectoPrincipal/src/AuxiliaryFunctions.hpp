

#ifndef PROYECTOPRINCIPAL_AUXILIARYFUNCTIONS_HPP
#define PROYECTOPRINCIPAL_AUXILIARYFUNCTIONS_HPP
#include "Utils.hpp"
#include "../structs/CadenaDeCaracteres.hpp"

void readData(ifstream &input,int *&dni,CadenaDeCaracteres *&conductor,CadenaDeCaracteres *&placa,int &cant);
struct CadenaDeCaracteres readName(ifstream &input) ;
void ordenData(int *&dni,CadenaDeCaracteres *&conductor,CadenaDeCaracteres *&placa,int cant);

#endif //PROYECTOPRINCIPAL_AUXILIARYFUNCTIONS_HPP