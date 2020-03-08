#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>
using namespace std;

class Horario{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        //Constructors
        Horario();
        Horario(int, int, int);
        Horario(const Horario &);

        //Setters
        void setHora(int);
        void setMinuto(int);
        void setSegundo(int);

        //Getters
        int getHora()const;
        int getMinuto()const;
        int getSegundo()const;

        //Others
        int compHorario(const Horario &)const;
        int difSegundos(const Horario &)const;
        void imprime();

        //Operators
        friend istream &operator>>(istream &, Horario &);
        friend ostream &operator<<(ostream &, const Horario &);
};
#endif
