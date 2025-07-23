
#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP

#include "Persona.hpp"

ostream & operator << (ostream &, const struct Persona &);

istream & operator >> (istream &, struct Persona&);

void operator += (struct Persona&, double);

//------------------------------------------------------------------

int f (int);

int f(int, int);

#endif //SOBRECARGAS_HPP
