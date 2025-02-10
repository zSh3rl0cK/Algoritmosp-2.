#include <iostream>
#include <list>
using namespace std;

int main(){
	
	
	list<int> pilha;
	
	int vetor = {};
	
	pilha.push_front();
	list<int>::interator it;
	
	it = pilha.begin();
	cout << "varredura da pilha" << endl;
	
	while(!pilha.empty()){
		cout << pilha.front() << endl;
		pilha.pop_front();
	}
	
	return 0;
}