

#ifndef UNAAPLICACIONCONBIBLIOTECAESTATICA_AUXILIARYFUCTIONS_HPP
#define UNAAPLICACIONCONBIBLIOTECAESTATICA_AUXILIARYFUCTIONS_HPP
#include "Overloads.hpp"
#include "../STRUCT/Estructuras.h"

void readBooks(const char* nombrArch,Libro *libros);

void readClients(const char* nombrArch,Cliente *clientes);

void readOrders(const char* nombrArch,Libro *libros,Cliente *clientes);

int buscarDni(int dni,Cliente *clientes) ;

#endif //UNAAPLICACIONCONBIBLIOTECAESTATICA_AUXILIARYFUCTIONS_HPP