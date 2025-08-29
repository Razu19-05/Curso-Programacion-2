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

int compare(const struct CadenaDeCaracteres cadena,const char *cad) {
    return strcmp(cadena.cadena, cad);
}
bool operator == (struct CadenaDeCaracteres &cadena, const char *cad) {
    return compare(cadena, cad) == 0 ;
}
bool operator > (struct CadenaDeCaracteres &cadena, const char *cad) {
    return compare(cadena, cad) == 1 ;
}
bool operator < (struct CadenaDeCaracteres &cadena, const char *cad) {
    return compare(cadena, cad) == -1 ;
}

int compare(const struct CadenaDeCaracteres cadena1,const struct CadenaDeCaracteres cadena2) {
    return strcmp(cadena1.cadena, cadena2.cadena);
}
bool operator == (struct CadenaDeCaracteres &cadena, const struct CadenaDeCaracteres cadena2) {
    return compare(cadena, cadena2) == 0 ;
}
bool operator > (struct CadenaDeCaracteres &cadena, const struct CadenaDeCaracteres cadena2) {
    return compare(cadena, cadena2) == 1 ;
}
bool operator < (struct CadenaDeCaracteres &cadena, const struct CadenaDeCaracteres cadena2) {
    return compare(cadena, cadena2) == -1 ;
}

int operator >>(ifstream &input, struct CadenaDeCaracteres &cadena) {
    char palabra[MAX_LETRAS];
    input >> palabra;
    if (input.eof()) return 1;
    input >> ws;//este es para poner el puntero en la siguiente caracter y ya que no es el fin de archivo
    char primeraLetra = palabra[0];
    if (!((primeraLetra>= 'A' and primeraLetra<='Z') or (primeraLetra>='a' and primeraLetra<='z')))return -1;
    cadena <= palabra;
    return 0;
}

void operator && (struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2){
    struct CadenaDeCaracteres aux;
    aux <= cadena1;
    cadena1 <= cadena2;
    cadena2 <= aux;
}
ofstream& operator <<(ofstream &output,const struct CadenaDeCaracteres &cadena) {
    output<<left<<setw(20)<<cadena.cadena<<right<<cadena.capacidad<<setw(10)<<cadena.longitud<<endl;
    return output;
}