#include "src/AuxiliaryFuctions.hpp"
#include "STRUCT/Estructuras.h"

int main() {
    Libro libros[300];
    Cliente clientes[150];
    readBooks("Data/Libros.csv",libros);

    ofstream output("Report.txt",ios::out);

    readClients("Data/Cientes.csv",clientes);

    readOrders("Data/Pedidos.txt",libros,clientes);

    for (int i = 0; clientes[i].dni != 0; i++) output<<clientes[i]<<endl;



    return 0;
}