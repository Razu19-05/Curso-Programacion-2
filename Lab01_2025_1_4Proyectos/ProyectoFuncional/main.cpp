#include "src/Overloads.hpp"
#include "structs/CadenaDeCaracteres.hpp"

int main() {
    CadenaDeCaracteres cadena1,cadena2;
    !cadena1;
    cadena1<="Gabriel";
    cout<<cadena1.cadena<<endl;
    cadena2<="Huarote";
    cout<<cadena2.cadena<<endl;
    // cadena1<=10;
    // cadena1<=cadena2;
    // cadena2+="Naomi Guzman";
    cadena1+=cadena2;
    cout<<cadena1.cadena<<endl;
    return 0;
}
