
#include  "SobreCargas.hpp"
#include  "Persona.hpp"

int main(int argc, char** argv) {
    struct Persona persona;
    persona.dni = 77420924;
    strcpy(persona.nombre, "Juan Perez");
    persona.sueldo = 3500.0;
    cout<<persona.dni<< endl;
    cout<<persona.nombre<<endl;
    cout<<persona.sueldo<<endl;
    // //sobrecargar de <<
    cout<<persona;
    struct Persona persona2;
    //sobrecarga de >>
    cin>>persona2;
    cout<<persona2;
    persona2.sueldo += 30.5;
    cout<<persona2;
    return 0;
}
