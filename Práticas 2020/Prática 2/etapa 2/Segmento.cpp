#include "Segmento.h"

Segmento::Segmento(double x, double y, double x2, double y2, int expessura, int cor, int tipo) :FigBase(x,y,expessura,cor,tipo){
    setX2(x2);
    setY2(y2);
}

double Segmento::getX2()const{
    return this->x2;
}

double Segmento::getY2()const{
    return this->y2;
}

void Segmento::setX2(double x2){
    this->x2 = x2;
}

void Segmento::setY2(double y2){
    this->y2=y2;
}

float Segmento::area()const{
    return 0;
}

float Segmento::perimetro() const {
    if (x2-y2 >= 0)
		return x2-y2;
	return y2-x2;      
}

void Segmento::imprime() const {
    cout << "--- [Segmento] ---" << endl;
	FigBase::imprime();
    cout << " x2 = " << getX2() << " y2 = " << getY2() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}