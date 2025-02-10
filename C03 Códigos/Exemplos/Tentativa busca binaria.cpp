#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

struct aluno
{
    int matricula;
    int idade;
    string nome;
};

aluno cria_aluno()
{
    aluno a;

    cin >> a.matricula;
    cin.ignore();
    cin >> a.nome;
    cin >> a.idade;

    return a;
}

int busca_bin_aluno_mat(aluno alunos[], int n, int mat)
{
   int inicio = 0;
   int fim = n - 1;
   int metade;
   
   while (inicio <= fim)
   {
	   metade = (inicio + fim) / 2; // calculando a metade do vetor
	   
	   if (alunos[metade].matricula == mat)
	   {
	   		return metade; // Retorna a posi��o do vetor onde a matr�cula foi encontrada
	   }
	   else if (alunos[metade].matricula < mat)
	   {
	   		inicio = metade + 1;
	   }
	   else
	   {
	   		fim = metade - 1;
	   }
   }
   
   return -1; // Retorna -1 se a matr�cula n�o for encontrada
}

int busca_bin_aluno_nome(aluno alunos[], int n, string nome)
{
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)
    {
        int metade = (inicio + fim) / 2; // calculando a metade do vetor

        if (alunos[metade].nome == nome)
        {
            return metade; // Retorna a posi��o do vetor onde o nome foi encontrado
        }
        else if (alunos[metade].nome < nome)
        {
            inicio = metade + 1; 
        }
        else
        {
            fim = metade - 1;
        }
    }

    return -1; // Retorna -1 se a matr�cula n�o for encontrada
}

int busca_seq_aluno_idade(aluno alunos[], int n, int idade)
{
    int quantidade = 0;

    for (int i = 0; i < n; i++)
    {
        if (idade >= alunos[i].idade)
            quantidade += 1;
    }
    
    return quantidade; // retorna a quantidade de alunos de acordo com as condi��es buscadas
}

int main()
{
    int n; // numero de alunos a serem cadastrados
    cout << "Insira o numero de alunos:" << endl;
    cin >> n;

    aluno alunos[n];

	// Habilitando a acentua��o no c�digo
	setlocale(LC_ALL, "");
	
	cout << "Cadastre os alunos por 
	// cadastrando cada aluno por meio da fun��o
    for (int i = 0; i < n; i++)
    {
        alunos[i] = cria_aluno();
    }

	cout << endl;
	
    int met; // m�todo de busca por aluno (matricula, nome e/ou idade)
    cout << "Insira o metodo de busca:" << endl;
    cin >> met;

	cout << endl;
	
	// buscando por matr�cula
    if (met == 1)
    {
        int mat; // matricula do aluno
        int result; // posi��o das infos. no vetor / -1 se n�o for encontrado
        cin >> mat;

        result = busca_bin_aluno_mat(alunos, n, mat);

        if (result != -1)
        {
            cout << alunos[result].nome << endl;
            cout << alunos[result].matricula << endl;
            cout << alunos[result].idade << endl;
        }
        else
        {
            cout << "N�o encontrado" << endl;
        }
    }
    
    // Buscando por nome
    else if (met == 2)
    {
        string nome; // nome a ser buscado
        int buscado; // posi��o das infos. do aluno  / -1 se n�o for encontrado
        cin.ignore(); // Para consumir a nova linha ap�s a leitura do valor de met
        cin >> nome; 
		
		cout << endl;
		
        buscado = busca_bin_aluno_nome(alunos, n, nome);
		
        if (buscado != -1)
        {
            cout << alunos[buscado].nome << endl; // Corrigido de result para buscado
            cout << alunos[buscado].matricula << endl;
            cout << alunos[buscado].idade << endl;
        }
        else
        {
            cout << "N�o encontrado" << endl;
        }
    }
    
    // busca da quantidade de alunos com a idade igual ou menor � fornecida
    else if (met == 3)
    {
        int resultado; // numero de alunos com a idade a ser buscada
        int idade;

        cin >> idade;

		cout << endl;
		
        resultado = busca_seq_aluno_idade(alunos, n, idade); // Adicionado ponto e v�rgula

        cout << "Existe(m) " << resultado << " aluno(s) com essa idade." << endl; // Corrigido "alunos" para "aluno"
    }
    
    return 0;
}