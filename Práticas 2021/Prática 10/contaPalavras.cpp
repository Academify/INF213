#include <iostream>
#include "MySet.h"
#include "MyVecNewIterator.h"

using namespace std;

int main(int argc, char *argv[]) {

	string tipoObjeto = argv[1];

	int qtdPalavras = 0;

	string palavra;

	if (tipoObjeto == "myvec"){
		MyVec<string> vec;
		bool unica = true;
		while(cin>>palavra){
			qtdPalavras++;
			for (int i = 0; i<vec.size(); i++){
				if (vec[i] == palavra) {
					unica = false;
					break;
				}
			}
			if (unica) vec.push_back(palavra);
			unica = true;
		} 
		cout << qtdPalavras << " " << vec.size() << endl;

	} else if(tipoObjeto == "myset"){
		MySet<string> set;
		while(cin>>palavra){
			qtdPalavras++;
			if (set.end() == set.find(palavra)){
				set.insert(palavra);
			}
		} 
		cout << qtdPalavras << " " << set.size() << endl;

	}
	
}
