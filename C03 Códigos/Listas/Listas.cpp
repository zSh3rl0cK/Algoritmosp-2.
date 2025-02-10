#include <iostream>
#include <list>

using namespace std;

int main()
{
	//<int> fala o tipo do conteudo da lista dinamica
	list<int> lista;
	
	int vetor[10] = {33, 66, 99, 121, 155, 63, 52, 12, 21, 47};
	
	// vetor[0] = 33; vetor[1] = 66; etc
	
	// inserindo os valores na lista
	lista.push_back(33);
	lista.push_back(66);
	lista.push_back(99);
	lista.push_back(121);
	
	// para fazer uma varredura dos valores do vetor:
	for(int i = 0; i <5; i++){
		cout << vetor[i] << " ";
	}
	
	// nao há como fazer a busca sequencial na lista, portanto precisa-se fazer:
	
	list<int>;;iterator it; // funciona como um ponteiro para a lista
	
	it = lista.begin(); // aponta para a 1 posicao
	
	// dessa forma pode se fazer a varredura da lista
	while(it != lista.end()){
		cout << *it << endl; //
		it++;
	}

	// retorna o tamanho da lista
	cout << lista.size() << endl;
	
	// retorna o primeiro valor da lista
	cout << lista.front() << endl;
	
		
	return 0;
}