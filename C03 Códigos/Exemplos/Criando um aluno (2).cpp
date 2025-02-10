#include <string>
#include <iostream>

using namespace std;

struct aluno
{
	int matricula;
	string nome;
};

aluno cria_aluno()
{
	aluno a;
	
	cin >> a.matricula;
	cin >> a.nome;
	
	return a;
}

int main()
{
	int n; // numero de alunos
	
	// inserindo o numero de alunos
	cin >> n;
	
	// struct alunos
	aluno alunos[n];
	
	// inserindo a matricula e o nome de cada aluno
	for(int i = 0; i < n; i++)
	{
		alunos[i] = cria_aluno();
	}
	
	return 0;
}