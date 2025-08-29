
#ifndef PROYECTOFUNCIONAL_OVERLOADS_HPP
#define PROYECTOFUNCIONAL_OVERLOADS_HPP
#include "Utils.hpp"

void operator ! (struct CadenaDeCaracteres &cadena);

void operator <= (struct CadenaDeCaracteres &cadena, const char *cad);
void operator <= (struct CadenaDeCaracteres &cadena, int cap);
void operator <= (struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2);

bool operator += (struct CadenaDeCaracteres &cadena, const char *cad);
bool operator += (struct CadenaDeCaracteres &cadena1, const struct CadenaDeCaracteres cadena2);

int compare(const struct CadenaDeCaracteres cadena,const char *cad);
bool operator == (struct CadenaDeCaracteres &cadena, const char *cad);
bool operator > (struct CadenaDeCaracteres &cadena, const char *cad) ;
bool operator < (struct CadenaDeCaracteres &cadena, const char *cad) ;

int compare(const struct CadenaDeCaracteres cadena1,const struct CadenaDeCaracteres cadena2);
bool operator == (struct CadenaDeCaracteres &cadena, const struct CadenaDeCaracteres cadena2);
bool operator > (struct CadenaDeCaracteres &cadena, const struct CadenaDeCaracteres cadena2);
bool operator < (struct CadenaDeCaracteres &cadena, const struct CadenaDeCaracteres cadena2);

int operator >>(ifstream &input, struct CadenaDeCaracteres &cadena);
void operator && (struct CadenaDeCaracteres &cadena1,struct CadenaDeCaracteres &cadena2);
ofstream& operator <<(ofstream &output,const struct CadenaDeCaracteres &cadena);
#endif //PROYECTOFUNCIONAL_OVERLOADS_HPP