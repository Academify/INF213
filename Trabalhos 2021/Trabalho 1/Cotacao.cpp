#include <string>
#include <fstream>
#include "Cotacao.h"

Cotacao::Cotacao(){}

Cotacao::Cotacao(const Acao &acao, const string &data){
    this->acao = acao;
    this->dataCotacao = data;
}

void Cotacao::setDataCotacao(const string &dataCotacao){
    this->dataCotacao = dataCotacao;
}

void Cotacao::setAcao(const Acao &acao){
    this->acao = acao;
}

const string &Cotacao::getDataCotacao()const{
    return this->dataCotacao;
}

const Acao &Cotacao::getAcao()const{
    return this->acao;
}


int Cotacao::readCotacoes(const string &arquivo, Cotacao *&cotacoes){
    ifstream arquivoCotacoes(arquivo);
    string linha;
    string conteudo;
    string particionado[8];
    int aux = 0;

    size_t beg = 0, pos = 0;
    
    while(getline(arquivoCotacoes, linha)){
        for(int i = 0; i < 8; i++){
            pos = linha.find(',', beg);
            conteudo = linha.substr(beg, pos - beg);
            beg = pos + 1;
            particionado[i] = conteudo;
        }        
        cotacoes[aux].acao.setTiker(particionado[0]);
        cotacoes[aux].dataCotacao = particionado[1];
        cotacoes[aux].acao.setValue(stod(particionado[5]));
        aux++;
    }
    return aux;
}

void Cotacao::merge(Cotacao *&v, int p, int q, int r) {
    int tam = r-p;
    Cotacao *aux = new Cotacao[tam];
    int i = p; 
    int j = q; 
    int k = 0; 
    while(i < q && j < r) {
        if (v[i].dataCotacao <= v[j].dataCotacao){
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

void Cotacao::mergeSort(Cotacao *&v, int p, int r) {
    if (p < r-1) {
        int meio = (p+r) / 2;
        mergeSort(v, p, meio);
        mergeSort(v, meio, r);
        merge(v, p, meio, r);
    }
}

/* int Cotacao::buscaBin(Cotacao *&array, int begin, int end, string tiker, string data) {
	if (begin > end) return -1;
	int meio = (end-begin)/2 + begin;
    cout << "data cot   " << array[meio].getDataCotacao() << endl;
    cout << "tiker   " << array[meio].getAcao().getTiker() << endl;
	if (array[meio].getDataCotacao() == data && array[meio].getAcao().getTiker() == tiker){
        cout << "dentro do if" << endl;
		return meio;
    }
	if (array[meio].getDataCotacao() > data)
		return buscaBin(array,begin, meio-1, tiker, data); 
	return buscaBin(array,meio+1, end, tiker, data); 	
} */

Cotacao &Cotacao::buscaCotacao(Cotacao *&v, const string &tiker, const string &data){
    /* 
    int index = Cotacao::buscaBin(v, 0, aux-1, tiker, data);
    cout << "teste: " << index << endl;
    return v[index]; */
    long int aux = 0;
    while(v[aux].dataCotacao != "") aux++;
    for(long int i=0; i < aux; i++){
        if(v[i].acao.getTiker() == tiker && v[i].dataCotacao == data){
            return v[i];
        }
    }
}

