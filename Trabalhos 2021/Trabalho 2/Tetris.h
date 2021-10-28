#ifndef TETRIS_H
#define TETRIS_H

using namespace std;

class Tetris{
    private:
        int colunas;  
        int *alturas;

        //Funções de adicao de peça
        bool adicionaFormaI(const int, const int, const int);
        bool adicionaFormaO(const int, const int, const int);
        bool adicionaFormaJ(const int, const int, const int);
        bool adicionaFormaL(const int, const int, const int);
        bool adicionaFormaT(const int, const int, const int);
        bool adicionaFormaZ(const int, const int, const int);
        bool adicionaFormaS(const int, const int, const int);

    public:
        char **jogo;
        //Construtor
        Tetris(const int);

        //Construtor de cópia - copia recurso
        Tetris(const Tetris &other);

        //Operador de atribuição
        Tetris & operator=(const Tetris &);

        //Destrutor
        ~Tetris();

        //Recebe linha e coluna e retorna o valor do estado dessa unidade.
        const char get(const int, const int)const;

        //Adiciona um pixel ao jogo, nas posições indicadas, 
        //atualizando a altura da coluna selecionada e
        //alocando os espaços em branco abaixo dele (quando necessário)
        void setPixel(const int, const int, const char);

        //Remove a coluna indicada do jogo e reajusta o tabuleiro
        void removeColuna(const int);

        //Busca as linhas completas do jogo e chama a função de remoção para cada uma delas
        void removeLinhasCompletas();

        //Percorre a linha e chama a função de remoção de elemento para cada posição
        //também atualiza altura e chama a função de desalocação de lacunas
        void removeLinha(const int);

        //realoca a coluna, removendo o elemento nas posições indicadas
        void removeElementoDeColuna(const int, const int);

        //Após a remoção de uma linha, desaloca os espaços em branco da coluna
        //caso não haja outro pixel preenchido acima deles
        void desalocaLacunas(const int);


        //Retorna o número de colunas presentes no jogo
        const int getNumColunas()const;

        //Retorna a altura da coluna indicada
        const int getAltura(const int)const; 

        //Retorna a altura máxima do jogo
        const int getAltura()const;

        //Verifica a peca que deve ser adicionada e chama a respectiva função
        bool adicionaForma(const int, const int, const char, const int);
};

#endif