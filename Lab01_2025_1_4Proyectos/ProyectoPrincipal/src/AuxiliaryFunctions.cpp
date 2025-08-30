
#include "AuxiliaryFunctions.hpp"
#include "Overloads.hpp"

void readData(ifstream &input,int *&dni,CadenaDeCaracteres *&conductor,CadenaDeCaracteres *&placa,int &cant) {
    // 12270502    CUEVA         FUENTES     CINTHIA   DELIA    129    P7T-999
    int bufferDni;
    CadenaDeCaracteres nombre;
    !nombre;
    char bufferPlaca[8];
    dni = new int[MAX_CONDUCTORES];
    conductor = new CadenaDeCaracteres[MAX_CONDUCTORES];
    placa = new CadenaDeCaracteres[MAX_CONDUCTORES];
    while (true) {
        input>>bufferDni;
        if (input.eof()) break;
        input>>ws;
        !conductor[cant];
        !placa[cant];
        conductor[cant] = readName(input);
        input.getline(bufferPlaca,8,'\n');
        dni[cant] = bufferDni;
        placa[cant] <= bufferPlaca;
        cant++;
    }
}

struct CadenaDeCaracteres readName(ifstream &input) {
    CadenaDeCaracteres fullName, word;
    bool firstWord = true;
    while (true) {
        int result = input>>word;
        if (result == 1 || result == -1) break;
        if (firstWord) {
            fullName <= word;
            firstWord = false;
        }else {
            fullName += "_";
            fullName += word;
        }
    }
    return fullName;
}
void cambiar(int &dniA, CadenaDeCaracteres &cadenaA, CadenaDeCaracteres &placaA,
             int &dniB, CadenaDeCaracteres &cadenaB, CadenaDeCaracteres &placaB) {
    int aux = dniA;
    dniA = dniB;
    dniB = aux;
    cadenaA && cadenaB;
    placaA && placaB;
}

void qsort(int *dni, CadenaDeCaracteres *conductores, CadenaDeCaracteres *placa, int izq, int der) {
    if (izq >= der) return;

    int medio = (izq + der) / 2;
    int limite = izq;
    // Mover el pivot al inicio
    cambiar(dni[izq], conductores[izq], placa[izq], dni[medio], conductores[medio], placa[medio]);
    // Particionar
    for (int i = izq + 1; i <= der; ++i) {
        if (conductores[i] < conductores[izq]) { // ordenar de mayor a menor
            limite ++;
            cambiar(dni[i], conductores[i], placa[i], dni[limite], conductores[limite], placa[limite]);
        }
    }
    // Mover el pivot a su posición final
    cambiar(dni[izq], conductores[izq], placa[izq],dni[limite], conductores[limite], placa[limite]);
    // Ordenar recursivamente
    qsort(dni, conductores, placa, izq, limite - 1);
    qsort(dni, conductores, placa, limite + 1, der);
}

void ordenData(int *&dni,CadenaDeCaracteres *&conductor,CadenaDeCaracteres *&placa,int cant) {
    qsort(dni, conductor, placa,0,cant-1);
}
