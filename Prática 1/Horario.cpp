#include "Horario.h"

//Constructors

Horario::Horario(int h, int m = 0, int s = 0){
    this->hora = h;
    this->minuto = m;
    this->segundo = s;
}

Horario::Horario(const Horario &hms){
    this->hora = hms.hora;
    this->minuto = hms.minuto;
    this->segundo = hms.segundo;
}

//Setters
void Horario::setHora(int h){
    if(h >= 0){
        this->hora = h;
    }else{
        this->hora = 0;
    }

    if( h <= 23){
        this->hora = h;
    }else{
        this->hora = 23;
    }
}

void Horario::setMinuto(int m){
    if(m >= 0){
        this->minuto = m;
    }else{
        this->minuto = 0;
    }

    if(m <= 59){
        this->minuto = m;
    }else{
        this->minuto = 59;
    }
}

void Horario::setSegundo(int s){
    if(s >= 0){
        this->segundo = s;
    }else{
        this->segundo = 0;
    }

    if(s <= 59){
        this->segundo = s;
    }else{
        this->segundo = 59;
    }
}

//Getters
int Horario::getHora()const{
    return this->hora;
}

int Horario::getMinuto()const{
    return this->minuto;
}

int Horario::getSegundo()const{
    return this->segundo;
}

//Others
int Horario::compHorario(const Horario &hms){
    if(this->hora > hms.hora){
        return 1;
    }else if(this->hora < hms.hora){
        return -1;
    }else{
        if(this->minuto > hms.minuto){
            return 1;
        }else if(this->minuto < hms.minuto){
            return -1;
        }else{
            if(this->segundo > hms.segundo){
                return 1;
            }else if(this->segundo < hms.segundo){
                return -1;
            }else{
                return 0;
            }
        }
    }
}

int Horario::difSegundos(const Horario &hms){
    int dif = 0;
    dif = (this->hora - hms.hora)*3600;
    dif = dif + (this->minuto - hms.minuto)*60;
    dif = dif + (this->segundo - hms.segundo);
    return dif;
}

void Horario::imprime(){
    cout << this->hora << " " << this->minuto << " " << this->segundo;
}

istream &operator>>(istream &in, Horario &hr){
    int h,m,s;

    in >> h >> m >> s;

    hr.setHora(h);
    hr.setMinuto(m);
    hr.setSegundo(s);

    return in;
}

ostream &operator<<(ostream &out, Horario &hr){
    out << hr.getHora << ":" << hr.getMinuto() << ":" << hr.getSegundo() << endl;
    return out;
}



