#ifndef HORARIO_H
#define HORARIO_H

class Horario{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        //Constructors
        Horario();
        Horario(int h, int m, int s);
        Horario(const Horario &);

        //Setters
        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);

        //Getters
        int getHora();
        int getMinuto();
        int getSegundo();

        //Others
        int compHorario(const Horario &hms);
        int difSegundos(const Horario &hms);
        void imprime();

        //Operators
        void operator<<(const Horario &dt);
        void operator>>(const Horario &dt);
};
#endif
