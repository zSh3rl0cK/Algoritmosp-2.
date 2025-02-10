#include <iostream>
#include <list>
using namespace std;

struct Item{
	int codigo;
	string nome;
	int preco;
	int status;
};

int hash_aux(int k,int m){
	return k % m;	
}

int hash_linear(int k,int m, int i){
	return (hash_aux(k,m)+i)%m;	
}

int inserir_item(Item tabela_hash[], Item valor, int m){
	int pos = -1, i = 0;
	
	while(i<m){
		pos = hash_aux(valor.codigo, m);
		if(tabela_hash[pos].status != 1){
			tabela_hash[pos] = valor;
			tabela_hash[pos].status = 1;
			return pos;
		}
		
		i++;
	}
	return -1;	
}

int buscar_item(Item tabela_hash[], int codigo, int m){
	int pos, i = 0;
	int status;
	
	do{
		pos = hash_linear(codigo, m, i);
		status = tabela_hash[pos].status;

		if(tabela_hash[pos].codigo == codigo){
			return pos;
		}
		
		i++;
	}while(tabela_hash[pos].status != 0 && i < m);
	
	return -1;		
}

int main(){
	setlocale(LC_ALL,""); // permitindo acentuação
	
	const int m = 53; // tamanho da tabela hash
	
	Item tabela_hash[m];
	
	list<int> vendas, compras;
	
	Item item;	
	
	for(int i = 0; i < m; i++){
	    tabela_hash[i].status = -1;
	}
	
	int n; // numero de itens a serem cadastrados
	cin >> n;
	
	for(int i=0;i<n;i++){
	    // inserindo as informações dos itens
		cin >> item.codigo;
		cin >> item.nome;
		cin >> item.preco;
		
		// inserindo o item na tabela
		inserir_item(tabela_hash, item, m);
	}
	
	int vi; 
	
	// inserindo numero de itens a serem vendidos
	cin >> vi;
	
	while(vi != -1){
		vendas.push_back(vi); // fila
		cin >> vi;
	}
	
	int ci;
	// inserindo códigos dos itens a serem comprados
	cin >> ci;
	
	while(ci != -1){
		compras.push_front(ci); // pilha
		cin >> ci;
	}
	
	
	int v, c, cod_item, pos_item, l=0;
	// inserindo a quantidade de itens a serem processados da fila dos vendidos e a da pilha dos comprados
	cin >> v >> c;
	
	// processando a fila dos vendidos
	while(v){
		cod_item = vendas.front();
		vendas.pop_front();
		pos_item = buscar_item(tabela_hash, cod_item, m);
		item = tabela_hash[pos_item];
		l += item.preco;
		v--;
	}
	
	// processando a pilha dos comprados
	while(c){
		cod_item = compras.front();
		compras.pop_front();
		pos_item = buscar_item(tabela_hash, cod_item, m);
		item = tabela_hash[pos_item];
		l -= item.preco;
		c--;
	}
	
	// imprimindo o lucro total obtido
	cout << l << " moeda(s)." << endl;
	
	return 0;
}