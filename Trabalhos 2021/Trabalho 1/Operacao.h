#ifndef OPERACAO_H
#define OPERACAO_H
#include <string>
#include <iostream>
#include "Cotacao.h"

using namespace std;

class Operacao{
    private:
        string tipo;
        string tiker;
        string data;
        int quantidade;
    public:
        //Setters
        void setTipo(const string &);
        void setTiker(const string &);
        void setData(const string &);
        void setQuantidade(const int &);

        //Getters
        const string &getTipo()const;
        const string &getTiker()const;
        const string &getData()const;
        const int &getQuantidade()const;
        static int getQuantidadeOperacoes(Operacao *&operacoes);

        //Others
        static int readOperacoes(const string &, Operacao *&operacoes);
        static int readConsultas(const string &, Operacao *&operacoes);
        static void exibeConsultas(Operacao *&operacoes, Cotacao *&cotacoes);
};

#endif