#include <string>
#include "Evento.h"

string Evento::getData(){
    return this->data;
}

string Evento::getTipo(){
    return this->tipo;
}

int Evento::getCodigo(){
    return this->codigo;
}

void Evento::preencheVetorDeEventos(Provento *&proventos, Split *&splits, Operacao *&operacoes, Evento *&eventos){
    int aux = 0;
    int posVetorEventos = 0;

    while(proventos[aux].getTiker() != ""){

        eventos[posVetorEventos].tipo = "p";
        eventos[posVetorEventos].data = proventos[aux].getData();
        eventos[posVetorEventos].codigo = aux;

        posVetorEventos++;
        aux++;
    }
    aux = 0;
    while(splits[aux].getTiker() != ""){

        eventos[posVetorEventos].tipo = "s";
        eventos[posVetorEventos].data = splits[aux].getData();
        eventos[posVetorEventos].codigo = aux;

        posVetorEventos++;
        aux++;
    }
    aux = 0;
    while(operacoes[aux].getTiker() != ""){

        eventos[posVetorEventos].tipo = "o";
        eventos[posVetorEventos].data = operacoes[aux].getData();
        eventos[posVetorEventos].codigo = aux;

        posVetorEventos++;
        aux++;
    }
    //Preencher fechamento
}

void Evento::merge(Evento *&v, int p, int q, int r) {
    int tam = r-p;
    Evento *aux = new Evento[tam];
    int i = p; 
    int j = q; 
    int k = 0; 
    while(i < q && j < r) {
        if (v[i].getData() <= v[j].getData()){
            aux[k++] = v[i++];
        }
        else
            aux[k++] = v[j++];
    }
    while(i < q){
        aux[k++] = v[i++];
    }
    while(j < r){
        aux[k++] = v[j++];
    }
    for(k = 0; k < tam; k++){
        v[p+k] = aux[k];
    }
    delete []aux;
}

void Evento::mergeSort(Evento *&v, int p, int r) {
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(v, p, meio);
        mergeSort(v, meio, r);
        merge(v, p, meio, r);
    }
}