#include <iostream>
using namespace std;

int main()
{
	int vet = {3, 7, 2, 5, 9. 1, 4, 8, 6};  // vetor
	int n = 9; // tamanho do vetor
	
	int min;
	int pos_min; // posicao minimo
	int temp; // armazena o numero que será substituido no vetor
	
	// selection sort
	// n * (n/2)
	for(int i = 0; i < n; i++) // 2° crescimento linear N * N = N ^ 2
	{
		min = vetor[i]; // 3 (N-1)
		pos_min = i; // 2 (N - 1)
		
		// pior caso: (n - 1) melhor: 1 -- (n - 1) + 1/2 = n/2
		for(int j = i + 1; j < n; j++) // 1°crescimento linear N / 
		{
			if(vetor[i] < min) // (4 (N/2)) * (N - 1)
			{
				min = vetor[i]; // (3 (N/2)) * (N - 1)
				pos_min = j; // (2 (N/2)) * (N - 1)
			}
		}
		
		// invertendo os numeros
		temp = vetor[j];	
		vetor[j] = min;
		vetor[pos_min] = temp;	
	}
	
	//5 - (N-1) * 21 + (N - 1) * (9N + 3)
	
	// 9N² + 24N - 28
	
	return 0;
}