
#include "Retangulo.h"
#include <iostream>
using std::cout;
using std::endl;

Retangulo::Retangulo(double x, double y, 
                     double larg, double alt,
                     int esp, int c, int t) {
    setX(x);
    setY(y);
    setLargura(larg);
    setAltura(alt);
    setEspessura(esp);
    setCor(c);
    setTipo(t);
}

double Retangulo::getX() const {
    return x;
}

void Retangulo::setX(double x) {
    this->x = x;
}

double Retangulo::getY() const {
    return y;
}

void Retangulo::setY(double y) {
    this->y = y;
}

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}
double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

int Retangulo::getEspessura() const {
    return espessura;
}

void Retangulo::setEspessura(int esp) {
    espessura = (esp < 1 || esp > 5) ? 1 : esp;
}

int Retangulo::getCor() const {
    return cor;
}

void Retangulo::setCor(int c) {
    cor = (c < 1 || c > 5) ? 1 : c;
}
    
int Retangulo::getTipo() const {
    return tipo;
}

void Retangulo::setTipo(int t) {
    tipo = (t < 1 || t > 3) ? 1 : t;;
}

float Retangulo::area() const {
    return altura * largura;     
}      
          
float Retangulo::perimetro() const {
    return 2*(largura + altura);      
}

void Retangulo::imprime() const {
    cout << "--- [Retangulo] ---" << endl;
    cout << " Atributos da linha: " << endl;
    cout << "     Espessura = " << getEspessura() << endl;
    cout << "     Cor       = " << getCor() << endl;
    cout << "     Tipo      = " << getTipo() << endl;      
    cout << " x = " << getX() << " y = " << getY() << endl;
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}
