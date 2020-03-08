#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;
class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:
        //Setters
        void setDia(int);
        void setMes(int);
        void setAno(int);

        //Getters
        int getDia()const;
        int getMes()const;
        int getAno()const;

        //Constructors
        Data();
        Data(int, int, int);
        Data(const Data &);

        //Others
        int compData(const Data &)const;
        int difDias(const Data &)const;
        void imprime();

        //Operadores
        friend istream &operator>>(istream &,  Data &);
        friend ostream &operator<<(ostream &, const Data &);
        
};
#endif