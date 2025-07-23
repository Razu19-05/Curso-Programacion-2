//
// Created by Huarote on 22/07/2025.
//
#include "sobreCargas.hpp"

void operator ! (CadenaDeCaracteres &c) {
    c.capacidad = 0;
    c.longitud = 0;
    c.cadena = nullptr;
}

void operator <= (CadenaDeCaracteres &c,const char * cad) {
    c.cadena = new char[strlen(cad)+1];
    strcpy(c.cadena,cad);
    c.longitud = strlen(c.cadena);
    c.capacidad = strlen(c.cadena)+1;
}

void operator <= (CadenaDeCaracteres &c,int espacio) {
    c.cadena = new char[espacio+1];
    c.longitud = 0;// dice que cad queda vacio
    c.capacidad = espacio + 1;
}

void operator <= (CadenaDeCaracteres &c1,CadenaDeCaracteres &c2) {
    c1.cadena = new char[strlen(c2.cadena)+1];
    strcpy(c1.cadena,c2.cadena);
    c1.longitud = c2.longitud;
    c1.capacidad = c2.capacidad;
}

bool operator +=(CadenaDeCaracteres &data,const char *cadena){
    if(data.cadena[0]!='\0'){
        int aux_tam=data.longitud;//guardar el tamano de la primera cadena
        char aux[aux_tam+1];//dale espacio para copiar la primera cadena
        strcpy(aux,data.cadena);//copia la primera cadena
        data<=(data.longitud+strlen(cadena));// pone todo vacio con el espacio nuevo dado
        strcpy(data.cadena,aux);//copia el auxiliar
        strcat(data.cadena,cadena);//copiar el nuevo
        data.longitud=strlen(data.cadena);//guarda la nueva longitud
        return true;
    }else return false;
}

bool operator +=( CadenaDeCaracteres &cad1,  const CadenaDeCaracteres &cad2) {
    if(cad1.cadena[0]!='\0'){
        int aux_tam=cad1.longitud;
        char aux[aux_tam+1];
        strcpy(aux,cad1.cadena);
        cad1<=(cad1.longitud+cad2.longitud);
        strcpy(cad1.cadena,aux);
        strcat(cad1.cadena,cad2.cadena);
        cad1.longitud=strlen(cad1.cadena);
        return true;
    }else return false;
}

int compare(const CadenaDeCaracteres data, const char* cad) {
    return strcmp(data.cadena,cad);
}

bool operator ==(const CadenaDeCaracteres data, const char *cadena){
    if(strcmp(data.cadena,cadena)==0)return true;
    return false;
}

bool operator >(const CadenaDeCaracteres data, const char *cadena){
    if(strcmp(data.cadena,cadena)>0)return true;
    return false;
}

bool operator <(const CadenaDeCaracteres data, const char *cadena){
    if(strcmp(data.cadena,cadena)<0)return true;
    return false;
}

int compare(const CadenaDeCaracteres data1, const CadenaDeCaracteres data2) {
    return strcmp(data1.cadena,data2.cadena);
}

bool operator ==(const CadenaDeCaracteres data1, const CadenaDeCaracteres data2) {
    if(strcmp(data1.cadena,data2.cadena)==0)return true;
    return false;
}

bool operator >(const CadenaDeCaracteres data1, const CadenaDeCaracteres data2) {
    if(strcmp(data1.cadena,data2.cadena)>0)return true;
    return false;
}
bool operator <(const CadenaDeCaracteres data1, const CadenaDeCaracteres data2) {
    if(strcmp(data1.cadena,data2.cadena)<0)return true;
    return false;
}

int operator >>(ifstream &arch, CadenaDeCaracteres &cadena){
    char palabra[30];
    arch >> palabra;
    if (arch.eof()) return 1;
    arch>>ws;
    // Verificar si el primer carácter es una letra (A-Z o a-z)
    char primerChar = palabra[0];
    if (!((primerChar >= 'A' && primerChar <= 'Z') || (primerChar >= 'a' && primerChar <= 'z')))
        return -1;
    cadena<=palabra;
    return 0;
}

void operator && (CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2) {
    CadenaDeCaracteres aux;
    aux=cad1;
    !cad1;
    cad1<=cad2;
    !cad2;
    cad2<=aux;
}

ofstream & operator << (ofstream & output, const CadenaDeCaracteres &cad) {
    output<<left<<setw(20)<<cad.cadena<<right<<cad.capacidad<<setw(10)<<cad.longitud<<endl;
    return output;
}