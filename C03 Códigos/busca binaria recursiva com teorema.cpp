#include <iostream>

using namespace std;

int vetor[9] = {1,2,3,4,5,6,7,8,9};

// Fórmula básica do teorema mestre T(n) = a * T(n/b) + n^b

// a = quantas vezes repete, b = quantas vezes é dividido e d = complexidade


int busca_bin(int elemento, int incio, int fim){
	
	int meio = (inicio + fim)/2;
	
	if(vetor[meio] = elemento)
		return meio;
	
	if(elemento > vetor[meio])
		busca_bin(elemento, meio + 1, fim);
	
	else
		busca_bin(elemento, incio, meio - 1);
}

int main()
{
	
	
	
	return 0;
}	