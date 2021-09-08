#ifndef PROVENTO_H
#define PROVENTO_H
#include <string>
#include <iostream>

using namespace std;

class Provento{
    private:
        string tiker;
        string data;
        double valor;
    public:
        //Setters
        void setTiker(const string &);
        void setData(const string &);
        void setValor(const double &);

        //Getters
        const string &getTiker()const;
        const string &getData()const;
        const double &getValor()const;

        //Others
        static int readProventos(const string &arquivo, Provento *&proventos);
};

#endif