#include <iostream>
#include "Metodos_Generales.h"
#include "Estructuras.h"
#include <vector>


int main() {

    vector<Subasta> subastas;

    fstream archivo;
    archivo.open("bid_example.txt",ios::in);

    Read(archivo,subastas);


    Print(cout,subastas);




    return 0;
}