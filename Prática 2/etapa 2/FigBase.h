#ifndef FigBase_h
#define FigBase_h

#include <iostream>
using namespace std;

class FigBase{

    private:
        double x;
        double y;

        int expessura;
        int cor;
        int tipo;

    public:
        //Constructors
        FigBase(double, double, int, int, int);

        //Getters
        double getX()const;
        double getY()const;
        int getExpessura()const;
        int getCor()const;
        int getTipo()const;

        //Setters
        void setX(double);
        void setY(double);
        void setExpessura(int);
        void setCor(int);
        void setTipo(int);

        //Others
        void imprime()const;

};

#endif