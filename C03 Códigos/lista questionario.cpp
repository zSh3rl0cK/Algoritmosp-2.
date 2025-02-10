#include <iostream>
#include <list>
#include <locale.h>
using namespace std;

int main()
{
	list<int> minhaLista;
	setlocale(LC_ALL, "");
	
	minhaLista.push_back(5);
	minhaLista.push_front(10);
	minhaLista.push_front(15);
	minhaLista.pop_back();
	minhaLista.push_front(20);
	minhaLista.pop_front();
		
	while(!minhaLista.empty()){
		cout << minhaLista.front() << " ";
		minhaLista.pop_front();
	}
	
	list<string> minhaLista2;

	minhaLista2.push_back("Maçã");
	minhaLista2.push_back("Banana");
	minhaLista2.push_back("Laranja");
	minhaLista2.pop_front();
	minhaLista2.push_back("Uva");
	minhaLista2.pop_front();
	
	cout << "Saída da Lista: " << minhaLista2.front() << endl;
	
	return 0;
}