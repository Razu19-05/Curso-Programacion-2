//
// Created by Huarote on 23/07/2025.
//

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"
void cargarAlumnos(const char*,int *&,char **&);
void leerAlumnos(ifstream &input,int *bufferDni,char **bufferNom,int &nDatos) ;
char * leerCadena(ifstream & input,char delim) ;
void insertarAlumnos(int *bufferDni,int *&dni,char **bufferNom,char **&nombres,int nDatos) ;
void imprimirAlumnos(const char*,int *,char **);
void cargarCursos(const char*,int *,char **,char***&);
void agregarCurso(ifstream &input,char **cursosAlumno,int &n);
void leerCurso(ifstream &input,int *dni,char ***cursos, int *nCursoAlumnos);
int buscar(int *dni,int codigo) ;
void insertarExactoCurso(int nDatos, char ***&cursos,int *nCursoAlumnos) ;
void recortar(char **&cursos,int n) ;
void imprimirAlumnos(const char*,int *,char **,char ***);
void reporte_cursos(ofstream &output, char**cursos_alumnos);
#endif //FUNCIONES_HPP
