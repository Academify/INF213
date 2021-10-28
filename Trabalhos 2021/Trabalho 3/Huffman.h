#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include "MyPriorityQueue.h"
#include "MySet.h"


class HuffmanTree{
	public:
		//Inicialização
	    HuffmanTree(int[256]);//Construtor
		~HuffmanTree();

        void comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const; //Função que realiza a compressão
        void descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const; //Função que realiza a descompressão
	
		MyPriorityQueue<MySet<int>> pq; // Fila de prioridade usada para ordenar as subárvores que geram a Huffman Tree

	private:
		int * frequencias; //Vetor que tem todas as frequências de todos os caracteres.
};

#endif