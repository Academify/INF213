#include <iostream>
#include <string>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
 #include "MyStack.h"
 #include "MyQueue.h"


void etapa1() {
	MyQueue<int> queue = MyQueue<int>();
	MyStack<int> stack = MyStack<int>();
	int entrada = 0;
	for (int i = 1; i<=6; i++){
		cin >> entrada;
		queue.push(entrada);
		stack.push(entrada);
	}
	for (int i = 1; i<=6; i++){
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;	
	for (int i = 1; i<=6; i++){
		cout << queue.front() << " ";
		queue.pop();
	}
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....


void etapa2() {

	string entrada;
	cin.ignore();
	getline(cin, entrada);

	MyStack<char> stack = MyStack<char>();
    char aux;
 
    for (int i = 0; i < entrada.length(); i++)
    {
        if (entrada[i] == '(' || entrada[i] == '['|| entrada[i] == '{'){	
        	stack.push(entrada[i]);
		}
        
        switch (entrada[i]) {
        case ')':
			if (stack.empty()){
				cout << "Inconsistente" << endl;
				return;
			}           
            aux = stack.top();
            stack.pop();
            if (aux != '('){
				cout << "Inconsistente" << endl;
				return;
			}
            break;
 
        case '}':
			if (stack.empty()){
				cout << "Inconsistente" << endl;
				return;
			} 
 
            aux = stack.top();
            stack.pop();
            if (aux == '(' || aux == '['){
				cout << "Inconsistente" << endl;
				return;
			}
            break;
 
        case ']':
 			if (stack.empty()){
				cout << "Inconsistente" << endl;
				return;
			} 
            aux = stack.top();
            stack.pop();
            if (aux == '(' || aux == '{'){
                cout << "Inconsistente" << endl;
				return;
			}
            break;
        }
    }
 	
	if(stack.empty()){
		cout << "Consistente" << endl;
	}else{
		cout << "Inconsistente" << endl;
	}

}
//---------------------------------------

// Insira aqui o codigo para a etapa 3....
 #include "Mediana.h"

//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
//#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}