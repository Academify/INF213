#include <iostream>
#include "MyMap.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	string palavra;
	int contador = 0; 

	MyMap<string, int> map;
	while(cin>>palavra){
		if (map.find(palavra) == map.end()){
			map[palavra] = contador;
			contador++;
		}
		cout << palavra << " " << map[palavra] << endl;	
	} 
}
