#include <iostream>
#include <string>

using namespace std;

int *converteCpf(string cpf){
    int beg = 0;
    int pos = 1;
    int *novoCpf;

    for(int i = 0; i < cpf.length(); i++){
        novoCpf[i] = stoi(cpf.substr(beg, pos));
        beg++;
        pos++;
    }
    return novoCpf;
}

int calculaDigitoVerificador(string cpf){
    int *novoCpf = converteCpf(cpf);
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

    fator = 11;
    soma = 0;
    for(int i = 0; i < 9; i++){
        soma += novoCpf[i] * fator;
        fator--;
    }

    soma = novoCpf[10] * fator;
    digito2 = (10 * soma) % 11;
    if(digito2 == 10) digito2 = 0;

    cout << digito1 << digito2 << endl;
    return 0;
}

int main(){

    int n;
    string cpf;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cpf;
        cout << calculaDigitoVerificador(cpf) << endl;
    }



    return 0;
}