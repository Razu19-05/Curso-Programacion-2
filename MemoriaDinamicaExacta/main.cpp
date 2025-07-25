#include "Funciones.hpp"

// void leerDatosExacto(const char* nombArch,int *&datos, int &n) {
//     ifstream input(nombArch,ios::in);
//     int buffer[20];
//     while (true) {
//         input>>buffer[n];
//         if (input.eof())break;
//         n++;
//     }
//     cout<<n<<endl;
//     datos = new int[n];
//     for (int i = 0; i < n; i++) datos[i] = buffer[i];
// }

int main(int argc, char** argv) {
    // int *datos, nDatos=0;
    // leerDatosExacto("texto.txt",datos,nDatos);
    // for(int i=0; i<nDatos; i++)cout<<datos[i]<<endl;

    //ahora Con un ejercicio MEMORIA EXACTA
    int *dni;
    char ** nombres, ***cursos;
    cargarAlumnos("Alumnos.csv",dni,nombres);
    imprimirAlumnos("ReporteSoloAlumnos.txt",dni,nombres);
    cargarCursos("Cursos.csv",dni,nombres,cursos);
    imprimirAlumnos("ReporteCompleto.txt",dni,nombres,cursos);



    return 0;
}