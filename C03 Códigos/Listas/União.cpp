#include <iostream>
#include <list>
using namespace std;

void ordena(int vetor[], int cont){
	int chave;
	int i;
	
	for (int j = 1; j < cont; j++)
    {
        chave = vetor[j];
        i = j - 1;

        while ((i >= 0) && (vetor[i] > chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }

        vetor[i + 1] = chave;
    }
}

int main(){
	
	int aux;
	list<int> lista1;
	list<int> lista2;
	list<int> lista3;
	int uniao[50];
	int i = 0;
	
	while(aux != 0){
		cin >> aux;
		
		if(aux == 0)
			break;
		lista1.push_back(aux);
		uniao[i] = aux;
		i++;
	}
	
	aux = 1;
	
	while(aux != 0){
		cin >> aux;
		
		lista2.push_back(aux);
		uniao[i] = aux;
		i++;
	}
	
	ordena(uniao, i);
	
	for(int k = 0; k < i; k++){
		lista3.push_back(uniao[k]);
		cout << uniao[k] << " ";
	}
	return 0;
}