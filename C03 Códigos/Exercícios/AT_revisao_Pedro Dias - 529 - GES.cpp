// Pedro Henrique Ribeiro Dias - GES - 529
// Exercício teams

#include <iostream>
#include <string>
#include <locale.h>
#define CURSOS 7
using namespace std;

string cursos[CURSOS] = {"GEC", "GES", "GEB", "GET", "GEE", "GEP", "GEA"};

typedef struct aluno{
	int matricula;
	string nome;
	int curso;
} Aluno;

void troca(Aluno &a, Aluno &b){
	Aluno temp = a;
	a = b;
	b = temp;
	return;
}

int encontra_menor_matricula(Aluno vetor[], int n, int inicio){
	int menor = inicio;
	for(int i=inicio+1;i<n;i++){
		if(vetor[i].matricula > vetor[menor].matricula)
			menor = i;
	}
	return menor;
}

void ordena1(Aluno vetor[], int n){
	for(int i = 0; i < n; i++){
	   int menor = encontra_menor_matricula(vetor, n, i);
	   troca(vetor[i], vetor[menor]); 
	}
} // O(n²) -- encontra_menor_matricula = O(n) e troca = O(1)

int divide(Aluno vetor[], int inicio, int fim){
	Aluno metade = vetor[(inicio+fim)/2];
	
	int i=inicio, j=fim;
	
	while(i <= j){
		while(vetor[i].matricula < metade.matricula && i < fim)
			i++;
		while(vetor[j].matricula > metade.matricula && j > inicio)
			j--;
		troca(vetor[i], vetor[j]);
		i++;
		j--;
	}
	return i;
} // analise assintotica O(n) (os whiles vao ser so o inicio ou o fim caminhando pelo vetor)

int busca_aluno(Aluno vetor[], int n, int matricula_buscada){
    int inicio = 0, fim = n - 1; // 1 + 3
    int metade;

    while (inicio <= fim) { // 3logN + 3
        metade = (inicio + fim) / 2; // 5logN
        if (vetor[metade].matricula == matricula_buscada) { // 4logN
            return metade; // 1
        } else if (vetor[metade].matricula > matricula_buscada) { // 4logN
            fim = metade - 1; // 3logN/2
        } else {
            inicio = metade + 1; // 3logN/2
        }
		// metade das vezes cai no else e a outra metade cai no else if
    }
    return -1;
} // Analise pelo modelo ram = 15logN + 8


void alunos_curso(Aluno vetor[], int n, int curso){
	cout << "Alunos do curso " << cursos[curso] << ":" << endl; // 6
	for(int i=0;i<n;i++){ // 1 + 6n + 3
		if(vetor[i].curso == curso) // 4n
			cout << vetor[i].nome << endl; // 4n
	}
} // Analise pelo modelo ram = 14n + 10

void ordena2(Aluno vetor[], int inicio, int fim){
	if(inicio >= fim)
		return;
	int metade = divide(vetor,inicio,fim);
	ordena2(vetor,inicio,metade-1);
	ordena2(vetor,metade+1,fim);	
}

int main(){
	
	setlocale(LC_ALL, "");
	
	Aluno alunos[1000];
	
	int n;
	cout << "Informe a quantidade de alunos: ";
	cin >> n;
	
	for(int i=0;i<n;i++){
		cout << "Cursos:";
		for(int j=0;j<CURSOS;j++)
			cout<<" |"<<j<<": "<<cursos[j]<<"| ";
		
		cout << "\n\nMatricula: ";
		cin >> alunos[i].matricula;
		cout << "Nome: ";
		cin.ignore();
		
		getline(cin, alunos[i].nome);
		cout << "Curso(0 a 6): ";
		cin >> alunos[i].curso;
		
		cout << endl;
	}
	
	cout << "Lista em ordem de matricula:"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<alunos[i].nome<<endl;
	}
	
	int op;
	cout << "\nInforme o curso que deseja visualizar: ";
	cin >> op;
	cout << endl;
	
	alunos_curso(alunos,n,op);
	
	
	cout << "\nInforme o aluno que deseja visualizar: ";
	cin >> op;
	cout << endl;
	
	int indice_aluno = busca_aluno(alunos, n, op);
	
	if(indice_aluno != -1){
		Aluno aluno = alunos[indice_aluno];
		cout << "Nome: " << aluno.nome<<endl;
		cout << "Curso: " << cursos[aluno.curso]<<endl;
	}
	
	return 0;
}

/* Respostas perguntas teams: 

Complexidade da função ordena1: Assitótica = O(N²)

 Complexidade da função ordena2: Assintótica = 
 T = 2T * (n/2) + O(N)  --  O(n * log(n))
 
Analise pelo modelo ram da função busca_ aluno = 15logN + 8

analise assintotica da função divide = O(n)

Analise pelo modelo ram da função alunos_curso = 14n + 10

*/