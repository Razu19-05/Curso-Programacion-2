
#include "AuxiliaryFuctions.hpp"

void readBooks(const char* nombrArch,Libro *libros) {
    ifstream arch (nombrArch,ios::in);
    if (!arch.is_open()) {
        cout << "Error opening file " << nombrArch << endl;
        exit(1);
    }
    int cont=0;
    while (true) {
        bool resultado = arch>>libros[cont];
        if (!resultado) {
            strcpy(libros[cont].codigo,"FIN");
            break;
        }
        cont++;
    }
}

void readClients(const char* nombrArch,Cliente *clientes) {
    ifstream arch (nombrArch,ios::in);
    if (!arch.is_open()) {
        cout << "Error opening file " << nombrArch << endl;
        exit(1);
    }
    int cont=0;
    while (true) {
        bool resultado = arch>>clientes[cont];
        if (!resultado) {
            clientes[cont].dni=0;
            break;
        }
        cont++;
    }
}

void readOrders(const char* nombrArch,Libro *libros,Cliente *clientes) {
    ifstream arch (nombrArch,ios::in);
    if (!arch.is_open()) {
        cout << "Error opening file " << nombrArch << endl;
        exit(1);
    }
    LibroSolicitado pedido;
    int dni,pos;
    char car;
    while (true) {
        arch>>pedido.numeroDePedido;
        if (arch.eof())break;
        arch>>car>>dni>>car;
        pos= buscarDni(dni,clientes);
        if (pos == -1 ) continue;
        while (true) {
            arch>>pedido.codigoDelLibro;
            bool encontrado = pedido>>libros;
            if (!encontrado) cout<<"no encontrado "<< pedido.numeroDePedido<<endl;
            clientes[pos]<<pedido;
            if (arch.get() == '\n')break;
        }
    }
    for (int i = 0; clientes[i].dni != 0; i++)++clientes[i];
}

int buscarDni(int dni,Cliente *clientes) {
    for (int i = 0; clientes[i].dni != 0; i++)
        if (clientes[i].dni == dni) return i;
    return -1;
}