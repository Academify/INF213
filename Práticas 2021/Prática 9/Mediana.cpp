#include <iostream>
#include "Mediana.h"
#include "MyPriorityQueue.h"
#include <algorithm>
using namespace std;


void Mediana::insere(int el) {
    menores.push(el);
    maiores.push(menores.top()*(-1));
    menores.pop();
    
    if (maiores.size() > menores.size() + 1) {
      menores.push(maiores.top()*(-1));
      maiores.pop();
    }
}

int Mediana::getMediana() {
    if (maiores.size() == 0) 
        return menores.top();

    if(maiores.size()==menores.size())              
        return((maiores.top()*(-1)+menores.top())/2);  

    else 
        return maiores.top()*(-1);
}


