

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
void leerAlumnos(const char*,int *&,char **&);
void insertarAlumnos(ifstream &input,int *&dnis,char **&nombres) ;
char *leerCadena(ifstream & input,char delim) ;
void reservarMemoriaIncremental(int *&dnis,char **&nombres,int &nDatos,int &capacidad) ;
void leerCursos(const char*,int* ,char**,char***&);
void imprimir_alumnos(int* codigos, char**nombres, char***cursos, const char*nombre_archivo) ;
#endif //FUNCIONES_HPP
