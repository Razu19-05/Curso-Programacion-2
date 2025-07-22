
#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP

#include "utils.hpp"
#include "Estructuras.hpp"

ifstream & operator >> (ifstream &,struct Falta&);
char* leerCadena(ifstream &, char);
int leerFecha(ifstream &);
ofstream & operator << (ofstream &,const struct Falta&);

ifstream & operator >> (ifstream &,struct Conductor&);
ofstream & operator << (ofstream &,const struct Conductor&);

bool operator < (const struct Conductor &,int );

void operator += (Conductor &,const struct Falta& );

#endif //SOBRECARGAS_HPP
