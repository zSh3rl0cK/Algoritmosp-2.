#include <iostream>
#include <string>

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
    cin.ignore(); // Para consumir a nova linha após a leitura da matrícula
    getline(cin, a.nome);
    cin >> a.idade;

    return a;
}

int busca_seq_aluno_mat(aluno alunos[], int n, int mat)
{
    for (int i = 0; i < n; i++)
    {
        if (mat == alunos[i].matricula)
            return i;
    }
    return -1;
}

int busca_seq_aluno_nome(aluno alunos[], int n, string nome)
{
    for (int i = 0; i < n; i++)
    {
        if (nome == alunos[i].nome)
            return i;
    }
    return -1;
}

int busca_seq_aluno_idade(aluno alunos[], int n, int idade)
{
    int quantidade = 0;

    for (int i = 0; i < n; i++)
    {
        if (idade >= alunos[i].idade)
            quantidade += 1;
    }
    return quantidade;
}

int main()
{
    int n;
    cin >> n;

    aluno alunos[n];

    for (int i = 0; i < n; i++)
    {
        alunos[i] = cria_aluno();
    }

    int met;
    cin >> met;

    if (met == 1)
    {
        int mat;
        int result;
        cin >> mat;

        result = busca_seq_aluno_mat(alunos, n, mat);

        if (result != -1)
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
    else if (met == 2)
    {
        string nome; // Corrigido para usar string em vez de int
        int buscado;
        cin.ignore(); // Para consumir a nova linha após a leitura do valor de met
        getline(cin, nome);

        buscado = busca_seq_aluno_nome(alunos, n, nome);

        if (buscado != -1)
        {
            cout << alunos[buscado].nome << endl; // Corrigido de result para buscado
            cout << alunos[buscado].matricula << endl;
            cout << alunos[buscado].idade << endl;
        }
        else
        {
            cout << "Não encontrado" << endl;
        }
    }
    else if (met == 3) // Adicionado else if aqui
    {
        int resultado;
        int idade;

        cin >> idade;

        resultado = busca_seq_aluno_idade(alunos, n, idade); // Adicionado ponto e vírgula

        cout << "Existe(m) " << resultado << " aluno(s) com essa idade." << endl; // Corrigido "alunos" para "aluno"
    }
    return 0;
}