#include <iostream>
#include "Tetris.h"

using namespace std;

//Quando existe alocação dinâmica, é necessário ter 3 coisas:
/* 
    1 - Construtor de cópia
    2 - Operador de atribuição
    3 - Destrutor
 */ 

//Construtor com um argumento: Número de colunas do jogo
Tetris::Tetris(const int colunas){
    this->colunas = colunas;
    this->alturas = new int [colunas];
    this->jogo = new char *[this->colunas];

    for(int i=0; i<this->colunas; i++){
        this->jogo[i] = new char[0];
        this->alturas[i] = 0;
    }

}

//Construtor de cópia
Tetris::Tetris(const Tetris &other) { 
    colunas = other.colunas;
    alturas = new int [other.colunas];
    jogo = new char *[other.colunas];

    for(int i=0; i<other.colunas; i++){
        jogo[i] = new char[0];
        alturas[i] = 0;
    }

    *this = other;
}

//Operador de atribuição -- (Sem ele dá ruim no subimmity)
Tetris & Tetris::operator=(const Tetris &other) {
	if(this==&other) return *this;
    
    for(int i=0; i < colunas; i++){
        delete [] jogo[i];
    }
    delete [] jogo;
    delete [] alturas;

    this->colunas = other.colunas;
    this->alturas = new int [other.colunas];
    this->jogo = new char *[other.colunas];

    for(int i = 0; i < other.colunas; i++) {
        alturas[i] = other.alturas[i];
        jogo[i] = new char[other.alturas[i]];
        for(int j = 0; j < other.alturas[i]; j++){
            jogo[i][j] = other.jogo[i][j];
        }
    } 

    return *this;
}

//Destrutor: 
/* 
    Primeiro desaloca coluna por coluna do jogo
    Depois desaloca o vetor de vetores do jogo
    Depois desaloca o vetor de alturas
 */
Tetris::~Tetris(){
    for(int i=0; i < colunas; i++){
        delete [] jogo[i];
    }
    delete [] jogo;
    delete [] alturas;
}

//Getters e setters --------------------------------------------------------
const char Tetris::get(const int coluna, const int linha)const{

    if(coluna < colunas && alturas[coluna] > linha){
        return jogo[coluna][linha];
    }
    return ' ';
}

const int Tetris::getNumColunas()const{
    return this->colunas;
}

const int Tetris::getAltura(const int coluna)const{
   return alturas[coluna];
}

const int Tetris::getAltura()const{
    int altMaxima = 0;
    for (int i = 0; i < colunas; i++){
        if(alturas[i] >= altMaxima){
            altMaxima = alturas[i];
        }
    }
    return altMaxima;
    
}

void Tetris::setPixel(const int coluna, const int linha, const char peca){
    if (linha < alturas[coluna])
        jogo[coluna][linha] = peca;
    else{
        char * aux = new char [linha+1];
        for (int i = 0; i<linha; i++){
            if (i < alturas[coluna]) 
                aux[i] = jogo[coluna][i];
            else 
                aux[i] = ' ';
        }
        aux[linha] = peca;
        delete [] jogo[coluna];
        jogo[coluna] = new char[linha+1];
        for(int i = 0; i<linha+1; i++){
            jogo[coluna][i] = aux[i];
        }
        alturas[coluna] = linha+1;
        delete [] aux;
    } 
        
}
//----------------------------------------------------------------------------

// Funções de desalocação e remoção
void Tetris::removeColuna(const int coluna){

    if(coluna >= 0 && coluna < colunas){

        //reorganização das colunas para sobrescrever a coluna que deve ser excluída,
        //passando todas as posteriores para a posição anterior a elas
        for(int j = coluna; j < colunas - 1; j++){
            char * colunaAux = new char[alturas[j + 1]];
            for(int i = 0; i < alturas[j + 1]; i++){
                colunaAux[i] = jogo[j + 1][i];
            }
            delete [] jogo[j];
            jogo[j] = new char [alturas[j + 1]];
            for(int i = 0; i < alturas[j + 1]; i++){
                jogo[j][i] = colunaAux[i];
            }
            delete [] colunaAux;
        }

        //deleção da coluna no final da matriz
        delete [] jogo[colunas - 1];
        colunas--;

        //atualização do vetor de alturas de forma dinâmica
        int * aux = new int [colunas];
        for (int i = 0; i<colunas; i++){
            if (i < coluna) 
                aux[i] = alturas[i];
            else 
                aux[i] = alturas[i + 1];
        }
        delete [] alturas;
        alturas = new int[colunas];
        for(int i = 0; i < colunas; i++){
            alturas[i] = aux[i];
        }
        delete [] aux;
    }   
        
}


//Função que vai desalocar os espaços vazios dentro da coluna
void Tetris::desalocaLacunas(const int coluna){
    int alturaInicial = getAltura(coluna);
    bool estaAlocada = false;
    for (int i = 0; i < alturaInicial; i++){
        if (get(coluna, i) != ' '){
            estaAlocada = true;
        }
    }
    if (!estaAlocada){
        delete [] jogo[coluna];
        jogo[coluna] = new char[0];
        alturas[coluna] = 0;
    }
}

void Tetris::removeLinha(const int linha){
    for(int i = 0; i < getNumColunas(); i++){
        removeElementoDeColuna(i, linha);
        alturas[i]--;
        desalocaLacunas(i);
    }
}

void Tetris::removeElementoDeColuna(int coluna, int linha){
    int tamanho = getAltura(coluna);
    char * aux = new char [tamanho-1];
    for (int j = 0; j < linha; j++){
        aux[j] = jogo[coluna][j];
    }
    for (int j = linha; j<tamanho-1;j++){
        aux[j] = jogo[coluna][j+1];
    }
    delete [] jogo[coluna];
    jogo[coluna] = new char[tamanho-1];
    for (int i = 0; i<tamanho-1; i++){
        setPixel(coluna, i, aux[i]);
    }
    delete [] aux;
}

void Tetris::removeLinhasCompletas(){
    bool linhaCompleta;
    int linha = 0;
    int alturaMatriz = getAltura();
    int i = 0;
    while(i < alturaMatriz){
        linhaCompleta = true;
        for(int j = 0; j < colunas; j++){
            if(get(j, i) == ' '){
                linhaCompleta = false;
                break;
            }
            linha = i;
        }
        if(linhaCompleta){
            removeLinha(linha);
            alturaMatriz--;
            i = 0;
        } else {
            i++;
        }
    }
}

//Funções de adição de forma ao jogo

bool Tetris::adicionaForma(const int coluna, const int linha, const char peca, const int rotacao){
    if (coluna < 0) 
        return false;

    switch (peca)
    {
    case 'I':
        return adicionaFormaI(linha, coluna, rotacao);
    
    case 'O':
        return adicionaFormaO(linha, coluna, rotacao);

    case 'J':
        return adicionaFormaJ(linha, coluna, rotacao);

    case 'L':
        return adicionaFormaL(linha, coluna, rotacao);

    case 'T':
        return adicionaFormaT(linha, coluna, rotacao);

    case 'Z':
        return adicionaFormaZ(linha, coluna, rotacao);

    case 'S':
        return adicionaFormaS(linha, coluna, rotacao);
    default:
        break;
    }
    return false;
}

bool Tetris::adicionaFormaI(const int linha, const int coluna, const int rotacao){
    if(rotacao == 0 || rotacao == 180){

        if(linha - 3 < 0 || coluna > getNumColunas() - 1){
            return false;
        }

        for(int i = linha; i > linha - 4; i--){
            if(get(coluna, i) != ' '){
                return false;
            }
        }
  
        for(int i = linha; i > linha - 4; i--){
            setPixel(coluna, i, 'I');
        }
        return true;

    }else if(rotacao == 90 || rotacao == 270){

        if(linha < 0 || coluna + 3 > getNumColunas() - 1){
            return false;
        }

        for(int i = coluna; i < coluna + 4; i++){
            if(get(i, linha) != ' '){
                return false;
            }
        }

        for(int i = coluna; i < coluna + 4; i++){
            setPixel(i, linha, 'I');
        }
        
        return true;
    }
    return false;
}

bool Tetris::adicionaFormaO(const int linha, const int coluna, const int rotacao){

    if(linha - 1 < 0 || coluna + 1 > getNumColunas() - 1){
        return false;
    }

    for(int i = linha; i > linha - 2; i--){
        for(int j = coluna; j < coluna + 2; j++){
            if(get(j, i) != ' '){
                return false;
            }
        }
    }
    
    for(int i = linha; i > linha - 2; i--){
        for(int j = coluna; j < coluna + 2; j++){
            setPixel(j, i, 'O');
        }
    }

    return true;
}

bool Tetris::adicionaFormaJ(const int linha, const int coluna, const int rotacao){
    if(rotacao == 0){

        //Verifica se os pixels estão dentro dos limites do jogo

        if(linha - 1 < 0 || coluna + 3 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna; i < coluna + 4; i++){
            if(get(i, linha) != ' '){
                return false;
            }
        }
        if(get(coluna + 3, linha - 1) != ' '){
            return false;
        }

        //Coloca a peça
        for(int i = coluna; i < coluna + 4; i++){
            setPixel(i, linha, 'J');
        }
        setPixel(coluna + 3, linha - 1, 'J');

        
        return true;
    }else if(rotacao == 90){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 3 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 4; i--){
            if(get(coluna + 1, i) != ' '){
                return false;
            }
        }
        if(get(coluna, linha - 3) != ' '){
            return false;
        }


        //Coloca a peça
        for(int i = linha; i > linha - 4; i--){
            setPixel(coluna + 1, i, 'J');
        }
        setPixel(coluna, linha - 3, 'J');

        
        return true;
    }else if(rotacao == 180){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 1 < 0 || coluna + 3 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna; i < coluna + 4; i++){
            if(get(i, linha - 1) != ' '){
                return false;
            }
        }
        if(get(coluna, linha) != ' '){
            return false;
        }

        for(int i = coluna; i < coluna + 4; i++){
            setPixel(i, linha - 1, 'J');
        }
        setPixel(coluna, linha, 'J');
        
        
        return true;
    }else if(rotacao == 270){

        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 3 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 4; i--){
            if(get(coluna, i) != ' '){
                return false;
            }
        }
        if(get(coluna + 1, linha) != ' '){
            return false;
        }

        //Coloca o pixel
        for(int i = linha; i > linha - 4; i--){
            setPixel(coluna, i, 'J');
        }
        setPixel(coluna + 1, linha, 'J');

        
        return true;
    }
    return false;
}

bool Tetris::adicionaFormaL(const int linha, const int coluna, const int rotacao){
    if(rotacao == 0){

        //Verifica se os pixels estão dentro dos limites do jogo

        if(linha - 1 < 0 || coluna + 3 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios

        for(int i = coluna; i < coluna + 4; i++){
            if(get(i, linha) != ' '){
                return false;
            }
        }
        if(get(coluna, linha - 1) != ' '){
            return false;
        }

        //Coloca a peça
        for(int i = coluna; i < coluna + 4; i++){
            setPixel(i, linha, 'L');
        }
        setPixel(coluna, linha - 1, 'L');

        
        return true;
    }else if(rotacao == 90){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 3 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 4; i--){
            if(get(coluna + 1, i) != ' '){
                return false;
            }
        }
        if(get(coluna, linha) != ' '){
            return false;
        }


        //Coloca a peça
        for(int i = linha; i > linha - 4; i--){
            setPixel(coluna + 1, i, 'L');
        }
        setPixel(coluna, linha, 'L');


        return true;
    }else if(rotacao == 180){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 1 < 0 || coluna + 3 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna; i < coluna + 4; i++){
            if(get(i, linha - 1) != ' '){
                return false;
            }
        }
        if(get(coluna + 3, linha) != ' '){
            return false;
        }

        for(int i = coluna; i < coluna + 4; i++){
            setPixel(i, linha - 1, 'L');
        }
        setPixel(coluna + 3, linha, 'L');
        
        
        return true;
    }else if(rotacao == 270){

        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 3 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 4; i--){
            if(get(coluna, i) != ' '){
                return false;
            }
        }
        if(get(coluna + 1, linha - 3) != ' '){
            return false;
        }

        //Coloca o pixel
        for(int i = linha; i > linha - 4; i--){
            setPixel(coluna, i, 'L');
        }
        setPixel(coluna + 1, linha - 3, 'L');

        
        return true;
    }
    return false;
}

bool Tetris::adicionaFormaT(const int linha, const int coluna, const int rotacao){


    if(rotacao == 0){

        //Verifica se os pixels estão dentro dos limites do jogo

        if(linha - 1 < 0 || coluna + 2 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna; i < coluna + 3; i++){
            if(get(i, linha) != ' '){
                return false;
            }
        }
        if(get(coluna + 1, linha - 1) != ' '){
            return false;
        }

        //Coloca a peça
        for(int i = coluna; i < coluna + 3; i++){
            setPixel(i, linha, 'T');
        }
        setPixel(coluna + 1, linha - 1, 'T');

        
        return true;
    }else if(rotacao == 90){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 2 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 3; i--){
            if(get(coluna + 1, i) != ' '){
                return false;
            }
        }
        if(get(coluna, linha - 1) != ' '){
            return false;
        }


        //Coloca a peça
        for(int i = linha; i > linha - 3; i--){
            setPixel(coluna + 1, i, 'T');
        }
        setPixel(coluna, linha - 1, 'T');


        return true;

    }else if(rotacao == 180){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 1 < 0 || coluna + 2 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna; i < coluna + 3; i++){
            if(get(i, linha - 1) != ' '){
                return false;
            }
        }
        if(get(coluna + 1, linha) != ' '){
            return false;
        }

        for(int i = coluna; i < coluna + 3; i++){
            setPixel(i, linha - 1, 'T');
        }
        setPixel(coluna + 1, linha, 'T');
        
        
        return true;
    }else if(rotacao == 270){

        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 2 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 3; i--){
            if(get(coluna, i) != ' '){
                return false;
            }
        }
        if(get(coluna + 1, linha - 1) != ' '){
            return false;
        }

        //Coloca o pixel
        for(int i = linha; i > linha - 3; i--){
            setPixel(coluna, i, 'T');
        }
        setPixel(coluna + 1, linha - 1, 'T');

        
        return true;
    }
    return false;
}

bool Tetris::adicionaFormaZ(const int linha, const int coluna, const int rotacao){
    if(rotacao == 0 || rotacao == 180){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 1 < 0 || coluna + 2 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna; i < coluna + 2; i++){
            if(get(i, linha) != ' '){
                return false;
            }
        }
        for(int i = coluna + 1; i < coluna + 3; i++){
            if(get(i, linha - 1) != ' '){
                return false;
            }
        }
        

        //Coloca a peça
        for(int i = coluna; i < coluna + 2; i++){
            setPixel(i, linha, 'Z');
        }
        for(int i = coluna + 1; i < coluna + 3; i++){
            setPixel(i, linha - 1, 'Z');
        }
        

        
        return true;
        
    }else if(rotacao == 90 || rotacao == 270){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 2 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha - 1; i > linha - 3; i--){
            if(get(coluna, i) != ' '){
                return false;
            }
        }
        for(int i = linha; i > linha - 2; i--){
            if(get(coluna + 1, i) != ' '){
                return false;
            }
        }


        //Coloca a peça
        for(int i = linha - 1; i > linha - 3; i--){
            setPixel(coluna, i, 'Z');
        }
        for(int i = linha; i > linha - 2; i--){
            setPixel(coluna + 1, i, 'Z');
        }
        

        
        return true;
    }
    return false;
}

bool Tetris::adicionaFormaS(const int linha, const int coluna, const int rotacao){

    if(rotacao == 0 || rotacao == 180){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 1 < 0 || coluna + 2 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = coluna + 1; i < coluna + 3; i++){
            if(get(i, linha) != ' '){
                return false;
            }
        }
        for(int i = coluna; i < coluna + 2; i++){
            if(get(i, linha - 1) != ' '){
                return false;
            }
        }
        

        //Coloca a peça
        for(int i = coluna + 1; i < coluna + 3; i++){
            setPixel(i, linha, 'S');
        }
        for(int i = coluna; i < coluna + 2; i++){
            setPixel(i, linha - 1, 'S');
        }
        

       
        return true;
        
    }else if(rotacao == 90 || rotacao == 270){
        //Verifica se os pixels estão dentro dos limites do jogo
        if(linha - 2 < 0 || coluna + 1 > getNumColunas() - 1){
            return false;
        }

        //Verifica se os pixels estão vazios
        for(int i = linha; i > linha - 2; i--){
            if(get(coluna, i) != ' '){
                return false;
            }
        }
        for(int i = linha - 1; i > linha - 3; i--){
            if(get(coluna + 1, i) != ' '){
                return false;
            }
        }


        //Coloca a peça
        for(int i = linha; i > linha - 2; i--){
            setPixel(coluna, i, 'S');
        }
        for(int i = linha - 1; i > linha - 3; i--){
            setPixel(coluna + 1, i, 'S');
        }
        

       
        return true;
    }
    return false;
}