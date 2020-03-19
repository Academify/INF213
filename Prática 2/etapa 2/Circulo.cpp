#include "Circulo.h"

const float PI = 3.141592653589;

Circulo::Circulo(double x, double y, double raio, int espessura, int cor, int tipo) : FigBase(x,y,espessura, cor, tipo){
    this->raio = raio;
}

double Circulo::getRaio()const{
    return this->raio;
}

void Circulo::setRaio(double raio){
    this->raio = raio;
}

float Circulo::area()const{
    return PI*(raio*raio);
}

float Circulo::perimetro()const{
    return 2 * PI * raio;
}

void Circulo::imprime()const{
    cout << "--- [Circulo] ---" << endl;
	FigBase::imprime();
    cout << " raio = " << getRaio() << endl; 
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}