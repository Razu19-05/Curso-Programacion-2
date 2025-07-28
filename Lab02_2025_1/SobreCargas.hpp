#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP

#include "Utils.hpp"
#include "Estructuras.hpp"

void operator += (Conductores &, const char *);
void operator += (Infracciones &, const char *);
void cargar_faltas_de_los_conductores(Faltas &);
void imprimir_faltas_de_los_conductores(Faltas);
#endif //SOBRECARGAS_HPP
