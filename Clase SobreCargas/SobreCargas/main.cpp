
#include  "SobreCargas.hpp"
#include  "Persona.hpp"

int main(int argc, char** argv) {
// //CLASE DE SOBRE CARGAR DE OPERADORES
//     struct Persona persona;
//     persona.dni = 77420924;
//     strcpy(persona.nombre, "Juan Perez");
//     persona.sueldo = 3500.0;
//     cout<<persona.dni<< endl;
//     cout<<persona.nombre<<endl;
//     cout<<persona.sueldo<<endl;
//     //sobrecargar de <<
//     cout<<persona;
//     struct Persona persona2;
//     //sobrecarga de >>
//     cin>>persona2;
//     cout<<persona2;
//     persona2.sueldo += 30.5;
//     cout<<persona2;
// //CLASE DE SOBRE CARGA DE FUNCIONES
//     int a, b;
//     a = 10;
//     b = 20;
//     cout<<f(a)<<endl;
//     cout<<f(a,b)<<endl;

    char *carecter;

    cin.getline(buffer, 100,',');
    carecter = new char[strlen(buffer)+1];
    strcpy(carecter, buffer);
    cout << carecter;
    return 0;
}
