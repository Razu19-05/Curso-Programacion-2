#include "Funciones.hpp"
#include "sobreCargas.hpp"

void LeerDatos(ifstream &arch, int *&dni, CadenaDeCaracteres *&conductor,
               CadenaDeCaracteres *&placa,int &cant) {
    int dni_i;
    CadenaDeCaracteres nombre;
    !nombre;
    char pl[8];
    dni = new int[MAX_CONDUCTORES];
    conductor = new CadenaDeCaracteres[MAX_CONDUCTORES];
    placa = new CadenaDeCaracteres[MAX_CONDUCTORES];
    while(true){
        arch >> dni_i;
        if(arch.eof()) break;
        !conductor[cant];
        !placa[cant];
        arch >> ws;
        leerNombre(arch, nombre);
        arch.getline(pl,8,'\n');
        insertarDatos(dni, dni_i, conductor, nombre, placa, pl,cant);
    }
}

void insertarDatos(int *dni, int dni_i, CadenaDeCaracteres *& conductor, CadenaDeCaracteres nombre,
                    CadenaDeCaracteres *&placa, const char *pl,int &cant) {
    int i = cant-1;
    while (i>=0 and conductor[i]>nombre) {
        dni[i+1] = dni[i];
        conductor[i+1] = conductor[i];
        placa[i+1] = placa[i];
        i--;
    }
    dni[i+1] = dni_i;
    conductor[i+1]<=nombre;
    placa[i+1]<=pl;
    cant++;
}

void leerNombre(ifstream &arch, CadenaDeCaracteres &nombre) {
    CadenaDeCaracteres palabra;
    bool primeraPalabra = true;
    while (true) {
        int resultado = arch>>palabra;
        if (resultado == -1 || resultado == 1) return;
        if (primeraPalabra) {
            nombre <= palabra;
            primeraPalabra = false;
        }else {
            nombre += "_";
            nombre += palabra;
        }
    }
}

void ImprimirReporte(ofstream & output, int*dni, CadenaDeCaracteres *conductor, CadenaDeCaracteres *placa,int n) {
    output << setw(40)<<"REPORTE DE CONDUCTORES" << endl;
    output << setw(80) << setfill('=') << "" << setfill(' ') << endl;
    output << left << setw(15) << "DNI"
           << setw(50) << "NOMBRE COMPLETO"
           << setw(15) << "PLACA" << endl;
    output << setw(80) << setfill('-') << "" << setfill(' ') << endl;

    for (int i = 0; i < n; i++) {
        output << left << setw(15) << dni[i]
               << setw(50) << conductor[i].cadena
               << setw(15) << placa[i].cadena << endl;
    }

    output << setw(80) << setfill('=') << "" << setfill(' ') << endl;
    output << "TOTAL DE CONDUCTORES: " << n << endl;
}