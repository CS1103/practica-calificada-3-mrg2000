#include <iostream>
#include "Metodos_Generales.h"
#include "Estructuras.h"
#include <vector>


int main() {

    vector<Subasta> subastas;

    //PRIMERA PRUEBA
    fstream archivo;
    archivo.open("subasta.txt",ios::in);

    Read(archivo,subastas);


    ofstream salida;
    salida.open("resultado.txt",ios::out);
    Print(salida,subastas);


    //SEGUNDA PRUEBA
    fstream archivo2;
    archivo2.open("bid_example.txt",ios::in);
    Read(archivo2,subastas);



    return 0;
}