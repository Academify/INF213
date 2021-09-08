#ifndef COTACAO_H
#define COTACAO_H
#include "Acao.h"

class Cotacao{
    private:
        string dataCotacao;
        Acao acao;
        static void merge(Cotacao *&v, int p, int q, int r);
        //static int buscaBin(Cotacao *&array, int begin, int end, string tiker, string data);
    public:
        //Construtores
        Cotacao();
        
        Cotacao(const Acao &, const string &);

        //Setters
        void setDataCotacao(const string &);
        void setAcao(const Acao &);

        //Getters
        const string &getDataCotacao()const;
        const Acao &getAcao()const;
        
        //Others
        static int readCotacoes(const string &, Cotacao *&cotacoes);
        const Cotacao index(const Cotacao *&)const;
        static void mergeSort(Cotacao *&v, int p, int r);
        static Cotacao &buscaCotacao(Cotacao *&v, const string &tiker, const string &data);

};

#endif
