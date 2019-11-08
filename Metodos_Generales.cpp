//
// Created by Maor Roizman Gheiler on 7/11/19.
//

#include "Estructuras.h"
#include <string>
#include <algorithm>

using namespace std;

bool ValidarUser(vector <Propuesta> prop,Propuesta propind){

    for(size_t i=0;i<prop.size();i++){
        if(prop[i].alias == propind.alias){
            if(prop[i].monto > propind.monto)
                return false;
        }
    }


    return true;
}


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

            if(ValidarUser(subastas[num_sub-1].propuestas,prop))
                subastas[num_sub-1].propuestas.push_back(prop);


            producto_name.clear();
            alias.clear();
            monto.clear();
            count_alias = 0;
        }
    }
}


float CalcMayor(vector<Propuesta> propuestas){
    float max = 0;

    for(auto it= begin(propuestas);it != end(propuestas);it++){
        if((*it).monto > max)
            max = (*it).monto;

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

float CalcMenor(vector<Propuesta> propuestas){
    float min = propuestas[0].monto;

    for(auto it= begin(propuestas);it != end(propuestas);it++){
        if((*it).monto < min)
            min = (*it).monto;

    }
    return min;
}


void SortPropuestas(vector<Propuesta>& propuestas){
    sort(propuestas.begin(),propuestas.end());
}





void Print(ostream& os, vector<Subasta> subastas){
    for(size_t i=0;i<subastas.size();i++){
        os << subastas[i].nombre_producto << ",";
        os << CalcMayor(subastas[i].propuestas) << ",";
        os << CalcProm(subastas[i].propuestas) << ",";
        os << CalcMenor(subastas[i].propuestas);
        os << endl;

        vector <Propuesta> prop = subastas[i].propuestas;
        SortPropuestas(prop);
        for(auto it=begin(prop); it != end(prop); it++){
            os << (*it).alias << " " << (*it).monto << endl;
        }
    }
}


