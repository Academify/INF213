#ifndef Segmento_h
#define Segmento_h

#include "FigBase.h"

#include <iostream>
using namespace std;

class Segmento : public FigBase{
private:
    double x2;
    double y2;
public:
    Segmento(double, double, double, double, int, int, int);

    double getX2()const;
    double getY2()const;

    void setX2(double);
    void setY2(double);

    float area()const;
    float perimetro()const;
    void imprime()const;
};
#endif