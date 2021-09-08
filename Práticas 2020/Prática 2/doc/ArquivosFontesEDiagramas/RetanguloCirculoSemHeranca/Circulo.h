
#ifndef __Circulo_h
#define __Circulo_h

class Circulo {
private:
    double x, y;   // centro
    double raio;

    // atributos da linha
    int espessura; // inteiro de 1 a 5
    int cor;       // inteiro de 1 a 5
    int tipo;      // inteiro de 1 a 3

public:
    Circulo(double, double, double, int, int, int);

    double getX() const;
    void setX(double);

    double getY() const;
    void setY(double);

    double getRaio() const;
    void setRaio(double);

    int getEspessura() const;
    void setEspessura(int);

    int getCor() const;
    void setCor(int);

    int getTipo() const;
    void setTipo(int);

    float area() const;
    float perimetro() const;

    void imprime() const;

};

#endif
