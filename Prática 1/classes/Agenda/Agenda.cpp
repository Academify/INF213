
#include "Agenda.h"
#include<string>

// --------------Classe Agenda--------------------------

//Constructors
Agenda::Agenda() {}

//Others

void Agenda::inserirItem(const ItemAgenda &it){
    
}

void Agenda::compromissosData(const Data &dt){
    

    
}

//-------------Classe ItemAgenda------------------------

//Constructors

ItemAgenda::ItemAgenda(){}

ItemAgenda::ItemAgenda(const string &desc, const Data &dt, const Horario &hr) : descricao(desc), d(dt), h(hr) {}

ItemAgenda::ItemAgenda(const ItemAgenda &it){
    this->d = it.d;
    this->h = it.h;
    this->descricao = it.descricao;
}

//Setters
void ItemAgenda::setDesc(const string &desc){
    this->descricao = desc;
}

void ItemAgenda::setData(const Data &dt){
    this->d = dt;
}

void ItemAgenda::setHorario(const Horario &hr){
    this->h = hr;
}

//Getters
const string &ItemAgenda::getDesc()const{
    return this->descricao;
}
const Data &ItemAgenda::getData()const{
    return this->d;
}

const Horario &ItemAgenda::getHorario()const{
    return this->h;
}