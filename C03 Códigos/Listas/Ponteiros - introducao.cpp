#include <iostream>
using namespace std;

int main()
{
	int a;
	int * p;
	
	p = &a; // p aponta para a
	
	cout << p /*ou &a*/ << endl; // retorna a posição 0xfef8 por exemplo
	
	*p = 25; // altera o conteudo para 25
	
	cout << (*p) << endl; // retorna o conteudo de p
	// obs: nao precisa necessariamente dos parenteses
	
	
	int b[10] = {0, 1, 2, 3 , 4, 5, 6 , 7, 8, 9};
	
	p = b; // p esta recebendo o vetor
	cout << *b  << enld; // retorna o conteudo de b
	// &b[0] retorna o endereco de b na posicao 0
	
	cout << *(p+3) << endl; // retorna o conteudo de b[3]
	
	return 0;
}