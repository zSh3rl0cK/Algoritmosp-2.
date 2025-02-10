// Pedro Henrique Ribeiro Dias - 529 AT: Insertion Sort


/* A ideia do insertion sort é pegar o valor da posição j do vetor e procurar
por sua posicao. Ex: 7 8 9 15 10 11 -- ao chegar no 10 ele vai jogar para antes do 15
e ao chegar no 11 ele vai jogar para antes do 15, deixando o 15 na ultima posicao.
Assim, inserindo o vetor na posicao */

void insertion_sort(int vetor[], int tamanho)
{
	
	int i, j; // contadores
	int chave; // chave aux
	
	// j = 1 (2°posicao do vetor)
	for(j = 1; j < tamanho; j++) // 4+6 (N-1)
	{
		chave = vetor[j]; // 3(N-1)
		i = j-1; // 3(N-1)
		
		while((i >= 0) && (vetor[i] > chave)){ // 7 (n/2) (n-1)
			vetor[i+1] = vetor[i]; // 5 (n/2) (n-1)
			i = i-1; // 3 (n/2) (n-1)
		}
		
		vetor[i+1] = chave; // 4 (n-1) 
	}
} 

// O(N²) - análise assintótica / 16(n-1) + 15(n/2)(n-1) = 15n²/2 - 15n/2 - 15/2 = 7.5n² + 8.5n - 2 - Análise modelo RAM

/* Observando o outro código, a metodo de insertion sort é mais eficaz,
analisando pelo modelo RAM, já que no insertion sort o termo de maior grau é menor*/ 