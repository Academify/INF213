
#include "Circulo.h"
#include <iostream>
using std::cout;
using std::endl;

const float PI = 3.141592653589;

Circulo::Circulo(double x, double y, double r, 
                     int esp, int c, int t) {
    setX(x);
    setY(y);
    setRaio(r);
    setEspessura(esp);
    setCor(c);
    setTipo(t);
}

double Circulo::getX() const {
    return x;
}

void Circulo::setX(double x) {
    this->x = x;
}

double Circulo::getY() const {
    return y;
}

void Circulo::setY(double y) {
    this->y = y;
}

double Circulo::getRaio() const {
    return raio;
}

void Circulo::setRaio(double r) {
    raio = r;
}

int Circulo::getEspessura() const {
    return espessura;
}

void Circulo::setEspessura(int esp) {
    espessura = (esp < 1 || esp > 5) ? 1 : esp;
}

int Circulo::getCor() const {
    return cor;
}

void Circulo::setCor(int c) {
    cor = (c < 1 || c > 5) ? 1 : c;
}
    
int Circulo::getTipo() const {
    return tipo;
}

void Circulo::setTipo(int t) {
    tipo = (t < 1 || t > 3) ? 1 : t;;
}

float Circulo::area() const {
    return PI * raio * raio;    
}      
          
float Circulo::perimetro() const {
    return 2 * PI * raio;      
}


void Circulo::imprime() const {
    cout << "--- [Circulo] ---" << endl;
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << getEspessura() << endl;
    cout << "     Cor       = " << getCor() << endl;
    cout << "     Tipo      = " << getTipo() << endl;          
    cout << " x = " << getX() << " y = " << getY() << endl;
    cout << " raio = " << getRaio() << endl; 
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}
