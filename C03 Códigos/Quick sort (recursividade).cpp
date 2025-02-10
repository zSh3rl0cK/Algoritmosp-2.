#include <iostream>

using namespace std;

void troca(int vetor[], int i, int j){
	int aux = vetor[i];
	
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int particiona(int vetor[], int inicio, int fim){
	
	int pivo = vetor[fim];
	
	
	int i = 0, j = fim - 1;
	while(i < j){
		
		while(vetor[i] < pivo && i < j){		
			i++;
		}
		
		while(vetor[j] > pivo && i < j){
			   j--;	
		}
		
		troca(vetor, i, j);
		
	}
	
	if(vetor[i] > pivo)
		troca(vetor, i, fim);
	
	return i;
}

void quick_sort(int vetor[], int inicio, int fim){
	
	if(inicio < fim){
		// Fazemdo a ordenação em relção ao pivô
		int pivo = particiona(vetor, inicio, fim);
		
		// Chamando o quick sort para a metade inferior
		quick_sort(vetor, inicio, pivo - 1);
		
		// Chamando o quick sort para a metade superiorm
		quick_sort(vetor, pivo + 1, inicio);
	}
}

int main()
{
	int vetor[9] = {9,8,1,4,3,6,2,7,5};
	
	quick_sort(vetor, 0, 9);
	
	return 0;
}	