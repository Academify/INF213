#ifndef ACAO_H
#define ACAO_H
#include <string>
#include <iostream>

using namespace std;

class Acao{
    private:
        string tiker;
        double value;
    public:
        //Construtores
        Acao();
        Acao(const string &tiker, const double &value);

        //Setters
        void setTiker(const string &);
        void setValue(const double &);

        //Getters
        const string &getTiker()const;
        const double &getValue()const;
};

#endif