#include <string>
#include <fstream>
#include "Split.h"

void Split::setTiker(const string &tiker){
    this->tiker = tiker;
}

void Split::setData(const string &data){
    this->data = data;
}

void Split::setRatio(const string &ratio){
    int pos = ratio.find(':', 0);
    this->dividendo = stoi(ratio.substr(0, pos));
    this->divisor = stoi(ratio.substr(pos + 1, ratio.length() - (pos + 1)));
}

const string &Split::getTiker()const{
    return this->tiker;
}

const string &Split::getData()const{
    return this->data;
}

const int &Split::getDividendo()const{
    return this->dividendo;
}

const int &Split::getDivisor()const{
    return this->divisor;
}

int Split::readSplits(const string &arquivo, Split *&splits){
    ifstream arquivoSplits(arquivo);
    string linha, conteudo;
    string particionado[3];
    int aux = 0;

    size_t beg = 0, pos = 0;

    while(getline(arquivoSplits, linha)){
        for(int i = 0; i < 3; i++){
            pos = linha.find(',', beg);
            conteudo = linha.substr(beg, pos - beg);
            beg = pos + 1;
            particionado[i] = conteudo;
        }
        splits[aux].setTiker(particionado[0]);
        splits[aux].setData(particionado[1]);
        splits[aux].setRatio(particionado[2]);

        aux++;
    }
    return aux;
}