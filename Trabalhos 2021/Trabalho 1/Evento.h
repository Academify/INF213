#ifndef EVENTO_H
#define EVENTO_H
#include "Acao.h"
#include "Evento.h"
#include "Provento.h"
#include "Operacao.h"
#include "Split.h"

class Evento{
    private:
        string data;
        string tipo;
        int codigo;
        static void merge(Evento *&v, int p, int q, int r);
    public:
        string getData();
        string getTipo();
        int getCodigo();
        static void preencheVetorDeEventos(Provento *&proventos, Split *&splits, Operacao *&operacoes, Evento *&eventos);
        static void mergeSort(Evento *&v, int p, int r);

};

#endif