#include <iostream>
#include "MySet.h"

using namespace std;

int main() {

    MySet<int> database;
	int numero;
    char operacao;

    while (cin >> operacao >> numero){

        if (operacao == 'C'){
            if (database.find(numero) == database.end()){
                database.insert(numero);
            }

        } else if (operacao == 'S'){
            MySet<int>::iterator posicao = database.find(numero);

            if (posicao != database.end() && ++posicao != database.end())
                cout << *posicao << endl;
            else 
                cout << "FALHA" << endl;          
        }
    }
}
