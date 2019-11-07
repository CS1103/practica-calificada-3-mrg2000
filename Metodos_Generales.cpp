//
// Created by Maor Roizman Gheiler on 7/11/19.
//

#include "Estructuras.h"
#include <string>

using namespace std;

void Read(fstream &archivo, vector<Subasta>& subastas){
    int num_sub = 0;
    string producto_name;
    string linea;
    int count_alias=0;
    string alias, monto;

    while(getline(archivo,linea)){


        if(linea[0] >= 'A' && linea[0]<= 'Z'){
            copy_n(linea.begin(), linea.size(), back_inserter(producto_name));
            Subasta sub(producto_name);
            subastas.push_back(sub);
            num_sub++;
        }


        if(linea[0] < 'A' || linea[0]>'Z'){
            for(size_t i=0;i<linea.size()-1;i++){
                if(linea[i] == ' '){
                    break;
                }else{
                    count_alias++;
                }
            }
            copy_n(linea.begin(), count_alias, back_inserter(alias));
            copy_n(linea.begin()+(count_alias+1), 2, back_inserter(monto));
            Propuesta prop(alias,stof(monto));
            subastas[num_sub-1].propuestas.push_back(prop);

            alias.clear();
            monto.clear();
            count_alias = 0;
        }
    }
}


float CalcMayor(vector<Propuesta> propuestas){
    float max = 0;

    for (size_t i=0;i<propuestas.size();i++){
        if(propuestas[i].monto > max)
            max = propuestas[i].monto;
    }

    return max;
}


float CalcProm(vector<Propuesta> propuestas){
    float suma = 0;

    for(auto it= begin(propuestas);it != end(propuestas);it++){
        suma += (*it).monto;
    }

    return suma/(propuestas.size());
}



void Print(ostream& os, vector<Subasta> subastas){
    for(size_t i=0;i<subastas.size();i++){
        os << subastas[i].nombre_producto << ",";
        os << CalcMayor(subastas[i].propuestas) << ",";
        os << CalcProm(subastas[i].propuestas) << ",";
        os << endl;
    }

}


