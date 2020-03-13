#include "FigBase.h"

//Constructor
FigBase::FigBase(double x, double y, int expessura, int cor, int tipo){
    this->setX(x);
    this->setY(y);
    this->setExpessura(expessura);
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

int FigBase::getExpessura()const{
    return this->expessura;
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

void FigBase::setExpessura(int expessura){

    if(expessura <= 1){
        this->expessura = 1;
    }else if(expessura >= 5){
        this->expessura = 5;
    }else{
    this->expessura = expessura;
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
    cout << "Expessura: " << this->expessura << endl;
    cout << "Cor: " << this->cor << endl;
    cout << "Tipo: " << this->tipo << endl;
}