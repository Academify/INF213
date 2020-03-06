
#ifndef AGENDA_H
#define AGENDA_H
#include <string>
#include <iostream>
#include "../Data/Data.h"
#include "../Horario/Horario.h"

using namespace std;


class Agenda {
public:
    Agenda();
    void inserirItem(const ItemAgenda &it);
    void compromissosData(const Data &dt);
};

class ItemAgenda{
    
private:
    string descricao;
    Data d;
    Horario h;
public:
    //Constructors
    ItemAgenda();
    ItemAgenda(const string &desc, const Data &dt, const Horario &hr);
    ItemAgenda(const ItemAgenda &it);

    //Setters
    void setDesc(const string &desc);
    void setData(const Data &dt);
    void setHorario(const Horario &hr);

    //Getters
    const string getDesc();
    const Data getData();
    const Horario getHorario();
};

#endif //PRÁTICA_1_AGENDA_H
