#include <iostream>
#include "Data.h"

using namespace std;

//Constructors
//Data::Data(){}

Data::Data(int d =1, int m = 1, int a = 2018){
    this->dia = d;
    this->mes = m;
    this->ano = a;
}

Data::Data(const Data &dt){
    this->dia = dt.dia;
    this->mes = dt.mes;
    this->ano = dt.ano;
}

//Setters
void Data::setDia(int d){
    this->dia = d;
}

void Data::setMes(int m){
    this->mes = m;
}

void Data::setAno(int a){
    this->ano = a;
}

//Getters
int Data::getDia(){
    return this->dia;
}

int Data::getMes(){
    return this->mes;
}

int Data::getAno(){
    return this->ano;
}

//Others
int Data::compData(const Data &dma){
    if(this->ano > dma.ano){
        return 1;
    }else if(this->ano < dma.ano){
        return-1;
    }else{
        if(this->mes > dma.mes){
            return 1;
        }else if(this->mes < dma.mes){
            return -1;
        }else{
            if(this->dia > dma.dia){
                return 1;
            }else if(this->dia < dma.dia){
                return -1;
            }else{
                return 0;
            }
        }
    }
}

int Data::difDias(const Data &dma){
    int dif = 0;
    return dif = quantDias(*this, dma);
}

void Data::imprime(){
    cout << this->dia << "/" << this->mes << "/" << this->ano << endl;
}

int Data::quantDias(Data dt1, Data dt2){
    int dif = (((dt1.ano - dt2.ano)*12)*30);
    dif = dif + ((dt1.mes) - dt2.mes)*30;
    dif = dif + (dt1.dia - dt2.dia);
    return dif;
}

//Operators

void Data::operator<<(const Data &dt){
    cout << dt.dia << "/" << dt.mes << "/" << dt.ano << endl;
}

Data Data::operator>>(istream entrada /* const Data &dt */){
    int d = 0 ;
    int m = 0 ;
    int a = 0 ;

    cin >> d >> m >> a;
    Data dt;

    dt.setDia(d);
    dt.setMes(m);
    dt.setAno(a);

    return dt;

/*
    cin >> d >> m >> a; */

}