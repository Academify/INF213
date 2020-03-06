#ifndef DATA_H
#define DATA_H
class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:
        //Setters
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);

        //Getters
        int getDia();
        int getMes();
        int getAno();

        //Constructors
        //Data();
        Data(int d, int m, int a);
        Data(const Data &dt);

        //Others
        int compData(const Data &dma);
        int difDias(const Data &dma);
        void imprime();
        int quantDias(Data dt1, Data dt2);

        //Operadores
        void operator<<(const Data &dt);
        Data operator>>(istream entrada);
};
#endif