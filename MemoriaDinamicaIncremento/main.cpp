#include "Funciones.hpp"
int main() {
    int *dnis;
    char **nombres;
    char ***cursos;
    leerAlumnos("Alumnos.csv",dnis,nombres);
    leerCursos("Cursos.csv",dnis,nombres,cursos);
    imprimir_alumnos(dnis,nombres,cursos,"Reporte.txt");

    return 0;
}