#include <iostream>
#include <list>
using namespace std;

int contar(list<int> lista){
	list<int>::iterator it;
	
	int conta = 0;
	for(it = lista.begin(); it != lista.end(); it++){
		conta += 1;
	}
	// return lista.size();
	return conta;
}

int main()
{
	int aux;
	list<int> lista;
	
	while(aux != 0){
		cin >> aux;
		
		if(aux == 0)
			break;
		lista.push_back(aux);
	}
	
	int total;
	
	
	// cout << lista.size() << endl;
	total = contar(lista);
	cout << total << endl;
	
	return 0;
}