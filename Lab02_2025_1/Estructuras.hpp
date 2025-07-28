

#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP
struct Conductores {
    int *dnis;
    char **nombres;
    int cant;
};

struct Infracciones {
    int *codigos;
    char **descripcion;
    char **tipos;
    double *valores;
    int cantidad;
};

struct Faltas {
    Conductores conductos;
    Infracciones infracciones;
    char ***placas;
    int *capacidad;
};
#endif //ESTRUCTURAS_HPP
