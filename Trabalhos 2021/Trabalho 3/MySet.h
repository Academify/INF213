#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H
#include <ostream>

#include <algorithm> //classe pair esta aqui...
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_, const char simbolo_) : elem(elem_),left(NULL), right(NULL), simbolo(simbolo_) {}
		Node<T> *left, *right;
		T elem;
		char simbolo;
		Node<T> *parent; //agora cada nodo armazena seu pai
};

//-------------------------------------------------------------------------------------------------------------------- (Clean Code mandou abraço)

template  <class T>
class MySet {
public:
	typedef MySetIterator<T> iterator;

	int size() const;
	MySet() : size_(0), root(NULL) {}

	pair<iterator,bool> insert(const T &elem_, const char simbolo_);

	iterator end() {return iterator(NULL);}; 
	iterator begin() ;
	MySet &combine(MySet &a, MySet &b) ;

	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	bool operator>(MySet &other);
	bool operator<(MySet &other);
	~MySet();

	void rastreiaCodigos();
	string buscaCodigo(const unsigned char simbolo) const;
	void rastreiaElementos(const MyVec<bool> & in, MyVec<unsigned char> & out) const;

private:
	Node<T> *root;
	int size_;
	string codigosBinarios[256];


	//funcoes auxiliares...
	pair<iterator,bool> insert(const T&elem, const char simbolo, Node<T> *&root,Node<T> *parent); 
	iterator find(const char elem, const int freq, Node<T> *root);


	void deleteNodes(Node<T> *root);
	Node<T> * copyNodes(const Node<T> *root, Node<T> *parent) const;

	void rastreiaCodigos(Node <T> * root);

};


template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(Node<T> *ptr_): ptr(ptr_) { }
	pair<T,char> operator*() {return make_pair(ptr->elem, ptr->simbolo);}
	Node<T> * operator&() {return ptr;}

	bool operator==(const MySetIterator &other) const {return ptr==other.ptr;}
	bool operator!=(const MySetIterator &other) const {return ptr!=other.ptr;}

	MySetIterator operator++();
	MySetIterator operator++(int);

	MySetIterator operator--();
	MySetIterator operator--(int);
private:
	Node<T> *ptr;
};

// ---------------------------- OPERADORES ---------------------------
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++() {
	if(ptr->right) { 
		ptr = ptr->right;
		while(ptr->left) ptr=ptr->left;
	} else { 
		while(ptr->parent && ptr->parent->right==ptr) ptr = ptr->parent;  
		ptr = ptr->parent;		
	}
	return *this;
}

template<class T>
MySetIterator<T>  MySetIterator<T>::operator--() {
	if(ptr->left) { 
		ptr = ptr->left;
		while(ptr->right) ptr=ptr->right;
	} else { 
		while(ptr->parent && ptr->parent->left==ptr) ptr = ptr->parent;  
		ptr = ptr->parent;		
	}
	return *this;
}

template<class T>
MySetIterator<T>  MySetIterator<T>::operator++(int) {
	MySetIterator<T> old(*this);
	++(*this);
	return old;
}

template<class T>
MySetIterator<T>  MySetIterator<T>::operator--(int) {
	MySetIterator<T> old(*this);
	--(*this);
	return old;
}

// -------------------------------------------------------

// ---------------------------- Funções de acesso a elementos chave ---------------------------
template  <class T>
typename MySet<T>::iterator MySet<T>::begin() {
	if(!root) return end();
	return iterator(root);
}


template  <class T>
MySet<T>::MySet(const MySet &other) { //Construtor
	size_=0;
	root= NULL;
	*this = other;
}

// Função que pega os dois menores subnodos e forma um novo nodo com a soma das frequâncias
template  <class T>
MySet<T> & MySet<T>::combine(MySet<T> &a, MySet<T> &b){
	int soma = a.root->elem + b.root->elem;
	this->root = new Node<T>(soma, '\0');
	this->root->right = copyNodes(a.root, root->right);
	this->root->left = copyNodes(b.root, root->left);
	size_++;
	return *this;
}


template  <class T>
void MySet<T>::deleteNodes(Node<T> *root) { //Função que deleta nodos da árvore
	if(!root) return;
	deleteNodes(root->left);
	deleteNodes(root->right);
	delete root;
}

template  <class T>
MySet<T>::~MySet() { //Destrutor da árvore
	deleteNodes(root);
}


template  <class T>
Node<T> * MySet<T>::copyNodes(const Node<T> *root,  Node<T> *parent) const { //Função que copia os nodos da árvore
	if(root==NULL) { 
		return NULL;
	}
	Node<T> *  ans = new Node<T>(root->elem, root->simbolo);
	ans->parent = parent;
	ans->left = copyNodes(root->left,ans);
	ans->right = copyNodes(root->right,ans);
	

	return ans;
}

template  <class T>
MySet<T> & MySet<T>::operator=(const MySet &other) { //Sobrecarga do operador de atribuição
	if(this==&other) return *this; 
	deleteNodes(root);
	root = copyNodes(other.root,NULL);
	for (int i = 0; i<256; i++){
		codigosBinarios[i] = other.codigosBinarios[i];
	}
	size_ = other.size_;
	return *this;
}

template  <class T>
bool MySet<T>::operator>(MySet &other){ //Sobrecarga do operador >
	return root->elem > other.root->elem;
}

template  <class T>
bool MySet<T>::operator<(MySet &other){ //Sobrecarga do operador <
	return root->elem < other.root->elem;
}

template  <class T>
int MySet<T>::size() const { //Retorna o tamanho da árvore
	return size_; 
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, const char simbolo, Node<T> * &ptr, Node<T> *parent) { //Insere o novo nodo
	if(!ptr) {
		ptr = new Node<T>(elem, simbolo);
		ptr->parent = parent;
		size_++;
		return make_pair(iterator(ptr),true);
	} else {
		if (ptr->simbolo == simbolo) return make_pair(iterator(ptr),false);
		else if (ptr->elem > elem) return insert(elem, simbolo, ptr->left, ptr);
		else return insert(elem, simbolo, ptr->right, ptr);
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, const char simbolo) { 
	return insert(elem, simbolo, root, NULL);
}

template  <class T>
string MySet<T>::buscaCodigo(const unsigned char simbolo) const { //Retorna o caminho para o símbolo requisitado
	return codigosBinarios[simbolo];
}

//Função que rastreia a árvore e "monta" o código de cada caractere.
template  <class T>
void MySet<T>::rastreiaCodigos(Node<T> * ptr) {
	string codigo; //código
	unsigned char caractere; //caractere
	if (!(ptr->right) && !(ptr->left)){ //se não tiver filhos, isto é, se for folha, ou ainda, se o node representar um caractere
		codigo = "";
		caractere = ptr->simbolo; // Coleta o caractere
		while(ptr->parent != NULL){ // Enquanto não chegar ao fim da árvore
			if (ptr == ptr->parent->right) //Se o caminho for a direita, o caminho recebe 1
				codigo = "1" + codigo;
			else if (ptr == ptr->parent->left) //Se for a esquerda, recebe 0
				codigo = "0" + codigo;
			ptr = ptr->parent;
		}
		this->codigosBinarios[caractere] = codigo; //Vetor de códigos binários é atualizados

	} else{
		rastreiaCodigos(ptr->right); // Se tem filhos, continua rastreando
		rastreiaCodigos(ptr->left);	 
	}
}

template  <class T>
void MySet<T>::rastreiaCodigos() {
	//se só houver um nodo na árvore (a raiz é uma folha), não há necessidade de rastrear outros códigos
	if(!(root->left) && !root->right){
		this->codigosBinarios[root->simbolo] = '0';
		return;
	}
	rastreiaCodigos(this->root);
}

template  <class T>
void MySet<T>::rastreiaElementos(const MyVec<bool> & in, MyVec<unsigned char> & out) const { 
	//se só houver um nodo na árvore, não há necessidade de percorrer todo o vetor, pois esse nodo é a raiz
	if (in.size()==1){
		out.push_back(root->simbolo);
		return;
	}

	Node<T> * ptr = root;

	for (int i = 0; i<in.size(); i++){ //Fas o rastreamento. Esquerda - 0; Direita - 1
		
		if (in[i]) {
			ptr = ptr->right;
		}
		else{
			ptr = ptr->left;
		} 

		if (!(ptr->left) && !(ptr->right)){ //Se não tiver filho, já chegou no nodo do elemento
			out.push_back(ptr->simbolo);
			ptr = root;
		}

	}
	
}

#endif