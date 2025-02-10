// numeros:  2 / 15 / 28 / 106 - 93
// posições: 2 / 6 / 12 / 9 - 3
#include <iostream>
using namespace std;
int h1(int k, int m) {
    int result = k%m;
    
    return result;
}

int h2(int k, int m){
    int result = 1+(k % (m - 1));
    return result;
}

int dhash(int k, int m, int i) {
    return ((h1(k, m) + i * h2(k, m)) % m);
}

int main() {
    int k; // chave a ser inserida
    int m; // tamanho da tabela hash

    cin >> m;
    
    int j;
    for(int i = 0; i < m; i++){
		cin >> k;
		j = dhash(k, m , i);
		cout << j << endl;
	}

    return 0;
}