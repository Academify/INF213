#ifndef Retangulo_h
#define Retangulo_h

#include "FigBase.h"

class Retangulo: public FigBase{
    private:
        double largura;
        double altura;
    public:
        //Constructors
        Retangulo(double, double);
        
        //Getters
        double getLargura();
        double getAltura();

        //Setters
        void setLargura( double);
        void setAltura(double);

        //Others
        float area();
        float perimetro();
        void imprime();
};

#endif