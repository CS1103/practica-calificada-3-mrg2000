//
// Created by Maor Roizman Gheiler on 7/11/19.
//

#include "Estructuras.h"
#include <string>
#include "Metodos_Generales.h"
#include <vector>
#include <string>

using namespace std;


Subasta::Subasta(string nombre){
    nombre_producto = nombre;


};

Propuesta::Propuesta(string ali,float mon){
    alias = ali;
    monto = mon;
}


bool operator<(const Propuesta &s1, const Propuesta &s2){
    return s1.monto > s2.monto;
}
