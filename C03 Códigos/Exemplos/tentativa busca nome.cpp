#include <iostream>
#include <string>
using namespace std;

struct aluno
{
    int matricula;
    string curso;
    string nome;
};

int busca_aluno(aluno alunos[], string nome, int N)
{
    int i; // contador
    for (i = 0; i < N; i++)
    {
        if (alunos[i].nome == nome)
        {
            return i; // retornando a posicao em que o aluno foi cadastrado
        }
    }
    return -1; // retornando -1 se o aluno nao for encontrado
}

int main()
{
    int N; // numero de alunos
    string nome;
    cin >> N;
    
    // alunos a serem cadastrados
    aluno alunos[N];

    // cadastrando cada aluno
    for (int i = 0; i < N; i++)
    {
        getline(cin, alunos[i].nome);
        getline(cin, alunos[i].curso);
        cin.ignore();
        cin >> alunos[i].matricula;
    }

    int j; // posicao do vetor em que o aluno esta cadastrado
    cin.ignore();
    cin >> nome;

    // calculando a posicao
    j = busca_aluno(alunos, nome, N);

    cout << j << endl;
    
    // imprimindo o nome, curso e matricula com a posicao j
    if (j != -1)
    {
        cout << alunos[j].nome << endl;
        cout << alunos[j].curso << endl;
        cout << alunos[j].matricula << endl;
    }
    else
        cout << "Nao encontrado" << endl;

    return 0;
}
