#include <iostream>
#include <string>

using namespace std;

void calculaDigitoVerificador(string cpf){
    int novoCpf[11];
    for (int i = 0; i<cpf.length(); i++){
        novoCpf[i] = cpf[i] - 48;
    }
    
    int fator = 10;
    int digito1, digito2 = 0;
    int soma = 0;
    string aux;

    for(int i = 0; i < 9; i++){
        soma += novoCpf[i] * fator;
        fator--;
    }

    digito1 = (10 * soma) % 11;
    if(digito1 == 10) digito1 = 0;
    novoCpf[9] = digito1;

    fator = 11;
    soma = 0;
    for(int i = 0; i < 10; i++){
        soma += novoCpf[i] * fator;
        fator--;
    }

    digito2 = (10 * soma) % 11;
    if(digito2 == 10) digito2 = 0;
    novoCpf[10] = digito2;

    cout << novoCpf[9] << novoCpf[10] << endl;
}

int main(){

    int n;
    string cpf;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cpf;
        calculaDigitoVerificador(cpf);
    }
    return 0;
}