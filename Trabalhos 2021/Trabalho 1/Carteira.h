#ifndef CARTEIRA_H
#define CARTEIRA_H
#include "Acao.h"
#include "Evento.h"
#include "Provento.h"
#include "Split.h"
#include "Operacao.h"
#include "Cotacao.h"

using namespace std;

class Carteira{
    private:
        //Vetor de açoes
        Acao acoes[100];
        // Vetor de quantidade de acoes
        int quantidades[100];


        //Dividendos
        //Vetor de total de dividendos por acao
        double totaisProventosPorAcao[100];
        //Total dividendos no mês
        double totaisProventosMensal[100];


        //Compra
        //Total Gasto por acao
        double totalGastosPorAcao[100];
        //Total Gasto por ação mensal
        double totalGastosMensal[100];


        //Venda
        //Total ganho por acao
        double totalGanhoPorAcao[100];
        //Total ganho por acao Mensal
        double totalGanhoMensal[100];

        
        // Funções que fazem as movimentações:
        //- compra de ações
        void compraAcao(Cotacao *&cotacoes, const int &index, const string &tiker, const string &data, const int &quantidade);
        void compraNovaAcao(Cotacao *&cotacoes, Carteira carteira, const string &tiker, const string &data, const int &quantidade);
        //- venda de acoes
        void vendeAcao(Cotacao *&cotacoes, const int &index, const string &tiker, const string &data, const int &quantidade);
        //- pagamento de dividendos
        void pagaDividendos(const int &index, const double &valor);
        //- recalculo de quantidade por conta de splits
        void recalculaQuantidadeAcoes(const int &index, const unsigned int &dividendo, const unsigned int &divisor);
        
    public:
        //Construtores e Destrutores
        Carteira();
        ~Carteira();

        //Getters
        unsigned int getQuantidadeAcoes()const;
        const int &getQuantidadePorAcao(const int &index)const;
        const double &getTotalProventosPorAcao(const int &index)const;
        const double &getTotalProventosMensalPorAcao(const int &index)const;
        const double &getTotalGastosPorAcao(const int &index)const;
        const double &getTotalGastosMensalPorAcao(const int &index)const;
        const double &getTotalGanhoPorAcao(const int &index)const;
        const double &getTotalGanhoMensalPorAcao(const int &index)const;

        //Uteis
        //Executa operações
        void executaEventos(Cotacao *&cotacoes, Provento *&proventos, Split *&splits, Operacao *&operacoes, Carteira &carteira, Evento *&eventos, const int &soma_eventos);
};

#endif