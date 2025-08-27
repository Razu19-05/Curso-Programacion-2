#include "Overloads.hpp"

#include "../structs/CadenaDeCaracteres.hpp"

void operator ! (struct CadenaDeCaracteres &cadena) {
    cadena.cadena = nullptr;
    cadena.longitud = 0;
    cadena.capacidad = 0;
}

void operator <= (struct CadenaDeCaracteres &cadena, const char *cad) {
    cadena.cadena = new char[strlen(cad) + 1];
    strcpy(cadena.cadena, cad);
    cadena.longitud = strlen(cad);
    cadena.capacidad = strlen(cad)+1;
}

void operator <= (struct CadenaDeCaracteres &cadena, int cap) {
    cadena.cadena = new char[cap + 1];
    cadena.capacidad = cap + 1;
    cadena.longitud = 0;
}

void operator <= (struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2) {
    cadena1.cadena = new char[strlen(cadena2.cadena) + 1];
    strcpy(cadena1.cadena, cadena2.cadena);
    cadena1.longitud = cadena2.longitud;
    cadena1.capacidad = cadena2.capacidad;
}

bool operator += (struct CadenaDeCaracteres &cadena, const char *cad) {
    if (cadena.cadena == nullptr || cadena.cadena[0] == '\0') return false;
    int nuevaLongitud = cadena.longitud + strlen(cad);
    if (nuevaLongitud >= cadena.capacidad) {
        char *aux = new char[nuevaLongitud + 1];
        strcpy(aux, cadena.cadena);
        delete [] cadena.cadena;
        cadena <= nuevaLongitud;
        strcpy(cadena.cadena, aux);
    }
    strcat(cadena.cadena, cad);
    cadena.longitud = nuevaLongitud;
    return true;
}

bool operator += (struct CadenaDeCaracteres &cadena1, const struct CadenaDeCaracteres cadena2) {
    if (cadena1.cadena == nullptr || cadena1.cadena[0] == '\0') return false;
    int nuevaLongitud = cadena1.longitud + cadena2.longitud;
    if (nuevaLongitud >= cadena1.capacidad) {
        char *aux = new char[nuevaLongitud + 1];
        strcpy(aux, cadena1.cadena);
        delete [] cadena1.cadena;
        cadena1 <= nuevaLongitud;
        strcpy(cadena1.cadena, aux);
    }
    strcat(cadena1.cadena, cadena2.cadena);
    cadena1.longitud = nuevaLongitud;
    return true;
}