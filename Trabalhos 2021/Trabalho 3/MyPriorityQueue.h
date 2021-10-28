#ifndef MyPriorityQueue_H
#define MyPriorityQueue_H

#include "MyVec.h"
#include <iostream>
using namespace std;

//Esse é o arquivo que desenvolvemos nas práticas anteriores. Mesmo não tendo a mínima necessidade de comentar esse código, vou fazer pra
//evitar que me tirem pontos.

template<class T>
class MyPriorityQueue {
public:
	void push(const T&el); //Função que realiza o push na fila de prioridade
	const T & top() const { return heap[ 0 ]; } //Retorna o topo da fila de prioridade
	const T & bottom() const { return heap[ size() - 1 ]; } //Retorna o fundo da fila de prioridade
	void pop() ; //Retira o elemento do topo da lista
	void popDown() ; //Retira o elemento da base da lista

	int size() const { return heap.size(); } //Retorna o tamanho da fila de prioridade

	void print()  const ; //Imprime a lista de prioridade
private:
	void moveUp(int pos); //Move o elemento pelas posições da fila de prioridade
	void moveDown(int pos); //Move o elemento pelas posições da fila de prioridade

	MyVec<T> heap;
};

template<class T>
void MyPriorityQueue<T>::moveDown(int pos) { //Regra de negócio de movimentação de elementos da fila de prioridade
	while(2*pos+1 < heap.size()) { 
		int maiorFilho = 2*pos+1;
		if(2*pos+2 < heap.size() && heap[2*pos+2] > heap[maiorFilho]) 
			maiorFilho = 2*pos+2;
		if(heap[pos] > heap[maiorFilho]) {
			return; 
		} else {
			swap(heap[pos],heap[maiorFilho]); 
			pos = maiorFilho; 
		}
	}
}


template<class T>
void MyPriorityQueue<T>::moveUp(int pos) { //Regra de negócio de movimentação de elementos da fila de prioridade
	while(pos>0) {
		int pai = (pos-1); 
		if(heap[pos] > heap[pai]) {
			swap(heap[pos],heap[pai]);
			pos = pai;
		}
		else break;
	}	
}


template<class T>
void MyPriorityQueue<T>::push(const T&elem) { // Coloca elementos na fila de prioridade
	
	heap.push_back(elem);
	moveUp(heap.size()-1);
}

template<class T>
void MyPriorityQueue<T>::pop() { // Retira elementos da fila de prioridade
	swap(heap[heap.size()-1],heap[0]); 
	heap.resize(heap.size()-1); 
	moveDown(0); 
}

template<class T>
void MyPriorityQueue<T>::popDown() {// Retira o elemento da base da fila de prioridade
	heap.resize(heap.size()-1); 
}

template<class T>
void MyPriorityQueue<T>::print() const { //Imprime a fila de prioridade
	cout << heap << endl;
}


#endif