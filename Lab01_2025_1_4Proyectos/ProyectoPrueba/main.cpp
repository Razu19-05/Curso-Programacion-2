#include "src/Overloads.hpp"
#include "structs/CadenaDeCaracteres.hpp"

int main() {
    cout<<"hola mundo"<<endl;
    CadenaDeCaracteres cad;
    cad <= "Gabriel";
    cout<<cad.cadena<<endl;
    return 0;
}