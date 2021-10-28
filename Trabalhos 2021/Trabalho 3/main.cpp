#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <bitset>
#include "Huffman.h"

using namespace std;

//Função que converte Bytes para bits
//Usado no momento da descompressão do arquivo
void conversorBytesParaBits(MyVec<unsigned char> bytesGerados, MyVec<bool> & in){
	string binario; // string que abrigará o código binário
	for (int i = 0; i<bytesGerados.size(); i++){

		//conversão de char para decimal
		int decimal = (int) bytesGerados[i];

		//conversão de decimal para binário		
		bitset<8> bs(decimal);
		binario = bs.to_string();

		//preenchimento do vetor
		for (int j = 0; j<binario.length(); j++){
			in.push_back(binario[j]=='1');
		}
	}
}

unsigned char conversorBitsParaByte(int bitsParaConverter){
	//conversão de binário para decimal
	int byteConvertido = 0, resto, base = 1; 
	
	//Enquanto houver bits para converter
	while(bitsParaConverter > 0){ 
		resto = bitsParaConverter % 10; //Passa para decimal
		bitsParaConverter/=10; 
		byteConvertido+=(base*resto); 
		base*=2; 
	}
	//conversão do decimal para char
	return (unsigned char)byteConvertido;
}

int main(int argc, char *argv[]) {
	//argv[1]: operação ("c" ou "d")
	//argv[2]: arquivo de entrada
	//argv[3]: arquivo de saída

	string acao = argv[1]; //Compressão ou descompressão
	string arqEntrada = argv[2]; //Nome arquivo entrada
	string arqSaida = argv[3]; //Nome arquivo saída
	ifstream arquivoEntrada(arqEntrada); //Abrindo arquivo entrada
	ofstream arquivoSaida(arqSaida); // Abrindo arquivo saída

	string linha; //Auxiliar para linha

	if (acao == "c"){
		//Se for compressão...
		
		MyVec<unsigned char> in;
		MyVec<bool> out;
		int freqs[256] = {0};

		//passagem do arquivo de entrada para o MyVec<char> in
		string conteudo((istreambuf_iterator<char>(arquivoEntrada)),
                       (istreambuf_iterator<char>()));

		for (int i = 0; i<conteudo.length(); i++){
			in.push_back(conteudo[i]);
		}

		//arquivo vazio
		if (in.size() == 0){
			for (int i = 0; i<257; i++){
				//o primeiro zero indica que nenhum caractere foi convertido
				//os outros 256 são o vetor de frequencias
				arquivoSaida << 0 << ";";
			}
			//se o arquivo estiver vazio, não há como criar a árvore, então o programa se encerra
			return 0;
		}

		//preenchimento do vetor de frequências
		for (int i = 0; i<in.size(); i++) 
			freqs[in[i]]++;

		//criação da árvore de Huffman
		HuffmanTree arvore(freqs);

		//compressão do arquivo
		arvore.comprimir(out, in);

		//Guarda a quantidade de bits gerados
		int quantidadeBitsGerados = out.size();

		//completando os dígitos do último byte, quando necessário, com 0
		while (out.size()%8 > 0){
			out.push_back(0);
		}

		//salvando a quantidade de bits gerados no arquivo
		arquivoSaida << quantidadeBitsGerados << ";";                                   

		//salvando o vetor de frequências no arquivo
		for (int i = 0; i<256; i++){
			arquivoSaida << freqs[i] << ";";                                      		
		}
		arquivoSaida << endl;

		string bitsParaConverter = "";
		unsigned char byteGerado;
		
		//convertendo os códigos binários em bytes e salvando no arquivo
		for (int i = 0; i<out.size(); i+=8){
			for (int j = i; j<i+8; j++){
				bitsParaConverter = bitsParaConverter + (out[j] ? "1" : "0");
			}
			byteGerado = conversorBitsParaByte(stoi(bitsParaConverter));
			arquivoSaida << byteGerado;    
			bitsParaConverter = "";
		}
				
	}else if (acao == "d"){
		// Se for descompressão
		MyVec<unsigned char> out;
		MyVec<bool> in;
		int freqs[256] = {0};
  		string conteudo((istreambuf_iterator<char>(arquivoEntrada)), // Lê todo o conteúdo do arquivo
                       (istreambuf_iterator<char>()));
		
		
		if(conteudo[0] == '0'){ //Se o conteúdo for nulo, encerra o programa
			arquivoSaida << "";
			return 0;
		}
		
		int i = 0;
		while(conteudo[i] != '\n'){ // Enquanto o conteúdo for diferente de \n, faz um push do conteúdo da linha recuperada.
			linha.push_back(conteudo[i]);
			i++;
		}

		conteudo = conteudo.substr(i+1, conteudo.length()-i);

		//leitura do vetor de inteiros na primeira linha

		//o primeiro número dentro do vetor de frequencias é a quantidade de dígitos gerados pela conversão
		//antes de serem acrescentados os zeros para completar o último char
		int proximoSeparador = linha.find(';');
		int bitsGerados = stoi(linha.substr(0, proximoSeparador));
		linha.erase(0, proximoSeparador + 1);

		i = 0;
		while (linha.length()) {
			proximoSeparador = linha.find(';');
			freqs[i] = stoi(linha.substr(0, proximoSeparador));
			linha.erase(0, proximoSeparador + 1);
			i++;
		}

		//criação da árvore de Huffman
		HuffmanTree arvore(freqs);

		//passagem do arquivo comprimido para o MyVec de bytes
		MyVec<unsigned char> bytesGerados;

		for (int i = 0; i<conteudo.length(); i++){
			bytesGerados.push_back(conteudo[i]);
		}

		//conversão dos bytes para o MyVec<bool> comprimido
		conversorBytesParaBits(bytesGerados, in);

		//retirando os bits acrescentados para completar o último byte
		while(in.size() > bitsGerados){
			in.resize(in.size()-1);
		}

		//descomprimir o arquivo
		arvore.descomprimir(out, in);
		for (i = 0; i<out.size(); i++)
			arquivoSaida << out[i];
	}
}


