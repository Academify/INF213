
#ifndef AGENDA_H
#define AGENDA_H
#include <string>
#include <iostream>

#include "Horario.h"
#include "Data.h"

using namespace std;

class ItemAgenda{
    
    private:
        string descricao;
        Data d;
        Horario h;
    public:
        //Constructors
        ItemAgenda();
        ItemAgenda(const string &, const Data &, const Horario &);
        ItemAgenda(const ItemAgenda &);

        //Setters
        void setDesc(const string &);
        void setData(const Data &);
        void setHorario(const Horario &);

        //Getters
        const string &getDesc()const;
        const Data &getData()const;
        const Horario &getHorario()const;
};

class Agenda {
    public:
        Agenda();
        void inserirItem(const ItemAgenda &);
        void compromissosData(const Data &)const;
    private:
        ItemAgenda itens[1000];
        int cont = 0;
};



#endif //PRÁTICA_1_AGENDA_H
