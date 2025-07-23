#include "Funciones.hpp"
#include "SobreCargas.hpp"
void leerConductores(ifstream & input,struct Conductor* conductor,int& n) {
    while (true) {
        input>>conductor[n];
        if (input.eof()) break;
        n++;
    }
}

int buscarPosicionDni(struct Conductor* conductor,int dni,int n) {
    for(int i=0; i<n;i++)
        if(conductor[i].dni==dni)return i;
    return -1;
}

void leerYLlenarFaltas(ifstream & input ,struct Conductor* conductor,int n) {
    int dni, pos;
    Falta f;
    while (true) {
        input>>dni;
        if (input.eof()) return;
        input.get();
        input>>f;
        pos = buscarPosicionDni(conductor,dni,n);
        conductor[pos] += f;
    }
}

void imprimirConductores(ofstream & output,Conductor* conductores,int n) {
    for(int i=0; i<n;i++)
        output<<conductores[i];
}