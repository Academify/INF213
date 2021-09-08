#include "Agenda.h"
#include<string>

// --------------Classe Agenda--------------------------

//Constructors
Agenda::Agenda() {}

//Others

void Agenda::inserirItem(const ItemAgenda &it){
    this->itens[this->cont] = it;
    (this->cont)++;
}

void Agenda::compromissosData(const Data &dt)const{
    for (int i=0; i < this->cont; i++){

        Data data = this->itens[i].getData();

        if(data.compData(dt)==0){

            Horario hr = this->itens[i].getHorario();
            string desc = this->itens[i].getDesc();

            //hr.imprime();
            cout << hr << " " << desc << endl; 
        }
    }
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