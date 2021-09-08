#include <string>
#include <fstream>
#include "Provento.h"

void Provento::setTiker(const string &tiker){
    this->tiker = tiker;
}

void Provento::setData(const string &data){
    this->data = data;
}

void Provento::setValor(const double &valor){
    this->valor = valor;
}


const string &Provento::getTiker()const{
    return this->tiker;
}

const string &Provento::getData()const{
    return this->data;
}

const double &Provento::getValor()const{
    return this->valor;
}


int Provento::readProventos(const string &arquivo, Provento *&proventos){
    ifstream arquivoProventos(arquivo);
    string linha, conteudo;
    string particionado[3];
    int aux = 0;

    size_t beg = 0, pos = 0;

    while(getline(arquivoProventos, linha)){
        for(int i = 0; i < 3; i++){
            pos = linha.find(',', beg);
            conteudo = linha.substr(beg, pos - beg);
            beg = pos + 1;
            particionado[i] = conteudo;
        }
        proventos[aux].setTiker(particionado[0]);
        proventos[aux].setData(particionado[1]);
        proventos[aux].setValor(stod(particionado[2]));

        aux++;
    }
    return aux;
}
