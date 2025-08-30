
#include "Overloads.hpp"

bool operator >> (ifstream &inputBook, Libro &libro) {
    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    inputBook.getline(libro.codigo,8,',');
    if (inputBook.eof()) return false;
    inputBook.getline(libro.tiltulo,80,',');
    inputBook.getline(libro.autor,60,',');
    inputBook>>libro.stock;
    inputBook.get();
    inputBook>>libro.precio;
    inputBook>>ws;
    return true;
}

bool operator >> (ifstream &input, Cliente &cliente) {
    // 54393647,Reyes Tang Edward
    input>>cliente.dni;
    if (input.eof()) return false;
    input.get();
    input.getline(cliente.nombre,60,'\n');
    input>>ws;
    cliente.cantDeLibros = 0;
    cliente.pagoTotal= 0;
    return true;
}

bool operator>>(LibroSolicitado &libroPedido, Libro *arregloLibros) {
    int i = 0;
    while (strcmp(arregloLibros[i].codigo,"FIN") != 0) {
        if (strcmp(arregloLibros[i].codigo, libroPedido.codigoDelLibro)==0) {
            if (arregloLibros[i].stock > 0) {
                libroPedido.atendido = true;
                libroPedido.precio = arregloLibros[i].precio;
                arregloLibros[i].stock --;
                return true;
            }else {
                libroPedido.atendido = false;
                libroPedido.precio = 0.0;
                return false;
            }
        }
        i++;
    }
    // Libro no encontrado en el arreglo
    libroPedido.atendido = false;
    libroPedido.precio = 0.0;
    return false;
}

bool operator << (Cliente &cliente, const LibroSolicitado libroPedido) {
    if (cliente.cantDeLibros==30)return false;
    cliente.librosSolicitados[cliente.cantDeLibros]=libroPedido;
    cliente.cantDeLibros++;
    return true;
}

void operator ++ (Cliente &cliente) {
    for (int i = 0; i < cliente.cantDeLibros; i++)
        cliente.pagoTotal += cliente.librosSolicitados[i].precio;
}

ofstream& operator << (ofstream &output, const Libro libro) {
    output<<left<<setw(10)<<libro.codigo<<setw(60)<<libro.tiltulo<<setw(30)<<libro.autor
          <<right<<setw(2)<<libro.stock<<setw(10)<<libro.precio<<endl;
    return output;
}

ofstream& operator << (ofstream &output, const Cliente cliente) {
    output <<cliente.dni<<"  "<<left<<setw(30)<<cliente.nombre<<endl;
    output <<"Libros entregados: "<<endl;
    output <<setw(10)<<" "<<left<<setw(15)<<"Pedido No."<<setw(15)<<"Codigo"<<"Precio"<<right<<endl;
    for (int i = 0; i < cliente.cantDeLibros; i++)
        if (cliente.librosSolicitados[i].atendido==true)
            output<<setw(16)<<cliente.librosSolicitados[i].numeroDePedido
                  <<setw(16)<<cliente.librosSolicitados[i].codigoDelLibro
                  <<setw(15)<<cliente.librosSolicitados[i].precio<<endl;
    output << "Total a pagar: "<<cliente.pagoTotal<<endl;
    output <<"Libros no entregados por falta de stock: "<<endl;
    output <<setw(10)<<" "<<left<<setw(15)<<"Pedido No."<<setw(15)<<"Codigo"<<right<<endl;
    for (int i = 0; i < cliente.cantDeLibros; i++)
        if (cliente.librosSolicitados[i].atendido==false)
            output<<setw(16)<<cliente.librosSolicitados[i].numeroDePedido
                  <<setw(16)<<cliente.librosSolicitados[i].codigoDelLibro<<endl;
    return output;
}