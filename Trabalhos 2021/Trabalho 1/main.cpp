#include <iostream>
#include <string>
#include <fstream>
#include "Acao.h"
#include "Cotacao.h"
#include "Split.h"
#include "Provento.h"
#include "Operacao.h"
#include "Evento.h"
#include "Carteira.h"

using namespace std;

string readTipo(const string &arquivo){
    ifstream arquivoOperacoes(arquivo);
    string tipo;

    getline(arquivoOperacoes, tipo);

    return tipo;
}

int main(int argc, char *argv[]){

    Cotacao *cotacoes = new Cotacao[500000];
    Split *splits = new Split[500000];
    Provento *proventos = new Provento[500000];
    Operacao *operacoes = new Operacao[500000];
    Evento *eventos = new Evento[1500000];
    string tipoSaida;
    Carteira carteira;

    const string nomeArquivoCotacoes = argv[1];
    int qtd_cotacoes = Cotacao::readCotacoes(nomeArquivoCotacoes, cotacoes);

    const string nomeArquivoSplits = argv[2];
    int qtd_splits =  Split::readSplits(nomeArquivoSplits, splits);

    const string nomeArquivoProventos = argv[3];
    int qtd_proventos = Provento::readProventos(nomeArquivoProventos, proventos);

    const string nomeArquivoOperacoes = argv[4];
    tipoSaida = readTipo(nomeArquivoOperacoes);
    int qtd_operacoes = 0;
    if(tipoSaida == "Q"){
        qtd_operacoes = Operacao::readConsultas(nomeArquivoOperacoes, operacoes);
        for(int i=0; i < qtd_operacoes; i++) cout << operacoes[i].getTipo() << " " << operacoes[i].getTiker() << " " << operacoes[i].getData() << " " << operacoes[i].getQuantidade() << endl;
        Operacao::exibeConsultas(operacoes, cotacoes);
        return 0;
    }else if(tipoSaida != "Q"){
        qtd_operacoes = Operacao::readOperacoes(nomeArquivoOperacoes, operacoes);
    }

    int soma_eventos = qtd_splits + qtd_proventos + qtd_operacoes;

    Evento::preencheVetorDeEventos(proventos, splits, operacoes, eventos);
    Evento::mergeSort(eventos, 0, soma_eventos);

    Cotacao::mergeSort(cotacoes, 0, qtd_cotacoes);

    carteira.executaEventos(cotacoes, proventos, splits, operacoes, carteira, eventos, soma_eventos);

    // Dividendos - splits - operações

    //Coisas pra amanhã:
    /* 
        1- Terminar os construtores, operadores de atribuição e destrutores
        2- Criar classe carteira
        3- Organizar melhor os dados armazenados em memória
        4- Fazer a ordenação dos vetores de acordo com o critério mais cabível
        5- Criar Classe de eventos - vetor de eventos
        6- Criar saída do tipo consulta
        7- Criar saída do tipo Mês a Mês
        8- Criar saída do tipo Total Final
        9- Criar saída do tipo detalhada
        10- Tratar corner-cases
     */

    delete []eventos;
    delete []operacoes;
    delete []proventos;
    delete []splits;
    delete []cotacoes;
    return 0;
}