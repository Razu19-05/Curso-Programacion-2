#include  "SobreCargas.hpp"

ostream & operator << (ostream & out, const struct Persona & p) {
    out<<"tengo hambre"<<endl;
    out<<p.dni<<endl;
    out<<p.nombre<<endl;
    out<<p.sueldo<<endl;
}

istream & operator >> (istream & in, struct Persona& p){
    cout<<"Ingrese Datos"<<endl;
    in>>p.dni;
    // in>>p.nombre;
    // in>>p.sueldo;
}