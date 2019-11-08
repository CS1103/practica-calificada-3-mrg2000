//
// Created by Maor Roizman Gheiler on 7/11/19.
//

#ifndef PC3_PROPUESTA_H
#define PC3_PROPUESTA_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Metodos_Generales.h"

using namespace std;


struct Propuesta{
    string alias;
    float monto;

    Propuesta(string ali,float mon);

};

bool operator<(const Propuesta &s1, const Propuesta &s2);


struct Subasta{
public:
    string nombre_producto;
    vector<Propuesta> propuestas;

    Subasta(string nombre);
};

void Read(fstream &archivo, vector<Subasta>& subastas);
float CalcMayor(vector<Propuesta> propuestas);
float CalcProm(vector<Propuesta> propuestas);
void Print(ostream& os, vector<Subasta> subastas);
void SortPropuestas(vector<Propuesta>& propuestas);



#endif //PC3_PROPUESTA_H
