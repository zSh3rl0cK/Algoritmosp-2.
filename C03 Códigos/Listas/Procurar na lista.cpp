#include <iostream>
#include <list>
using namespace std;

bool encontrar(list<int> lista, int x){
	list<int>::iterator it;
	
	for(it = lista.begin(); it != lista.end(); it++){
		if(x == *it)
			return true;
	}
	
	return false;
}


int main()
{
	int aux;
	bool enc;
	list<int> lista;
	
	while(aux != 0){
		cin >> aux;
		
		if(aux == 0)
			break;
		lista.push_back(aux);
	}
	
	int n;
	cin >> n;

	enc = encontrar(lista, n);
	
	if(enc == true)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;
	
	return 0;
}