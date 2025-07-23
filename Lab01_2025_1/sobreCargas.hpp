#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP
#include "Utils.hpp"
#include "Estructuras.hpp"
void operator ! (CadenaDeCaracteres &);
void operator <= (CadenaDeCaracteres &,const char *);
void operator <= (CadenaDeCaracteres &,int);
void operator <= (CadenaDeCaracteres &,CadenaDeCaracteres &);
bool operator += (CadenaDeCaracteres &,const char *);
bool operator += (CadenaDeCaracteres &, const CadenaDeCaracteres&);
int compare(const CadenaDeCaracteres, const char*);
bool operator ==(const CadenaDeCaracteres , const char *);
bool operator >(const CadenaDeCaracteres , const char *);
bool operator <(const CadenaDeCaracteres , const char *);
int compare(const CadenaDeCaracteres, const CadenaDeCaracteres);
bool operator ==(const CadenaDeCaracteres , const CadenaDeCaracteres);
bool operator >(const CadenaDeCaracteres , const CadenaDeCaracteres);
bool operator <(const CadenaDeCaracteres , const CadenaDeCaracteres);
int operator >> (ifstream &,CadenaDeCaracteres &);
void operator && (CadenaDeCaracteres &, CadenaDeCaracteres &);
ofstream & operator << (ofstream &, const CadenaDeCaracteres &);

#endif //SOBRECARGAS_HPP
