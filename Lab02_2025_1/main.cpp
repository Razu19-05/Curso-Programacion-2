#include "SobreCargas.hpp"

int main() {
    // Conductores conductor;
    // Infracciones infraccion;
    // conductor += "Conductores.csv";
    // cout<<conductor.cant<<endl;
    // infraccion += "Infracciones.csv";
    // cout<<infraccion.cantidad<<endl;
    Faltas faltas;
    cargar_faltas_de_los_conductores(faltas);
    imprimir_faltas_de_los_conductores(faltas);
    return 0;
}
