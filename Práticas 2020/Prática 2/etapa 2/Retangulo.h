#ifndef Retangulo_h
#define Retangulo_h

#include "FigBase.h"

class Retangulo: public FigBase{
    private:
        double largura;
        double altura;
    public:
        //Constructors
        Retangulo(double, double, double, double, int, int, int);
        
        //Getters
        double getLargura()const;
        double getAltura()const;

        //Setters
        void setLargura( double);
        void setAltura(double);

        //Others
        float area()const;
        float perimetro()const;
        void imprime()const;
};

#endif