#include "Retangulo.h"

Retangulo::Retangulo(double x, double y, double largura, double altura, int expessura, int cor, int tipo):FigBase(x, y, expessura, cor, tipo){ //Resolver isso...
    setLargura(largura);
    setAltura(altura);
}
//Getters
double Retangulo::getLargura()const{
    return this->largura;
}

double Retangulo::getAltura() const{
    return this->altura;
}

//Setters
void Retangulo::setLargura(double largura){
    this->largura = largura;
}

void Retangulo::setAltura(double altura){
    this->altura = altura;
}

//Others

float Retangulo::area()const{
    return (largura * altura);
}

float Retangulo::perimetro()const{
    return 2*(largura+altura);
}

void Retangulo::imprime() const {
    cout << "--- [Retangulo] ---" << endl;
	FigBase::imprime();
    cout << " largura = " << getLargura() << " altura = " << getAltura() << endl;  
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}




