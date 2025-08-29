#include "src/AuxiliaryFunctions.hpp"
#include "structs/CadenaDeCaracteres.hpp"

int main() {
    ifstream input("Data/Infracciones de transito.txt",ios::in);
    if(!input.is_open()) {
        cout<<"Error"<<endl;
        exit(1);
    }
    ofstream output("Report/Reporte.txt",ios::out);
    int *dni, cant=0;
    CadenaDeCaracteres *conductor, *placa;
    readData(input,dni,conductor,placa,cant);

    cout<<cant<<endl;
    ordenData(dni,conductor,placa,cant);
    for(int i=0;i<cant;i++) cout<<dni[i]<<"   "<<conductor[i].cadena<<endl;
    return 0;
}