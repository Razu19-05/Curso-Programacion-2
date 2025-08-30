#include "src/Overloads.hpp"
#include "STRUCT/Estructuras.h"
int main() {
    Libro libros[300];
    Cliente clientes[100];
    LibroSolicitado Pedidos[150];
    int contador = 0;
    int cont = 0;
    ifstream inputBook("Data/Libros.csv",ios::in);
    if (!inputBook.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    ifstream inputClient("Data/Cientes.csv",ios::in);
    if (!inputClient.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    ifstream inputOrders("Data/Pedidos.txt",ios::in);
    if (!inputOrders.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    ofstream output("Report/Reporte.txt",ios::out);
    while (true) {
        int resultado = inputBook >> libros[contador];
        if (!resultado) {
            strcpy(libros[contador].codigo,"FIN");
            break;
        }
        // output<<libros[contador];
        contador++;
    }
    while (true) {
        int resultado = inputClient >> clientes[cont];
        if (!resultado) break;
        output<<clientes[cont];
        cont++;
    }
    return 0;
}