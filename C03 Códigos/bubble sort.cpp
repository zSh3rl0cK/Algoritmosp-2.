#include <iostream>
using namespace std;

int main()
{
	int vetor[9] = {3, 7, 2, 5, 9. 1, 4, 8, 6};  // vetor
	int n = 9; // tamanho do vetor
	int min; // menor numero
	int pos_min; // posicao minimo
	int temp; // armazena o numero que será substituido no vetor
	
	
	
	// bubble sort
	for(int i = (N - 1); i > 0; i--) // 6 + 6(N - 1)
	{
		for(int j = 0; j < i; j++) // (6 + 6(N/2)) (N -1)
		{
			if(vetor[i] > vetor[j + 1]) // 6(N/2) (N -1)
			{
				// invertendo os numeros
				temp = vetor[j]; // 3(N/2) (N - 1)
				vetor[j] = vetor[i + 1]; // 4(N/2) (N - 1)
				vetor[J + 1] = temp; // 4(N/2) (N - 1)
			}
		}
	}
	
	// 12n - 12 + 21((n² - n)/2)
	
	// 11n² + n + 6
	
	// O (N²)
	return 0;
}