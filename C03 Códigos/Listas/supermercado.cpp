#include <iostream>
#include <list>
using namespace std;

void coloca_venda(list<int> &lista1, list<int> &lista2){
	lista2.push_back(lista1.front());
	
	lista1.pop_front();
}

int main()
{
	list<int> lista1;
	list<int> lista2;
	
	int N;
	cin >> N;
	
	int aux;
	int tipo;
	
	for(int i = 0; i < N; i++){
		cin >> tipo;
		
		if(tipo == 1){
			cin >> aux;
		
			if(aux == 0)
				break;
			lista1.push_back(aux);
		}
		
		if(tipo == 2){
			coloca_venda(lista1, lista2);
		}
	}
	
	cout << "Estoque: ";
	list<int>::iterator it;
	for(it = lista1.begin(); it != lista1.end(); it++){
		cout << *it << " ";
	}
	
	cout << endl;
	
	cout << "Venda: ";
	
	for(it = lista2.begin(); it != lista2.end(); it++){
		cout << *it << " ";
	}
	return 0;
}