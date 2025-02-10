#include <iostream>
#include <string>

struct aluno
{
	int matricula;
	int idade;
	string nome;
};

aluno cria_aluno
{
	aluno a;
	
	cin >> a.matricula;	
	cin >> a.nome;
	cin >> a.idade;	
};

int main()
{
	int n;
	
	cin >> n;
	
	aluno alunos[n];	
	
	for(int i = 0; i < n; i++)
	{
		aluno[i] = cria_aluno();
	}
	
	return 0;
}