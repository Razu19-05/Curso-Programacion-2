//
// Created by Huarote on 23/07/2025.
//

#include "Funciones.hpp"
char * leerCadena(ifstream & input,char delim) {
    char buffer[100], *cad;
    input.getline(buffer,100,delim);
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void leerAlumnos(ifstream &input,int *bufferDni,char **bufferNom,int &nDatos) {
    // 20196975,Hijar Pairazaman Jenny Delicia
    while(true) {
        input>>bufferDni[nDatos];
        if (input.eof())break;
        input.get();//lee la coma
        bufferNom[nDatos] =leerCadena(input,'\n');
        nDatos++;
    }
}

void insertarAlumnos(int *bufferDni,int *&dni,char **bufferNom,char **&nombres,int nDatos) {
    dni = new int[nDatos]{};
    nombres = new char*[nDatos]{};
    for(int i=0;i<nDatos;i++) {
        dni[i] = bufferDni[i];
        nombres[i] = bufferNom[i];
    }
}

void cargarAlumnos(const char*nombArch ,int *& dni,char **& nombres) {
    ifstream input(nombArch,ios::in);
    if(!input.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    int bufferDni[MAX_AlUMNOS]{}, nDatos=0;
    char * bufferNom[MAX_AlUMNOS]{};
    leerAlumnos(input,bufferDni,bufferNom,nDatos);
    insertarAlumnos(bufferDni,dni,bufferNom,nombres,nDatos);
}

void imprimirAlumnos(const char* nombArch,int *dni,char **nombres) {
    ofstream output(nombArch,ios::out);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; dni[i]; i++) {
        output << left<<setw(10)<<dni[i] <<setw(40) << nombres[i] << right<< endl;
    }
}

int buscar(int *dni,int codigo) {
    for (int i = 0; dni[i]; i++) if (dni[i] == codigo) return i;
    return -1;
}

void agregarCurso(ifstream &input,char **cursosAlumno,int &n) {
    char *codigo = leerCadena(input,'\n');
    cursosAlumno[n] = codigo;//guardo el codigo
    n++;
}

void leerCurso(ifstream &input,int *dni,char ***cursos, int *nCursoAlumnos) {
    // 20187490,MAT219
    int codigo,pos;
    while(true) {
        input>>codigo;
        if (input.eof()) break;
        input.get();
        pos = buscar(dni,codigo);
        cout<<pos<<endl;
        if (pos != -1) agregarCurso(input,cursos[pos],nCursoAlumnos[pos]);
        cout<<nCursoAlumnos[pos]<<endl;
    }
}

void recortar(char **&cursos,int n) {
    char **cursosBufffer;
    if (n!=0) {
        cursosBufffer = new char*[n+1]{};//memoria exacta
        for(int i=0;i<n;i++) cursosBufffer[i] = cursos[i];//copiar al buffer
        delete cursos;//eliminar la memoria que tenia cursos
        cursos = cursosBufffer;//le copia los datos con memoria exacta
    }else {
        delete cursos;
        cursos = NULL;
    }
}

void insertarExactoCurso(int nDatos, char ***&cursos,int *nCursoAlumnos) {
    for(int i = 0; i < nDatos; i++) recortar(cursos[i],nCursoAlumnos[i]);
}

void cargarCursos(const char* nombrArch,int *dni,char **nombres,char***&cursos) {
    ifstream input(nombrArch,ios::in);
    if(!input.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    int nDatos=0;
    for(int i = 0; dni[i]; i++) nDatos++;//nivel 1: Sacar la cantidad de alumnos hay
    int nCursoAlumnos[nDatos] {};//nivel 2 : Arreglo que guardara la cantidad de cursos por alumno(osea contador de cursos)

    cursos = new char**[nDatos]{};// nivel 1: Reservo espacio para curso char**
    for(int i=0;i<nDatos;i++) cursos[i] = new char*[MAX_CURSOS_ALUMNO]{};// reservar espacio en cada arreglo de curso char* (no es exacto)

    leerCurso(input,dni,cursos,nCursoAlumnos);
    insertarExactoCurso(nDatos,cursos,nCursoAlumnos);
}

void reporte_cursos(ofstream &output, char**cursos_alumnos) {
    for (int i = 0; cursos_alumnos[i]; i++)
        output << right << setw(15) << cursos_alumnos[i];
    output << endl;
}

void imprimirAlumnos(const char* nombArch,int *dni,char **nombres,char ***cursos) {
    ofstream output(nombArch,ios::out);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; dni[i]; i++) {
        output << dni[i] << setw(40) << nombres[i] << endl;
        if (cursos[i])
            reporte_cursos(output, cursos[i]);
        else
            output << "No se encontraron cursos" << endl;
    }
}