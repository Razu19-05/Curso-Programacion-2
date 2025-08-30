

#ifndef FUENTESBIBLIOTECA_OVERLOADS_HPP
#define FUENTESBIBLIOTECA_OVERLOADS_HPP
#include "Utils.hpp"
#include "..\STRUCT/Estructuras.h"

bool operator >> (ifstream &input, Libro &libro);
bool operator >> (ifstream &input, Cliente &cliente);
bool operator >> (LibroSolicitado &libroPedido, Libro *arregloLibros);
bool operator << (Cliente &cliente, const LibroSolicitado libroPedido);
void operator ++ (Cliente &cliente);
ofstream& operator << (ofstream &output, const Libro libro);
ofstream& operator << (ofstream &output, const Cliente cliente) ;


#endif //FUENTESBIBLIOTECA_OVERLOADS_HPP