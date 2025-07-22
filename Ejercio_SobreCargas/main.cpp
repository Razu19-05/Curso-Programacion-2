#include "SobreCargas.hpp"
#include "Funciones.hpp"
#include  "Estructuras.hpp"
int main(int argc, char** argv) {
    Falta f, f1;
    Conductor c;
    //abrir archivos
    ifstream inputFaltas ("papeletas.csv",ios::in);
    ifstream inputConductores("constructores.csv",ios::in);
    ofstream output ("Reporte.txt",ios::out);
//Haciendo las SobreCargas antes de hacer el problema
    // // SobreCarga de Leer e Imprimir
    //  inputFaltas>>f;
    //  inputFaltas>>f1;
    //  output<<f<<endl;
    //  inputConductores>>c;
    //  output<<c<<endl;
    //  //SobreCarga de Comparar y agregar
    //  cout<<(c<123456789);
    //  c += f;
    //  output<<c<<endl;
//Resolviendo el problema
    Conductor conductores[MAX_CONDUCTORES];
    int n_conductos = 0;
    leerConductores(inputConductores,conductores,n_conductos);
    leerYLlenarFaltas(inputFaltas,conductores,n_conductos);
    imprimirConductores(output,conductores,n_conductos);
    return 0;
}