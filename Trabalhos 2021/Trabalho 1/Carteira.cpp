#include <string>
#include <fstream>
#include "Carteira.h"
#include "Cotacao.h"

Carteira::Carteira(){
    for(int i=0; i<100; i++){
        quantidades[i] = 0;
        totaisProventosPorAcao[i] = 0;
        totaisProventosMensal[i] = 0;
        totalGastosPorAcao[i] = 0;
        totalGastosMensal[i] = 0;
        totalGanhoPorAcao[i] = 0;
        totalGanhoMensal[i] = 0;
    }
}
Carteira::~Carteira(){}

unsigned int Carteira::getQuantidadeAcoes()const{
    unsigned int length = 0;
    while(this->acoes[length].getTiker() != ""){
        length++;
    }
    return length;
}

const int &Carteira::getQuantidadePorAcao(const int &index)const{
    return quantidades[index];
}

const double &Carteira::getTotalProventosPorAcao(const int &index)const{
    return totaisProventosPorAcao[index];
}

const double &Carteira::getTotalProventosMensalPorAcao(const int &index)const{
    return totaisProventosMensal[index];
}

const double &Carteira::getTotalGastosPorAcao(const int &index)const{
    return totalGastosPorAcao[index];
}

const double &Carteira::getTotalGastosMensalPorAcao(const int &index)const{
    return totalGastosMensal[index];
}

const double &Carteira::getTotalGanhoPorAcao(const int &index)const{
    return totalGanhoPorAcao[index];
}

const double &Carteira::getTotalGanhoMensalPorAcao(const int &index)const{
    return totalGanhoMensal[index];
}

void Carteira::executaEventos(Cotacao *&cotacoes, Provento *&proventos, Split *&splits, Operacao *&operacoes, Carteira &carteira, Evento *&eventos, const int &soma_eventos){
    string p = "p", s = "s", o = "o"; //Tipos de eventos
    string c = "C", v = "V", q = "Q";

    for(int i = 0; i < soma_eventos; i++){
        if(eventos[i].getTipo() == p){
            for(int j = 0; j < carteira.getQuantidadeAcoes(); j++){
                if(carteira.acoes[j].getTiker() == proventos[eventos[i].getCodigo()].getTiker()){
                    //Paga dividendo de acordo com a quantidade de ações na carteira
                    cout << "PROVENTO de " << proventos[eventos[i].getCodigo()].getData() << endl;
                    cout << "Ticker: " << proventos[eventos[i].getCodigo()].getTiker() << endl;
                    cout << "Qtd: " << quantidades[j] << endl;
                    cout << "Valor: " << proventos[eventos[i].getCodigo()].getValor() << endl;
                    cout << "Total ganho por acao antes: " << totalGanhoPorAcao[j] << endl;
                    pagaDividendos(j, proventos[eventos[i].getCodigo()].getValor());
                    cout << "Total ganho por acao depois: " << totalGanhoPorAcao[j] << endl;
                    cout << endl;
                }
            }
        }else if(eventos[i].getTipo() == s){
            for(int j = 0; j < carteira.getQuantidadeAcoes(); j++){
                if(carteira.acoes[j].getTiker() == splits[eventos[i].getCodigo()].getTiker()){
                    cout << "SPLIT de " << splits[eventos[i].getCodigo()].getData() << endl;
                    cout << "Ticker: " << splits[eventos[i].getCodigo()].getTiker() << endl;
                    cout << "Qtd antes: " << quantidades[j] << endl;
                    cout << "Razao do split: " << splits[eventos[i].getCodigo()].getDividendo() << ":" << splits[eventos[i].getCodigo()].getDivisor() << endl;
                    recalculaQuantidadeAcoes(j, splits[eventos[i].getCodigo()].getDividendo(), splits[eventos[i].getCodigo()].getDivisor());
                    cout << "Qtd depois: " << quantidades[j] << endl;
                    cout << endl;

                    //Multiplica ou divide a quantidade de açoes de acordo com o ratio
                }
            }
        }else if (eventos[i].getTipo() == o){
            if(operacoes[eventos[i].getCodigo()].getTipo() == c){
                bool novaAcao = false;
                for(int j = 0; j < carteira.getQuantidadeAcoes(); j++){
                    if(carteira.acoes[j].getTiker() == operacoes[eventos[i].getCodigo()].getTiker()){
                        cout << "COMPRA de " << operacoes[eventos[i].getCodigo()].getData() << endl;
                        cout << "Ticker: " << operacoes[eventos[i].getCodigo()].getTiker() << endl;
                        cout << "Qtd antes: " << quantidades[j] << endl;
                        cout << "Total gasto antes: " << totalGastosPorAcao[j] << endl;
                        cout << "Qtd comprada: " << operacoes[eventos[i].getCodigo()].getQuantidade()<< endl;            

                        compraAcao(cotacoes, j, operacoes[eventos[i].getCodigo()].getTiker(), operacoes[eventos[i].getCodigo()].getData(), operacoes[eventos[i].getCodigo()].getQuantidade());
                        cout << "Qtd depois: " << quantidades[j] << endl;
                        cout << "Total gasto depois: " << totalGastosPorAcao[j] << endl;
                        cout << endl;
                        novaAcao = true;
                        break;
                        //Compra mais ações do mesmo tiker
                    }
                }
                if(novaAcao == false){   
                    cout << "PRIMEIRA COMPRA de " << operacoes[eventos[i].getCodigo()].getData() << endl;
                    cout << "Ticker: " << operacoes[eventos[i].getCodigo()].getTiker() << endl;
                    cout << "Qtd antes: " << quantidades[getQuantidadeAcoes()] << endl;
                    cout << "Total gasto antes: " << totalGastosPorAcao[getQuantidadeAcoes()] << endl; 
                    cout << "Qtd comprada: " << operacoes[eventos[i].getCodigo()].getQuantidade()<< endl;            
            
                    compraNovaAcao(cotacoes, carteira, operacoes[eventos[i].getCodigo()].getTiker(), operacoes[eventos[i].getCodigo()].getData(), operacoes[eventos[i].getCodigo()].getQuantidade());
                    cout << "Qtd depois: " << quantidades[getQuantidadeAcoes()-1] << endl;
                    cout << "Total gasto depois: " << totalGastosPorAcao[getQuantidadeAcoes()-1] << endl;
                    cout << endl;
                    //Compra ação com tiker novo
                }
            }else if(operacoes[eventos[i].getCodigo()].getTipo() == v){
                for(int j = 0; j < carteira.getQuantidadeAcoes(); j++){
                    if(carteira.acoes[j].getTiker() == operacoes[eventos[i].getCodigo()].getTiker()){
                        
                        cout << "VENDA de " << operacoes[eventos[i].getCodigo()].getData() << endl;
                        cout << "Ticker: " << operacoes[eventos[i].getCodigo()].getTiker() << endl;
                        cout << "Qtd antes: " << quantidades[j] << endl;
                        cout << "Total ganho antes: " << totalGanhoPorAcao[j] << endl; 
                        cout << "Qtd vendida: " << operacoes[eventos[i].getCodigo()].getQuantidade()<< endl;            
                        if(operacoes[eventos[i].getCodigo()].getQuantidade() <= carteira.quantidades[j] && carteira.quantidades[j] != 0){
                            vendeAcao(cotacoes, j, operacoes[eventos[i].getCodigo()].getTiker(), operacoes[eventos[i].getCodigo()].getData(), operacoes[eventos[i].getCodigo()].getQuantidade());
                            //Decrementa a quantidade de ações no vetor de quantidades
                            //Aumenta o ganho de acordo com a quantidade
                        }
                        cout << "Qtd depois: " << quantidades[j] << endl;
                        cout << "Total ganho depois: " << totalGanhoPorAcao[j] << endl;
                        cout << endl;
                    }else{
                        //Mensagem de erro, pois não existe
                    }
                }
            }
        }
    }
}

//Privadas

void Carteira::compraNovaAcao(Cotacao *&cotacoes, Carteira carteira, const string &tiker, const string &data, const int &quantidade){
    Cotacao cotacao = Cotacao::buscaCotacao(cotacoes, tiker, data);
    int index = carteira.getQuantidadeAcoes();
    acoes[index] = Acao(tiker, cotacao.getAcao().getValue());
    quantidades[index] = quantidade;
    cout << "Valor da cotacao no dia: " << cotacao.getAcao().getValue() << endl;

    totalGastosPorAcao[index] += quantidade * cotacao.getAcao().getValue();
}

void Carteira::compraAcao(Cotacao *&cotacoes, const int &index, const string &tiker, const string &data, const int &quantidade){
    Cotacao cotacao = Cotacao::buscaCotacao(cotacoes, tiker, data);
    quantidades[index] += quantidade;
    cout << "Valor da cotacao no dia: " << cotacao.getAcao().getValue() << endl;
    totalGastosPorAcao[index] += quantidade * cotacao.getAcao().getValue();
}

void Carteira::vendeAcao(Cotacao *&cotacoes, const int &index, const string &tiker, const string &data, const int &quantidade){
    Cotacao cotacao = Cotacao::buscaCotacao(cotacoes, tiker, data);
    quantidades[index] -= quantidade;
    cout << "Valor da cotação no dia: " << cotacao.getAcao().getValue() << endl;

    totalGanhoPorAcao[index] += quantidade * cotacao.getAcao().getValue();
}

void Carteira::pagaDividendos(const int &index, const double &valor){
    int quantidade = this->getQuantidadePorAcao(index);
    totaisProventosPorAcao[index] += quantidade * valor;
    totalGanhoPorAcao[index] += quantidade * valor;
}

void Carteira::recalculaQuantidadeAcoes(const int &index, const unsigned int &dividendo, const unsigned int &divisor){
    quantidades[index] = (quantidades[index] * dividendo) / (divisor);
}