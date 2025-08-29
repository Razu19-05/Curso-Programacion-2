#include "src/Overloads.hpp"
#include "structs/CadenaDeCaracteres.hpp"

int main() {
    CadenaDeCaracteres cadena1,cadena2;
    !cadena1;
    cadena1<="Ana";
    cout<<cadena1.cadena<<endl;
    cadena2<="Ana ";
    cout<<cadena2.cadena<<endl;
    // cadena1<=10;
    // cadena1<=cadena2;
    // cadena2+="Naomi Guzman";
    cadena1+=" ";
    // cadena1+=cadena2;
    cout<<cadena1.cadena<<endl;
    int cmp = compare(cadena1,"Ana Rojas");
    if (cmp==0)cout<<"son iguales";
    else if (cmp==1)cout<<"el primero es mayor";
    else cout<<"el segundo es mayor";
    cout<<endl;
    cout<<(cadena1 == "Ana Rojas")<<endl;
    cout<<(cadena1 > "Ana Rojas")<<endl;
    cout<<(cadena1 < "Ana Rojas")<<endl;
    cmp = compare(cadena1,cadena2);
    if (cmp==0)cout<<"son iguales";
    else if (cmp==1)cout<<"el primero es mayor";
    else cout<<"el segundo es mayor";
    // ifstream arch;
    // arch>>cadena1;
    cout<<endl;
    cadena1<= "JESUS";
    cadena2<= "GABRIEL";
    cadena1&&cadena2;
    ofstream output;
    output<<cadena1;
    cout<<cadena1.cadena<<endl;
    cout<<cadena2.cadena<<endl;
    return 0;
}
