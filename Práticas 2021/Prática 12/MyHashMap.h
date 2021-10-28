#ifndef MY_HASH_MAP_H
#define MY_HASH_MAP_H


//tamanho (numero de linhas) da tabela hash... (numero pequeno para facilitar a visualizacao)
//esse e' o tamanho padrao das nossas tabelas (idealmente deveriamos usar valores maiores do que esse)
const int DEFAULT_TABLE_SIZE = 10;

#include <algorithm> //contem a classe pair...


#include "MyList2NewIterator.h"
#include "MyVecNewIterator.h"

template <class KEY, class VALUE, class HASH>
class MyHashMap {
public:
	MyHashMap();
	void set(const KEY &k,  const VALUE &v);

	//algumas das funcoes abaixo (count, getValue, imprime) deveriam ser const.... mas como nossa classe MyList2 nao possui iteradores constantes (isso foi feito por simplicidade)--> nao podemos fazer isso....
	//
	int count(const KEY &k) ; //quantos elementos com a chave dada a tabela possui? (0 se nenhum, 1 se contem o elemento -- nao armazenamos elementos duplicados)
	int size() const  { return numElems; }; //quantos elementos ha no nosso hashmap?
	VALUE &getValue(const KEY &k) ; //retorna o valor associado a chave k...
	void imprime() ; //usada para visualizar o conteudo da tabela...
	void imprimeTamanhoBaldes() const; //imprime o numero de elementos em cada balde do hashmap
	void reHash(int);

private:
	MyVec<MyList2<std::pair<KEY,VALUE> > > table;
	int numElems;
	HASH funcaoHash; //functor representando a funcao hash que vamos usar na classe...

	int tableSize;
};


#include <iostream>



template <class KEY, class VALUE, class HASH>
void MyHashMap<KEY,VALUE,HASH>::imprimeTamanhoBaldes() const  {
	std::cout << "Size: " << size() << std::endl;
	for(int i=0;i<tableSize;i++) {
		std::cout << "Bucket " << i << " : " << table[i].size() << "\n";
	}
}

template <class KEY, class VALUE, class HASH>
void MyHashMap<KEY,VALUE,HASH>::imprime()  {
	std::cout << "Size: " << size() << std::endl;
	for(int i=0;i<tableSize;i++) {
		std::cout << "Bucket " << i << " : ";
		for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[i].begin();it!=table[i].end();it++) {
			std::cout <<  "(" << (*it).first << "," << (*it).second << ");";
		}
		std::cout << "\n";
	}
}

template <class KEY, class VALUE, class HASH>
MyHashMap<KEY,VALUE,HASH>::MyHashMap() {
	numElems = 0;
	tableSize = DEFAULT_TABLE_SIZE;
	table.resize(tableSize);
}



template <class KEY, class VALUE, class HASH>
void MyHashMap<KEY,VALUE,HASH>::set(const  KEY &k, const VALUE &v) {
	//Etapa 2: implemente esta funcao.
	//primeiramente devemos calcular o hash da chave e, com isso, determinar em qual linha da tabela a chave estara (lembre-se de usar a operacao resto de divisao)
	//entao, veja se a chave ja se encontra em tal linha.
	//se ja se encontrar: atualize o valor associado a chave com o valor novo
	//se nao se encontrar: adicione a chave (par: chave, valor) a linha em questao.
	int pos = funcaoHash(k)%tableSize;
	for(typename MyList2<std::pair<KEY,VALUE>>::iterator it = table[pos].begin(); it!=table[pos].end(); it++){
		if((*it).first == k){
			(*it).second = v;
			return;
		}
	}
	table[pos].push_back(std::pair<KEY,VALUE> (k,v));
	numElems++;

}


template <class KEY, class VALUE, class HASH>
int MyHashMap<KEY,VALUE,HASH>::count(const KEY &k) {
	int hash = funcaoHash(k)%tableSize; //chame a funcao hash (na verdade functor) para calcular o hash da chave
	for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[hash].begin();it!=table[hash].end();it++) { //procure pela chave no balde adequado da tabela...
		if((*it).first == k) { //encontramos a chave?
			return 1;
		}
	}
	//se nao retornamos --> a chave nao se encontra na tabela
	return 0;
}

template <class KEY, class VALUE, class HASH>
VALUE &MyHashMap<KEY,VALUE,HASH>::getValue(const KEY &k)  {
	int hash = funcaoHash(k)%tableSize; //chame a funcao hash (na verdade functor) para calcular o hash da chave
	for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[hash].begin();it!=table[hash].end();it++) { //procure pela chave no balde adequado da tabela...
		if((*it).first == k) { //encontramos a chave?
			return (*it).second; //retorna o valor...
		}
	}
	//se nao retornamos --> a chave nao se encontra na tabela
	//isso e' um erro de execucao.
	//o usuario da classe deveria testar antes se a chave se encontra na tabela
	//uma solucao melhor consiste em retornar um iterador (nesse caso, se a chave nao se encontrar retornariamos um iterador para end())
	//mas isso foge do escopo desta aula... (onde estamos focando em uma implementacao simples)
}

template <class KEY, class VALUE, class HASH>
void MyHashMap<KEY,VALUE,HASH>::reHash(int newSize){
	tableSize = newSize;
	MyVec<MyList2<std::pair<KEY,VALUE>>> new_table;
	new_table.resize(newSize);
	for(int i = 0; i < table.size(); i++){
		for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[i].begin();it!=table[i].end();it++) { //procure pela chave no balde adequado da tabela...
			int new_hash = funcaoHash((*it).first)%tableSize;
			new_table[new_hash].push_back(*it);
		}
	}
	table=new_table;
}
#endif