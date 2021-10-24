#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H

#include <algorithm> //classe pair esta aqui...
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_) : elem(elem_),left(NULL), right(NULL) {}
		Node<T> *left, *right;
		T elem;
		Node<T> *parent; //agora cada nodo armazena seu pai
};

template  <class T>
class MySet {
public:
	typedef MySetIterator<T> iterator;

	int size() const;
	MySet() : size_(0), root(NULL) {}

	//funções que faltaram implementar
	MySet(const MySet &other);
	MySet operator=(const MySet &other);
	~MySet();



	pair<iterator,bool> insert(const T&elem); //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	iterator find(const T&elem); //por simplicidade, nao vamos deixar implementar um find constante...

	iterator end() {return iterator(NULL);}; 
	iterator begin() ;


	void imprimeBFS() const;
	void imprimeDFS_pre() const;
	void imprimeDFS_in() const;
	void imprimeDFS_pos() const;

private:
	Node<T> *root;
	int size_;


	//funcoes auxiliares...
	pair<iterator,bool> insert(const T&elem, Node<T> *&root,Node<T> *parent); 
	iterator find(const T&elem, Node<T> *root);

	void destroy(Node<T> *ptr);


	void imprimeDFS_pre(const Node<T> *root) const;
	void imprimeDFS_in(const Node<T> *root) const;
	void imprimeDFS_pos(const Node<T> *root) const;

	Node<T> * copyNodes(Node<T> *parent,  Node<T> *other) const;
};





//por enquanto vamos desconsiderar os operadores ++ e -- em conjuntos...
//tais operadores serao "escondidos"
template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(Node<T> *ptr_): ptr(ptr_) { }
	T &operator*() {return ptr->elem;}

	bool operator==(const MySetIterator &other) const {return ptr==other.ptr;}
	bool operator!=(const MySetIterator &other) const {return ptr!=other.ptr;}

	MySetIterator operator++();
	MySetIterator operator++(int);

	MySetIterator operator--();
	MySetIterator operator--(int);
private:
	Node<T> *ptr;
};


//operador de pre-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++() {
	if(ptr->right) { //pegue o menor elemento da sub-arvore direita
		ptr = ptr->right;
		while(ptr->left) ptr=ptr->left;
	} else { //mais dificil..temos que subir na arvore ate fazermos a primeira virada a direita
		while(ptr->parent && ptr->parent->right==ptr) ptr = ptr->parent;  //enquanto vou a esquerda para chegar a meu pai, suba...
		ptr = ptr->parent;	//vire a direita (subindo) uma vez

		//para que precisamos do "ptr->parent &&" no while?
		//O que acontece se incrementarmos um iterador para o ultimo elemento da arvore?
	}
	return *this;
}

//operador de pre-decremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator--() {
	//faca tudo que fez no operador ++, mas no sentido contrario (left --> right e vice-versa)!
	if(ptr->left) { 
		ptr = ptr->left;
		while(ptr->right) ptr=ptr->right;
	} else { 
		while(ptr->parent && ptr->parent->left==ptr) ptr = ptr->parent;  
		ptr = ptr->parent;	

		//para que precisamos do "ptr->parent &&" no while?
		//O que acontece se decrementarmos um iterador para o primeiro elemento?
		//O que acontece se decrementarmos um apontador para end()?		
	}
	return *this;
}



//operador de pos-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++(int) {
	MySetIterator<T> old(*this);
	++(*this);
	return old;
}

//operador de pos-decremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator--(int) {
	MySetIterator<T> old(*this);
	--(*this);
	return old;
}

template  <class T>
typename MySet<T>::iterator MySet<T>::begin() {
	if(!root) return end();
	Node<T> *ptr = root;
	while(ptr->left) ptr = ptr->left;
	return iterator(ptr);
}









template  <class T>
int MySet<T>::size() const {
	return size_; //exercicio: como calcular o tamanho de forma dinamica? (i.e., sem armazenar o inteiro "size" na classe)
}

template  <class T>
MySet<T>::MySet(const MySet &other) {
	size_=other.size_;
	root = copyNodes(root, other.root);
}

template  <class T>
MySet<T>::~MySet() {
	destroy(root);
}

template  <class T>
void MySet<T>::destroy(Node<T> *ptr) {
	if (ptr==NULL) return;
	destroy(ptr->left);
	destroy(ptr->right);
	delete ptr;
}

template  <class T>
Node<T> * MySet<T>::copyNodes(Node<T> *parent,  Node<T> *other) const {
	if(other==NULL) { //caso base
		return NULL;
	}
	Node<T> *  ans = new Node<T>(other->elem);
	ans->parent = parent;
	ans->left = copyNodes(ans, other->left);
	ans->right = copyNodes(ans, other->right);	

	return ans;
}

template  <class T>
MySet<T> MySet<T>::operator=(const MySet &other){
	if(this==&other) return *this;
	destroy(root);	
	size_ = other.size_;
	root = copyNodes(root, other);
	return *this;
};



//funcao auxiliar...
//exercicio: por que a raiz precisa ser passada por referencia?
template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, Node<T> * &root, Node<T> *parent) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if(!root) {
		root = new Node<T>(elem);
		root->parent = parent;
		size_++;
		return make_pair(iterator(root),true);
	} else {
		if(root->elem > elem) return insert(elem, root->left, root);
		else if (root->elem < elem) return insert(elem, root->right, root);
		else return make_pair(iterator(root),false);//igual..
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	return insert(elem,root, NULL);
}



//funcao auxiliar...
template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem, Node<T> *root) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if(!root) {		
		return iterator(NULL);
	} else {
		if(root->elem > elem) return find(elem, root->left);
		else if (root->elem < elem) return find(elem, root->right);
		else return iterator(root);//igual..
	}
}


template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem) {
	return find(elem,root);
}




#include "MyQueue.h"

/*
template  <class T>
void MySet<T>::imprimeBFS() const { //um nivel por vez..
	MyQueue<Node<T> *> q;
	MyQueue<Node<T> *> u;
	if(!root) return;
	u.push(root);

	int nivel = 0;
	while(!u.empty()) {
		q = u;
		u = MyQueue<Node<T> *>();

		cout <<  "Nivel " << nivel++ << " : ";
		while(!q.empty()) {
			Node<T> * p = q.front();
			q.pop();
			cout << p->elem << " ";
			if(p->left) u.push(p->left);  
			if(p->right) u.push(p->right);
		}
		cout << endl;
	}
	
}*/


template  <class T>
void MySet<T>::imprimeBFS() const {
	MyQueue<Node<T> *> q;
	if(!root) return;
	q.push(root);

	while(!q.empty()) {
		Node<T> * p = q.front();
		q.pop();
		cout << p->elem << " ";
		if(p->left) q.push(p->left);  
		if(p->right) q.push(p->right);
	}
}


template  <class T>
void MySet<T>::imprimeDFS_pre(const Node<T> *p) const {
	if(!p) return;
	cout << p->elem << " ";
	imprimeDFS_pre(p->left);
	imprimeDFS_pre(p->right);
} 

template  <class T>
void MySet<T>::imprimeDFS_in(const Node<T> *p) const {
	if(!p) return;	
	imprimeDFS_in(p->left);
	cout << p->elem << " ";
	imprimeDFS_in(p->right);
} 


template  <class T>
void MySet<T>::imprimeDFS_pos(const Node<T> *p) const {
	if(!p) return;
	imprimeDFS_pos(p->left);
	imprimeDFS_pos(p->right);
	cout << p->elem << " ";
} 


template  <class T>
void MySet<T>::imprimeDFS_pre() const {
	imprimeDFS_pre(root);
}

template  <class T>
void MySet<T>::imprimeDFS_in() const {
	imprimeDFS_in(root);
}

template  <class T>
void MySet<T>::imprimeDFS_pos() const {
	imprimeDFS_pos(root);
}





#endif