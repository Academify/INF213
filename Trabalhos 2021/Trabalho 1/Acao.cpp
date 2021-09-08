#include "Acao.h"
#include <string>

//Construtores
Acao::Acao(){
    this->setTiker("");
    this->setValue(0);
}

Acao::Acao(const string &tiker, const double &value){
    this->setTiker(tiker);
    this->setValue(value);
}

//Setters

void Acao::setTiker(const string &tiker){
    this->tiker = tiker;
}

void Acao::setValue(const double &value){
    this->value = value;
}

//Getters

const string &Acao::getTiker()const{
    return this->tiker;
}

const double &Acao::getValue()const{
    return this->value;
}

