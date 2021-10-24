#include <iostream>
#include "MySet.h"

using namespace std;

void procura(MySet<int> &s, int elem) {
	cout << "Procurando " << elem << " : " << (s.find(elem)!=s.end()) << endl;
}

void insere(MySet<int> &s, int elem) {
	cout << "Inserindo " << elem << " : " << (s.insert(elem).second) << endl;
}


int main() {
	MySet<int> s;
	insere(s,1);
	insere(s,2);
	insere(s,10);
	insere(s,10); //repetidos..
	insere(s,10); //repetidos..
	insere(s,1);

	s.imprimeBFS();
	cout << endl;

	//qual sera o formato dessa arvore?
	//desenhe-a!
	MySet<char> s2;
	s2.insert('k');
	s2.insert('d');
	s2.insert('s');
	s2.insert('a');
	s2.insert('m');
	s2.insert('w');
	s2.insert('b');
	s2.insert('z');
	s2.insert('t');
	s2.insert('r');
	s2.insert('c');

	cout << "DFS in ordem: " << endl;
	s2.imprimeDFS_in();
	cout << endl;

	cout << "Usando iteradores: " << endl;	
	for(MySet<char>::iterator it = s2.begin();it!=s2.end();it++) {
		cout << *it << " ";
	} cout << endl;

	cout << "De tras para a frente..." << endl;
	//por enquanto nao suportamos decremento de end()
	MySet<char>::iterator it = s2.begin();
	for(;*it!='z';it++);
	//coincidenetemente, ao decrementar um iterador para o ultimo elemento
	//chegamos a um iterador para end() (pode ser que seja melhor mudar isso...)
	for(;it!=s2.end();it--) cout << *it << " ";
	cout << endl;

	cout << "Usando range-based for: " << endl;
	for(auto x:s2) {cout << x << " ";
	} cout << endl;
}

/*
Saida esperada:
Inserindo 1 : 1
Inserindo 2 : 1
Inserindo 10 : 1
Inserindo 10 : 0
Inserindo 10 : 0
Inserindo 1 : 0
1 2 10 
DFS in ordem: 
a b c d k m r s t w z 
Usando iteradores: 
a b c d k m r s t w z 
De tras para a frente...
z w t s r m k d c b a 
Usando range-based for: 
a b c d k m r s t w z
*/