#include "SobreCargas.hpp"

char* leerCadena(ifstream &input, char delim) {
    char* cadena, buffer[MAX_CADENA];
    input.getline(buffer, MAX_CADENA,delim);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

int leerFecha(ifstream &input) {
    int fecha, aa, mm, dd;
    char car;
    input>>aa>>car>>mm>>car>>dd;
    input.get();
    return fecha = aa*10000+mm*100+dd;
}

ifstream & operator >> (ifstream & in, struct Falta& f) {
    // int id;
    // in>>id;
    // in.get(); //Leer la coma
    f.codigo = leerCadena(in,','); //char*
    f.fecha = leerFecha(in);
    in>>f.monto;
    in.get(); //Leer la coma
    f.gravedad = leerCadena(in,',');
    f.descripcion = leerCadena(in,'\n');
    return in;
}

ofstream & operator << (ofstream & out,const struct Falta& f) {
    out<<setprecision(2)<<fixed;
    out<<"["<<f.codigo<<"]"<<f.descripcion<<"|"<<f.monto<<"|Gravedad: "<<f.gravedad;
    return out;
}

ifstream & operator >> (ifstream & in,struct Conductor& c) {
    in>>c.dni;
    in.get();
    c.nombre = leerCadena(in,'\n');
    return in;
}

ofstream & operator << (ofstream & out ,const struct Conductor& c) {
    out<<"DNI: "<<c.dni<<endl;
    out<<"Nombre: "<<c.nombre<<endl;
    out<<"Faltas"<<endl;
    if (c.n_faltas != 0)
        for(int i=0;i<c.n_faltas;i++)
            out<<c.faltas[i]<<endl;
    return out;
}

bool operator < (const struct Conductor & c,int numero ) {
    return c.dni<numero;
}

void operator += (Conductor & c,const struct Falta&  f) {
    if (c.n_faltas <MAX_FALTAS) {
        c.faltas[c.n_faltas]= f; //se le agrega una falta
        c.n_faltas++;
    }else
        cout<<"No se pudo ingresar la papeleta al conductor"<<endl;
}