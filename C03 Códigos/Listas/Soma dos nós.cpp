#include <iostream>
#include <list>
using namespace std;

int soma(list<int> lista){
	list<int>::iterator it;
	
	int soma = 0;
	for(it = lista.begin(); it != lista.end(); it++){
		soma += *it;
	}
	
	return soma;
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
	
	int somatorio;
	
	somatorio = soma(lista);
	cout << somatorio << endl;
	
	
	return 0;
}