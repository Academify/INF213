#include "Huffman.h"

using namespace std;

//Construtor
HuffmanTree::HuffmanTree(int freqs[256]){
    //Percorre o vetor de frquências e cria subarvores que formarão a árvore de Huffman
    for (int i = 0; i<256; i++){
        if (freqs[i] > 0){
            unsigned char simbolo = (int)i;
            MySet<int> subarvore; //Cria a subárvore
            subarvore.insert(freqs[i], simbolo); //Insere o caractere e a frequência
            pq.push(subarvore); //Adiciona a árvore na Priority Queue
        }
    } 

    // Enquanto existir mais do que 1 árvore na fila de prioridade, faz a mescla das "menores" árvores
    //Repete isso até obter a árvore de Huffman
    while (pq.size()>1){  
        MySet<int>  a, b, t;
        a = MySet<int> (pq.bottom());
        pq.popDown();
        b = MySet<int> (pq.bottom());
        pq.popDown();
        t = MySet<int> ();
        t.combine(a, b);

        pq.push(t);
    }   

    frequencias = freqs;
}

//Destrutor
HuffmanTree::~HuffmanTree(){}

/*
//Construtor de cópias
HuffmanTree::HuffmanTree(const HuffmanTree &otherHuffmanTree){
    
    *this = otherHuffmanTree;
}

//Operador de Atribuição
HuffmanTree &HuffmanTree::operator=(const HuffmanTree &otherHuffmanTree){

    if(this==&otherHuffmanTree) return *this;
    
    return *this;
}

 */

//Essa função é chamada quando se deseja comprimir um arquivo
void HuffmanTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const{
    //Pega a árvore de Huffman
    MySet<int> arv = pq.top();

    //Rastreia quais são os códigos dos caracteres na árvore
    arv.rastreiaCodigos();
    
    //convertendo cada letra em código binário
    for (int i = 0; i < in.size(); i++){
        string codigo = arv.buscaCodigo(in[i]);
        for (int j = 0; j<codigo.length(); j++){
            out.push_back(codigo[j]=='1');
        }
    }
}	

void HuffmanTree::descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const{
    //Pega a árvore de Huffman
    MySet<int> arv = pq.top();
    //Faz o caminho contrário da compressão, rastreando os elementos da árvore.
    arv.rastreiaElementos(in, out);    
}