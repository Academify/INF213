#include <iostream>
#include "MySet.h"

using namespace std;


class Aluno {
public: 
	Aluno(const string &nome_, int matricula_): nome(nome_), matricula(matricula_) {}
	const string &getNome() const {return nome;}
	int getMatricula() const {return matricula;}

	bool operator<(const Aluno &other);
	bool operator>(const Aluno &other);

private:
	string nome;
	int matricula;
};

ostream& operator<<(ostream &out,const Aluno &a) {
	out << "(" << a.getNome() << "," << a.getMatricula() << ")";
	return out;
}


template <class T>
void insere(MySet<T> &s, const T& elem) {
	cout << "Inserindo " << elem << " : " << (s.insert(elem).second) << endl;
}

bool Aluno::operator<(const Aluno &other){
	if(this->nome > other.nome) return true;
	else if(this->nome == other.nome) if(this->matricula > other.matricula) return true;
	else return false;
}

bool Aluno::operator>(const Aluno &other){
	if(this->nome < other.nome)return true;
	else if(this->nome == other.nome) if(this->matricula < other.matricula) return true;
	else return false;
}

int main() {
	MySet<Aluno> s;
	insere(s,Aluno("Salles",123));
	insere(s,Aluno("Abc da Silva",3));
	insere(s,Aluno("Joao",1));
	insere(s,Aluno("Maria",2));
	insere(s,Aluno("Capivara",1234));


	s.imprimeBFS();
	cout << endl;

	//qual sera o formato dessa arvore?
	//desenhe-a!
	MySet<Aluno> s2;
	insere(s2,Aluno("Salles",123));
	insere(s2,Aluno("Abc da Silva",3));
	insere(s2,Aluno("Joao",1));
	insere(s2,Aluno("Maria",2));
	insere(s2,Aluno("Capivara",1234));
	insere(s2,Aluno("A",2));
	insere(s2,Aluno("A",3)); //mesmo nome, mas matricula diferente...
	insere(s2,Aluno("B",2));
	insere(s2,Aluno("C",2));
	insere(s2,Aluno("D",2));

	cout << "DFS in ordem: " << endl;
	s2.imprimeDFS_in();
	cout << endl;

	cout << "Usando iteradores: " << endl;	
	for(MySet<Aluno>::iterator it = s2.begin();it!=s2.end();it++) {
		cout << *it << " ";
	} cout << endl;

	cout << "Usando range-based for: " << endl;
	for(auto x:s2) {cout << x << " ";
	} cout << endl;
}

/*Saida esperada:
Inserindo (Salles,123) : 1
Inserindo (Abc da Silva,3) : 1
Inserindo (Joao,1) : 1
Inserindo (Maria,2) : 1
Inserindo (Capivara,1234) : 1
(Salles,123) (Abc da Silva,3) (Joao,1) (Maria,2) (Capivara,1234) 
Inserindo (Salles,123) : 1
Inserindo (Abc da Silva,3) : 1
Inserindo (Joao,1) : 1
Inserindo (Maria,2) : 1
Inserindo (Capivara,1234) : 1
Inserindo (A,2) : 1
Inserindo (A,3) : 1
Inserindo (B,2) : 1
Inserindo (C,2) : 1
Inserindo (D,2) : 1
DFS in ordem: 
(Salles,123) (Maria,2) (Joao,1) (D,2) (Capivara,1234) (C,2) (B,2) (Abc da Silva,3) (A,3) (A,2) 
Usando iteradores: 
(Salles,123) (Maria,2) (Joao,1) (D,2) (Capivara,1234) (C,2) (B,2) (Abc da Silva,3) (A,3) (A,2) 
Usando range-based for: 
(Salles,123) (Maria,2) (Joao,1) (D,2) (Capivara,1234) (C,2) (B,2) (Abc da Silva,3) (A,3) (A,2)
*/