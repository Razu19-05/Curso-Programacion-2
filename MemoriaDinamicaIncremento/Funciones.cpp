
#include "Funciones.hpp"
char *leerCadena(ifstream & input,char delim) {
    char buffer[100], *cad;
    input.getline(buffer,100,delim);
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void reservarMemoriaIncremental(int *&dnis,char **&nombres,int &nDatos,int &capacidad) {
    int *auxDni;
    char **auxNombres;
    capacidad += INCREMENTO;
    if (dnis == nullptr) {
        dnis = new int[capacidad]{};
        nombres = new char*[capacidad]{};
        nDatos = 1;//se inicia desde 1 para que nunca choque con la capicadad al limite
    }else {
        auxDni = new int[capacidad]{};
        auxNombres = new char*[capacidad]{};
        for (int i = 0; i < nDatos; i++) {
            auxDni[i] = dnis[i];
            auxNombres[i] = nombres[i];
        }
        delete dnis;
        delete nombres;
        dnis = auxDni;
        nombres = auxNombres;
    }
}

void insertarAlumnos(ifstream &input,int *&dnis,char **&nombres) {
    int nDatos = 0, capacidad = 0,dni;
    char *nombre;
    while (true) {
        input>>dni;
        if (input.eof())break;
        input.get();
        nombre=leerCadena(input,'\n');
        if (capacidad==nDatos) reservarMemoriaIncremental(dnis,nombres,nDatos,capacidad);
        dnis[nDatos-1] = dni;
        nombres[nDatos-1] = nombre;
        nDatos++;
    }
}

void leerAlumnos(const char*nombArch,int *&dnis,char **&nombres) {
    ifstream input(nombArch,ios::in);
    if(!input.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    dnis = nullptr;
    nombres = nullptr;
    insertarAlumnos(input,dnis,nombres);
}

int buscar(int dni,int *dnis) {
    for (int i = 0; dnis[i]; i++) if (dni==dnis[i]) return i;
    return -1;
}

void reservarMemoriaIncremental(char **&cursos,int &cantidad,int &capacidad) {
    char**auxCursos;
    capacidad += INCREMENTO;
    if (cursos == nullptr) {
        cursos = new char*[capacidad] {};
        cantidad = 1;
    } else {
        auxCursos = new char*[capacidad] {};
        for (int i = 0; i < cantidad; i++)
            auxCursos[i] = cursos[i];
        delete cursos;
        cursos = auxCursos;
    }
}

void colocarCurso(ifstream &input,char **&cursos,int &cantidad,int &capacidad) {
    char *curso;
    curso = leerCadena(input,'\n');
    if (capacidad==cantidad) reservarMemoriaIncremental(cursos,cantidad,capacidad);
    cursos[cantidad-1] = curso;
    cantidad++;
}

void insertarCursos(ifstream &input ,char ***&cursos,int *dnis,char **nombres) {
    int dni, pos;
    int cantidad[50]{},capacidad[50]{};
    while (true) {
        input>>dni;
        if (input.eof())break;
        input.get();
        pos = buscar(dni,dnis);
        if (pos != -1) {
            colocarCurso(input,cursos[pos],cantidad[pos],capacidad[pos]);
        }else while (input.get()!='\n');
    }
}

void leerCursos(const char*nombrArch,int* dnis,char**nombres,char***&cursos) {
    ifstream input(nombrArch,ios::in);
    if(!input.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    int nDatos=0;
    for (int i = 0; dnis[i]; i++) nDatos++;
    cursos = new char**[nDatos+1]{};
    insertarCursos(input,cursos,dnis,nombres);
}
void reporte_cursos(ofstream &output, char**cursos_alumnos) {
    for (int i = 0; cursos_alumnos[i]; i++)
        output << right << setw(15) << cursos_alumnos[i];
    output << endl;
}
void imprimir_alumnos(int* codigos, char**nombres, char***cursos, const char*nombre_archivo) {
    ofstream output (nombre_archivo,ios::out);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; codigos[i]; i++) {
        output << codigos[i] << setw(40) << nombres[i] << endl;
        if (cursos[i])
            reporte_cursos(output, cursos[i]);
        else
            output << "No se encontraron cursos" << endl;
    }
}