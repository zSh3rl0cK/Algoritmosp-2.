#include <iostream>
#include <string>

struct aluno
{
	// informações do aluno
	
	int matricula;
	int idade;
	string nome;
};

aluno cria_aluno
{
	aluno a;
	
	// cadastro do aluno
	cin >> a.matricula;	
	cin >> a.nome;
	cin >> a.idade;	
}

int busca_seq_aluno_mat(aluno alunos[], int n, int mat)
{
	/* preferência pelo int por ocupar menos memória 
	poderia ser feito usando void ou com o tipo aluno*/
	
	for(int i = 0; i < n; i++)
	{
		if(mat == alunos[i].matricula)
			return i;
	}
	return -1;
}

int busca_seq_aluno_nome(aluno alunos[], int n, string nome)
{
	/* preferência pelo int por ocupar menos memória 
	poderia ser feito usando void ou com o tipo aluno*/
	
	for(int i = 0; i < n; i++)
	{
		if(nome == alunos[i].nome)
			return i;
	}
	return -1;
}

int busca_seq_aluno_idade(aluno alunos[], int n, int idade)
{
	/* preferência pelo int por ocupar menos memória 
	poderia ser feito usando void ou com o tipo aluno*/
	
	int quantidade = 0; 
	
	for(int i = 0; i < n; i++)
	{
		if(idade >= alunos[i].idade)
			quantidade += 1;
	}
	return quantidade;
}

int main()
{
	// numero de alunos
	int n;
	cin >> n;
	
	// alunos
	aluno alunos[n];	
	
	// cadastro dos alunos
	for(int i = 0; i < n; i++)
	{
		aluno[i] = cria_aluno();
	}
	
	int met;
	cin >> met;

	if(met == 1)
	{
		// Area da busca por aluno
		
		int mat; // matricula para buscar
		int result; // posição do aluno
		
		cin >> mat;
		
		// encontrando a posição
		result = busca_seq_aluno_mat(alunos, n, mat);
		
		// imprimindo as infos. do aluno buscado
		
		if(result != -1)
		{
			cout << alunos[result].nome << endl;
			cout << alunos[result].matricula << endl;
			cout << alunos[result].idade << endl;
		}
		else
		{
			cout << "Não encontrado" << endl;
		}
	}
	
	else if(met == 2)
	{
		int buscado;
		int nome;
		cin >> nome;
		
		buscado = busca_seq_aluno_nome(alunos, n, nome);
		
		// imprimindo as infos. do aluno buscado
		
		if(buscado != -1)
		{
			cout << alunos[result].nome << endl;
			cout << alunos[result].matricula << endl;
			cout << alunos[result].idade << endl;
		}
		else
		{
			cout << "Não encontrado" << endl;
		}
	}
	
	if(met == 3)
	{
		int resultado;
		int idade;
		
		cin >> idade;
		
		resultado = busca_seq_aluno_idade(alunos, n, idade)
		
		cout << "Existe(m) " << resultado << " alunos com essa idade." << endl;
	}
	return 0;
}