#include <string>
#include <fstream>
#include "Operacao.h"
#include "Cotacao.h"

void Operacao::setTipo(const string &tipo){
    this->tipo = tipo;
}

void Operacao::setTiker(const string &tiker){
    this->tiker = tiker;
}

void Operacao::setData(const string &data){
    this->data = data;
}

void Operacao::setQuantidade(const int &quantidade){
    this->quantidade = quantidade;
}

const string &Operacao::getTipo()const{
    return this->tipo;
}

const string &Operacao::getTiker()const{
    return this->tiker;
}

const string &Operacao::getData()const{
    return this->data;
}

const int &Operacao::getQuantidade()const{
    return this->quantidade;
}

int Operacao::getQuantidadeOperacoes(Operacao *&operacoes){
    int aux = 0;
    while(operacoes[aux].getTiker() != "") aux ++;
    return aux;
}

int Operacao::readOperacoes(const string &arquivo, Operacao *&operacoes){
    ifstream arquivoOperacoes(arquivo);
    string linha, conteudo;
    string particionado[4];
    int aux = 0;
    size_t beg = 0, pos = 0;
    
    while(getline(arquivoOperacoes, linha)){
        if(linha.length() != 1){
            for(int i = 0; i < 4; i++){
                pos = linha.find(',', beg);
                conteudo = linha.substr(beg, pos - beg);
                beg = pos + 1;
                particionado[i] = conteudo;
            }
            operacoes[aux].setData(particionado[0]);
            operacoes[aux].setTipo(particionado[1]);
            operacoes[aux].setTiker(particionado[2]);
            operacoes[aux].setQuantidade(stoi(particionado[3]));
            aux++;
        }
    }
    return aux;
}

int Operacao::readConsultas(const string &arquivo, Operacao *&operacoes){
    ifstream arquivoOperacoes(arquivo);
    string linha, conteudo;
    string particionado[4];
    int aux = 0;
    size_t beg = 0, pos = 0;
    
    while(getline(arquivoOperacoes, linha)){
        if(linha.length() != 1){
            for(int i = 0; i < 3; i++){
                pos = linha.find(',', beg);
                conteudo = linha.substr(beg, pos - beg);
                beg = pos + 1;
                particionado[i] = conteudo;
            }
            operacoes[aux].setData(particionado[0]);
            operacoes[aux].setTipo(particionado[1]);
            operacoes[aux].setTiker(particionado[2]);
            operacoes[aux].setQuantidade(0);
            aux++;
        }
    }
    return aux;
}

void Operacao::exibeConsultas(Operacao *&operacoes, Cotacao *&cotacoes){
    for(int i = 0; i < Operacao::getQuantidadeOperacoes(operacoes); i++){
        Cotacao c = Cotacao::buscaCotacao(cotacoes, operacoes[i].getTiker(), operacoes[i].getData());
        int valor = (int) (c.getAcao().getValue() * 100);
        cout << valor << endl;
    }
}