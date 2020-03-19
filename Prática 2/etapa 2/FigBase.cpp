#include "FigBase.h"

//Constructor
FigBase::FigBase(double x, double y, int espessura, int cor, int tipo){
    this->setX(x);
    this->setY(y);
    this->setEspessura(espessura);
    this->setCor(cor);
    this->setTipo(tipo);
}

//Getters

double FigBase::getX()const{
    return this->x;
}

double FigBase::getY()const{
    return this->y;
}

int FigBase::getEspessura()const{
    return this->espessura;
}

int FigBase::getCor()const{
    return this->cor;
}

int FigBase::getTipo()const{
    return this->tipo;
}

//Setters

void FigBase::setX(double x){
    this->x = x;
}

void FigBase::setY(double y){
    this->y = y;
}

void FigBase::setEspessura(int espessura){

    if(espessura <= 1){
        this->espessura = 1;
    }else if(espessura >= 5){
        this->espessura = 5;
    }else{
    this->espessura = espessura;
    }
}

void FigBase::setCor(int cor){

    if(cor <= 1){
        this->cor = 1;
    }else if(cor >= 5){
        this->cor = 5;
    }else{
    this->cor = cor;
    }
}

void FigBase::setTipo(int tipo){

    if(tipo <= 1){
        this->tipo = 1;
    }else if(tipo >= 3){
        this->tipo = 3;
    }else{
    this->tipo = tipo;
    }
}

//Others

void FigBase::imprime()const{
    
    cout << "X: " << this->x << endl;
    cout << "Y: " << this->y << endl;
    cout << "Espessura: " << this->espessura << endl;
    cout << "Cor: " << this->cor << endl;
    cout << "Tipo: " << this->tipo << endl;
}