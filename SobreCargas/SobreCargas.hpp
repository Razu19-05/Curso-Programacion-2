
#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP

#include "Persona.hpp"

ostream & operator << (ostream &, const struct Persona &);

istream & operator >> (istream &, struct Persona&);

#endif //SOBRECARGAS_HPP
