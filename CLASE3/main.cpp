#include "scr/Overloads.hpp"

int main() {
    struct Reviews reviews{};
    reviews.n_reviews = 0;
    "DATA/reviews.csv"<<reviews; //Realizar una sobrecarga
    //reviews<<"Data/reviews.csv";
    cout<<reviews.n_reviews<<endl;
    reviews<<"Reports/reporte_reviews.txt";
    //    reviews<<"hola"
    //# Positivos 0.6 a 1.0
    //# Negativos 0.0 a 0.4
    //# Neutrales 0.4 a 0.5
    //Sacar estadisticas
    int estadisticas[3]{};
    reviews += estadisticas;
    cout<<"Cantidad Negativas: "<< estadisticas[0]<<endl;
    cout<<"Cantidad Neutrales: "<< estadisticas[1]<<endl;
    cout<<"Cantidad Positivas: "<< estadisticas[2]<<endl;

    return 0;
}