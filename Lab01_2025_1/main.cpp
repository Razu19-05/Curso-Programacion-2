#include "Sobrecargas.hpp"
#include "Estructuras.hpp"
#include "Funciones.hpp"

int main(int argc, char** argv) {
    ifstream arch ("Infracciones de transito.txt",ios::in);
    if (!arch.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    ofstream report ("Reporte.txt", ios::out);
    CadenaDeCaracteres cadena1, cadena2;
    // !cadena1;
    cadena1 <= "gabriel";
    // cadena2 <= "Ana Maria";
    // cadena1 <= 10;
    // cadena1 <= cadena2;
    // cout<<(cadena1 += "Naomi Guzman")<<endl;
    // cout<<compare(cadena1,"gabriel")<<endl;
    // cout<<(cadena1 > cadena2)<<endl;
    // cout<<(arch>>cadena1)<<endl;
    // cout<<cadena1.cadena<<endl;
    // cadena1 && cadena2;
    // cout<< cadena2.cadena<<endl;
    // report<<cadena1<<endl;
    int *dni, cant=0;
    CadenaDeCaracteres *conductor, *placa;
    LeerDatos(arch, dni, conductor, placa,cant);
    ImprimirReporte(report, dni, conductor, placa,cant);
    return 0;
}