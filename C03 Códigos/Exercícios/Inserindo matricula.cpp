#include <string>
#include <iostream>
#include <locale.h>

using namespace std;

struct aluno
{
	string nome; // nome de cada aluno
	int idade; // idade de cada aluno
	int matricula; // matricula de cada aluno
};

aluno cria_aluno()
{
	aluno a;
	
	cin >> a.matricula;
	cin >> a.nome;
	cin >> a.idade;
	
	return a;
}

int main()
{
	int num; // numero de alunos
	int mat; // matricula
	int info; // informação
	int menorg = 0; // idade menor ou igual
	int idade; // idade 
	string nome; // nome
	
	// permitindo acentuação
	setlocale(LC_ALL, "");
	
	// inserindo o numero de alunos
	cin >> num;
	
	// struct dos alunos
	aluno alunos[num];
	
	// matriculando cada aluno
	for(int i = 0; i < num; i++)
	{
		alunos[i] = cria_aluno();
	}
	
	// inserindo o método de busca de alunos
	cout << "Insira o método de busca" << endl;
	cin >> info;
	
	// Busca por matricula
	if(info == 1)
	{
		cin >> mat;
		
		for(int i = 0; i < num; i++)
		{
			if(mat == alunos[i].matricula)
			{
				cout << alunos[i].matricula << endl;
				cout << alunos[i].nome << endl;
				cout << alunos[i].idade << endl;
			}
		}
	}
	
	// Busca por nome
	else if(info == 2)
	{
		cin >> nome;
		
		for(int i = 0; i < num; i++)
		{
			if(nome == alunos[i].nome)
			{
				cout << alunos[i].matricula << endl;
				cout << alunos[i].nome << endl;
				cout << alunos[i].idade << endl;
			}
		}
	}

	// Busca de idades menores ou iguais
	else if(info == 3)
	{
		cin >> idade;
		
		for(int i = 0; i < num; i++)
		{
			if(idade <= alunos[i].idade)
			{
				menorg += 1;
			}
		}
		
		cout << menorg << endl;
	}
	
	// caso um numero diferente seja inserido
	else
	{
		cout << "Não existe" << endl;
	}
	
	return 0;
}