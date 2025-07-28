#include "SobreCargas.hpp"

char* leerCadena(ifstream &input,char delim) {
    char buffer[200], *cad;
    input.getline(buffer,200,delim);
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void leerConductores(ifstream &input,int *buffer_dnis,char **buffer_Nombres,int &cantDatos) {
    // 81485316,JUSTINO MARTINEZ ENRIQUE
    while (true) {
        input>>buffer_dnis[cantDatos];
        if (input.eof()) break;
        input.get();
        buffer_Nombres[cantDatos] = leerCadena(input,'\n');
        cantDatos++;
    }
}

void insertarConductores(int *buffer_dnis,char **buffer_Nombres,Conductores &c,int cantDatos) {
    c.dnis = new int[cantDatos]{};
    c.nombres = new char*[cantDatos]{};
    c.cant = cantDatos;
    for (int i = 0; i < cantDatos; i++) {
        c.dnis[i] = buffer_dnis[i];
        c.nombres[i] = buffer_Nombres[i];
    }
}
void operator += (Conductores &c, const char *nombrArch) {
    ifstream input (nombrArch,ios::in);
    if (!input.is_open()) {
        cout << "Error opening file " << nombrArch << endl;
        exit(1);
    }
    int cantDatos = 0, buffer_dnis [MAX_CONDUCTORES]{};
    char * buffer_Nombres [MAX_CONDUCTORES]{};
    leerConductores(input,buffer_dnis,buffer_Nombres,cantDatos);
    insertarConductores(buffer_dnis,buffer_Nombres,c,cantDatos);
}

void    leerInfraccion(ifstream &input,int *buffer_codigo,char **buffer_descripcion,char **buffer_gravedad,
                    double *buffer_valores, int &cantDatos) {
    // 101,Adelantar o sobrepasar en forma indebida a otro vehículo.,Grave,316.00
    while (true) {
        input>>buffer_codigo[cantDatos];
        if (input.eof()) break;
        input.get();
        buffer_descripcion[cantDatos] = leerCadena(input,',');
        buffer_gravedad[cantDatos] = leerCadena(input,',');
        input>>buffer_valores[cantDatos];
        cantDatos++;
    }
}

void insertarInfracciones(int *buffer_codigo,char **buffer_descripcion,char **buffer_gravedad,double *buffer_valores,
                          int cantDatos,Infracciones &infr) {
    infr.codigos = new int[cantDatos]{};
    infr.descripcion = new char*[cantDatos]{};
    infr.tipos = new char*[cantDatos]{};
    infr.valores = new double[cantDatos]{};
    infr.cantidad = cantDatos;
    for (int i = 0; i < cantDatos; i++) {
        infr.codigos[i] = buffer_codigo[i];
        infr.descripcion[i] = buffer_descripcion[i];
        infr.tipos[i] = buffer_gravedad[i];
        infr.valores[i] = buffer_valores[i];
    }
}

void  operator += (Infracciones & infa, const char *nombrArch) {
    ifstream input (nombrArch,ios::in);
    if (!input.is_open()) {
        cout << "Error opening file " << nombrArch << endl;
        exit(1);
    }
    int cantDatos = 0, buffer_codigo[MAX_CONDUCTORES]{};
    char * buffer_descripcion [MAX_CONDUCTORES]{}, *buffer_gravedad[MAX_CONDUCTORES]{};
    double buffer_valores[MAX_CONDUCTORES]{};
    leerInfraccion(input,buffer_codigo,buffer_descripcion,buffer_gravedad,buffer_valores,cantDatos);
    insertarInfracciones(buffer_codigo,buffer_descripcion,buffer_gravedad,buffer_valores,cantDatos,infa);
}

void cargarDatos(Faltas &faltas) {
    faltas.conductos += "Conductores.csv";
    faltas.infracciones += "Infracciones.csv";
}

void inicializarFaltas(Faltas &faltas) {
    faltas.placas = new char**[faltas.conductos.cant]{};//darle el espacio con la misma cantidad de conductores
    for (int i = 0; i < faltas.conductos.cant; i++) faltas.placas[i] = nullptr;//las placas de los conductores desde 0
    faltas.capacidad = new int[faltas.conductos.cant]{};//darle el espacio con la misma cantidad de conductores
}

int buscar(int dni,Faltas faltas) {
    for (int i = 0; i < faltas.conductos.cant; i++) if (dni == faltas.conductos.dnis[i]) return i;
    return -1;
}

void reservarMemoria(char **&placas,int &cantidad,int &capacidad) {
    char **aux;
    capacidad += INCREMENTO;
    if (placas == nullptr) {
        placas = new char*[capacidad]{};
        cantidad = 1;
    }else {
        aux = new char*[capacidad]{};
        for (int i = 0; i < capacidad; i++) aux[i] = placas[i];
        delete placas;
        placas = aux;
    }
}

void colarPlaca(ifstream &input,int &cantidad,int &capacidad,char **&placas,bool &primeraVez) {
    char* placa,c;
    int null;
    placa = leerCadena(input,',');
    input>>null>>c>>null>>c>>null>>c>>null;
    if (cantidad==capacidad) reservarMemoria(placas,cantidad,capacidad);
    bool existe = false;
    for (int i = 0; i < cantidad-1 && existe == false; i++)
        if (strcmp(placa, placas[i]) == 0) existe = true;

    if (!existe) {
        if (primeraVez == false) {
            placas[cantidad-1] = placa;
            cantidad++;
            primeraVez = true;
        } else {
            placas[cantidad-1] = placa;
            cantidad++;
        }
    }
}

void leerFaltas(ifstream &input,Faltas& faltas) {
    // 81485316,J5T-691,24/12/2020,128
    int dni,pos, cantidad[faltas.conductos.cant]{};
    bool primeraVez[faltas.conductos.cant]{};
    while (true) {
        input>>dni;
        if (input.eof()) break;
        input.get();
        pos = buscar(dni,faltas);
        if (pos != -1) {
            colarPlaca(input,cantidad[pos],faltas.capacidad[pos],faltas.placas[pos],primeraVez[pos]);
        }else while (input.get()!='\n');
    }
}

void cargar_faltas_de_los_conductores(Faltas &faltas) {
    cargarDatos(faltas);
    inicializarFaltas(faltas);
    ifstream input ("Faltas.csv", ios::in);
    if (!input.is_open()) {
        cout << "Error opening file " << "Faltas.csv" << endl;
        exit(1);
    }
    leerFaltas(input,faltas);
}

void separador(ofstream &out,char c){
    for(int i=0;i<150;i++)out<<c;
    out<<endl;
}

int cuentaPlacas(char **datos){
    int cant=0;
    for(int i=0;true;i++){
        if(datos==nullptr)break;
        else{
            if(datos[i]==nullptr)break;
            cant++;
        }
    }
    return cant;
}

void imprimir_faltas_de_los_conductores(Faltas faltas){
    ofstream out("reporte.txt",ios::out);
    separador(out,'=');
    out<<right<<setw(6)<<"DNI"<<setw(12)<<"CLIENTE"<<setw(50)<<"CANT VEHICULOS"<<endl;
    separador(out,'-');
    for(int i=0;i<faltas.conductos.cant;i++){
        char **datos=faltas.placas[i];
        int cantidad_autos=cuentaPlacas(datos); //funcion que me contara la cantidad de carros
        out<<left<<setw(11)<<faltas.conductos.dnis[i]<<setw(50)<<faltas.conductos.nombres[i]<<right<<setw(3)<<cantidad_autos<<endl;
    }
    separador(out,'=');
}