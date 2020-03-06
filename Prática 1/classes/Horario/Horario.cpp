#include <iostream>
#include "Horario.h"

using namespace std;

//Constructors
Horario::Horario(){}

Horario::Horario(int h = 0, int m = 0, int s = 0){
    this->hora = h;
    this->minuto = m;
    this->segundo = s;
}

Horario::Horario(const Horario &hms){
    this->hora = hms.hora;
    this->minuto = hms.minuto;
    this->segundo = hms.segundo;
}

//Setters
void Horario::setHora(int h){
    this->hora = h;
}

void Horario::setMinuto(int m){
    this->minuto = m;
}

void Horario::setSegundo(int s){
    this->segundo = s;
}

//Getters
int Horario::getHora(){
    return this->hora;
}

int Horario::getMinuto(){
    return this->minuto;
}

int Horario::getSegundo(){
    return this->segundo;
}

//Others
int Horario::compHorario(const Horario &hms){
    if(this->hora > hms.hora){
        return 1;
    }else if(this->hora < hms.hora){
        return -1;
    }else{
        if(this->minuto > hms.minuto){
            return 1;
        }else if(this->minuto < hms.minuto){
            return -1;
        }else{
            if(this->segundo > hms.segundo){
                return 1;
            }else if(this->segundo < hms.segundo){
                return -1;
            }else{
                return 0;
            }
        }
    }
}

int Horario::difSegundos(const Horario &hms){
    int dif = 0;
    dif = (this->hora - hms.hora)*3600;
    dif = dif + (this->minuto - hms.minuto)*60;
    dif = dif + (this->segundo - hms.segundo);
    return dif;
}

void Horario::imprime(){
    cout << this->hora << ":" << this->minuto << ":" << this->segundo << endl;
}

void Horario::operator<<(const Horario &hr){
    cout << hr.hora << "/" << hr.minuto << "/" << hr.segundo << endl;
}

void Horario::operator>>(const Horario &hr){
    int h = hr.hora;
    int m = hr.minuto;
    int s = hr.segundo;
 
}

