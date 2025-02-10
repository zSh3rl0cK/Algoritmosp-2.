// vetor: 1 2 7 10 3 6 8


for(int j = 0; j < n; j++)
{
	in + min = 9999;
	
	for(i = j; i < n; i++)
	{
		if(vetor[i] < min)
		{
			min = vetor[i];
			pos_min = i;
		}
	}
	
	temp = vetor[j];
	vetor[j] = min;
	
	vetor[pos_min] = temp;
}