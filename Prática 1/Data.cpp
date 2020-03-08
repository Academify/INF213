#include "Data.h"

//Constructors

Data::Data(){}

Data::Data(int d, int m = 1, int a = 2018){
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
    if(d >= 1){
        this->dia = d;
    }else{
        this->dia = 1;
    }
    if(d <= 30){
        this->dia = d;
    }else{
        this->dia = 30;
    }
}

void Data::setMes(int m){

    if(m >= 1){
        this->mes = m;
    }else{
        this->mes = 1;
    }

    if(m <=12){
        this->mes = m;
    }else{
        this->mes = 12;
    }
}

void Data::setAno(int a){

    if(a >= 2018){
        this->ano = a;
    }else{
        this->ano = 2018;
    }

    if(a <= 2020){
        this->ano = a;
    }else{
        this->ano = 2020;
    }
}

//Getters
int Data::getDia()const{
    return this->dia;
}

int Data::getMes()const{
    return this->mes;
}

int Data::getAno()const{
    return this->ano;
}

//Others
int Data::compData(const Data &dma)const{
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

int Data::difDias(const Data &dma)const{
    int dif = 0;
    dif = (((this->ano - dma.ano)*12)*30);
    dif = dif + ((this->mes) - dma.mes)*30;
    dif = dif + (this->dia - dma.dia);
    return dif;
}

void Data::imprime(){
    cout << this->dia << " " << this->mes << " " << this->ano;
}

//Operators

istream &operator>>(istream &in, Data &dt){
    int d, m, a;
    in >> d >> m >> a;

    dt.setDia(d);
    dt.setMes(m);
    dt.setAno(a);
    return in;
}

ostream &operator<<(ostream &out, const Data &dt){
    out << dt.getDia() << " " << dt.getMes() << " " << dt.getAno();
    return out;
}