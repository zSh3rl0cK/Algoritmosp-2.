/*
	Esses sitema tem o objetivo de registar dados de alunos em uma tabela hash.
	O processo de cadastro de alunos é o seguinte:
		1 - Primeiro os dados do aluno são informados pelo usuário;
		2 - Em seguida, o aluno entra na fila de matrículas;
		3 - Assim que a fila é processada, os alunos são registrados na tabela.
		Obs.: A tabela tem um limite de matrículas e os demais alunos que não puderem ser registrados devem permanecer na fila.
	O processo de exclusão de alunos é o seguinte:
		1 - O aluno é buscado na tabela e iserido em uma pilha de análises;
		2 - Quando o cosnelho analisa a pilha, os alunos são excluídos da tabela.
		Obs.: O conselho só processa 5 alunos da pilha por vez.
	Os usuários podem ainda gerar listas de alunos ativos por curso e buscar os dados de um aluno pela matrícula. 

*/

// Resolução exercício - Pedro Henrique Ribeiro Dias - 529

#include<iostream>
#include<list>
#include <locale.h> 
#define MAX_CURSOS 7
#define MAX_PROCESSOS_CONSELHO 5
using namespace std;
const string SIGLAS_CURSOS[MAX_CURSOS] = {"GEC", "GES", "GEB", "GET", "GEE", "GEP", "GEA"};

// certo
struct Aluno{
	int matricula;
	string nome;
	int curso;
	int status;
};

// certo
int hash_aux(int k,int m){
	return k % m;	
}

// certo
int hash_aux2(int k,int m){
	return 1+(k % (m-1));
}

// certo
int hash_duplo(int k,int m, int i){
	return (hash_aux(k,m)+i*hash_aux2(k,m))%m;	
}

// corrigido
int insere_aluno(Aluno tabela_hash[], int m, Aluno aluno){
	int pos, i = 0;
	while(i<m){
		pos = hash_duplo(aluno.matricula, m, i);
		if(tabela_hash[pos].status != 1){
			tabela_hash[pos].nome = aluno.nome;
			tabela_hash[pos].matricula = aluno.matricula;
			tabela_hash[pos].curso = aluno.curso;
			tabela_hash[pos].status = 1;
			return pos;
		}
		i++;
	}
	return -1;	
}

// certo(?)
void lista_cursos(){
	cout<<"Cursos disponíveis: "<<0<<": "<<SIGLAS_CURSOS[0];
	for(int i=1;i<MAX_CURSOS;i++){
		cout<<", "<<i<<": "<<SIGLAS_CURSOS[i];
	}
	cout<<endl;
}

// certo
int solicita_curso(){
	int curso;
	lista_cursos();
	while(true){
		cout<<"Digite o curso (0 a "<<MAX_CURSOS-1<<"): ";
		cin>>curso;
		if(curso < 0 || curso >= MAX_CURSOS)
			cout<<"Curso inválido."<<endl;
		else
			return curso;
	}
	return -1;
}

// Provavelmente corrigido
Aluno novo_aluno(){
	Aluno novo;
	
	cout <<"Digite a matrícula do aluno: ";
	cin >> novo.matricula;
	
	
	cin.ignore();
	
	cout<<"Digite o nome do aluno: ";
	getline(cin,novo.nome);
	
	novo.curso = solicita_curso();
	return novo;
}

// certo
void exibe_aluno(Aluno a){
	cout<<endl<<"Informações do aluno "<<a.nome<<endl;
	cout<<"Matrícula: "<<a.matricula<<endl;
	cout<<"Curso: "<<SIGLAS_CURSOS[a.curso]<<endl<<endl;	
}

// certo
void lista_alunos(Aluno tabela_hash[], int m){
	for(int i=0;i<m;i++){
		cout<<"Posição "<<i<<": ";
		if(tabela_hash[i].status == 1)
			exibe_aluno(tabela_hash[i]);
		else if(tabela_hash[i].status == 2)
			cout<<"Aluno removido.";
		else
			cout<<"Matrícula disponível.";
		cout<<endl;
	}
}


// corrigindo... status: provavelmente corrigido
int buscar_aluno(Aluno tabela_hash[], int m, int matricula){
	int i = 0;
    int j;
    
    do{
        j = hash_duplo(matricula,m,i);
        
        if (tabela_hash[j].matricula == matricula){                             
            return j;
        }
        
        i++;
    }while(tabela_hash[i].status != 0 && i<m);
    
    return -1;
}

// corrigindo... status: provavelmente corrigido
int remover_aluno(Aluno tabela_hash[], int m, int matricula){
	int j;
	j = buscar_aluno(tabela_hash, m, matricula);                                
      
    if(j != -1){
       tabela_hash[j].status = 2;
       tabela_hash[j].matricula = -1;
       return 0; // consegui remover
    }
	else
		return -1;	
}

// certo
int menu(){
	int op;
	cout<<"\t\t\tMenu\n";
	cout<<"\t1:\tInserir aluno na fila de matrícula.\n";
	cout<<"\t2:\tBuscar aluno\n";
	cout<<"\t3:\tListar alunos ativos do curso.\n";
	cout<<"\t4:\tInserir aluno na pilha de remoção.\n";
	cout<<"\t5:\tProcessar fila de matrículas.\n";
	cout<<"\t6:\tEnviar alunos excluídos para análise do conselho.\n";
	cout<<"\t-1:\tSair\n";
	
	cin>>op;
	
	return op;
}

int main(){
	setlocale(LC_ALL,"");
	cout<<"Bem-vindo(a) ao sistema de cadastro de alunos!\n\n";
	
	list<Aluno> fila;
	list<Aluno> pilha;
	
	int m = 10;
	Aluno tabela_hash[m];
	
	for(int i=0;i<m;i++){
		tabela_hash[i].matricula = -1;
		tabela_hash[i].status = 0;
	}
	
	int op = 0;
	while(op != -1){
		op = menu();
		switch(op){
			case 1:
			{
				// Inserir aluno na fila
				Aluno novo = novo_aluno();
				fila.push_back(novo);			                               	
				break;
			}
			case 2: 
			{
				// Buscar aluno pela matrícula
				int matricula;
				cout<<"Informa a matrícula para buscar: ";
				cin>>matricula;
				int pos = buscar_aluno(tabela_hash, m, matricula);
				if(pos != -1){
					Aluno buscado = tabela_hash[pos];
					exibe_aluno(buscado);
				} else {
					cout<<"Aluno não encontrado"<<endl;
				}
				break;
			}
			case 3:
			{
				// Listar alunos de um determinado curso
				solicita_curso();
				lista_alunos(tabela_hash, m);
				break;                                                          
			}
			case 4:
			{				
				// Remover aluno pela matrícula
				int matricula;
				cout<<"Informa a matrícula para remover: ";
				cin>>matricula;
				
				// Buscar aluno a ser removido
				int pos = buscar_aluno(tabela_hash, m, matricula);
				if(pos != -1){
					Aluno removido = tabela_hash[pos];
					// Adicionar aluno na pilha
					pilha.push_front(removido);
					
				} else {
					cout<<"Aluno não encontrado"<<endl;
				}
				break;
			}
			case 5:
			{				
				// Processar fila de matrículas
				while(!fila.empty()){
					Aluno novo;
					// Seleciona um dos alunos a ser removido da fila
					novo = fila.front();
					int pos = insere_aluno(tabela_hash, m, novo);
					if(pos != -1){
						cout<<"Aluno inserido na posição "<<pos<<endl;
						// Remove da fila
						fila.pop_front();
					}
					else{
						cout<<"Tabela cheia!";
						break;
					}
				}
				break;
			}
			case 6:
			{
				// Processa pilha de remoções
				int processos = 0;
				while(processos < MAX_PROCESSOS_CONSELHO && !pilha.empty()){
					Aluno removido;
					// Seleciona um dos alunos a ser removido da pilha           
					removido = pilha.front();
					
					exibe_aluno(removido);
					char confirma = 'n';
					cout<<"Tem certeza que quer remover o aluno acima? (s/n)";
					cin>>confirma;
					if(confirma == 's'){
						// Remover da tabela
						remover_aluno(tabela_hash,m, removido.matricula);
					
					} else if(confirma == 'n') {
						cout<<"Aluno desconsiderado na remoção."<<endl;
						
					} else {
						cout<<"Opção inválida...";
						break;
					}
					// Remover da pilha
					pilha.pop_back();
					processos++;				
				}
				break;
			}
			case -1:
				break;				
			default:
				cout<<"Opção inválida!"<<endl<<endl;
				break;
		}		
	}
	
	
	
	cout<<"\n\nObrigado por utilizar o sistema de cadastro de alunos!\n";
	
	return 0;
}
