#include <iostream>
#include <string>
using namespace std;

typedef struct item {
    int codigo;
    string nome;
    float preco;
} Item;

void selection_sort(Item vetor[], int n, int o) {
    if (o == 0) {
        for (int i = 0; i < n - 1; i++) {
            int menor = i;
            for (int j = i + 1; j < n; j++) {
                if (vetor[j].codigo < vetor[menor].codigo) {
                    menor = j;
                }
            }
        
            Item temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    } else if (o == 1) {
        for (int i = 0; i < n - 1; i++) {
            int menor = i;
            for (int j = i + 1; j < n; j++) {
                if (vetor[j].preco < vetor[menor].preco) {
                    menor = j;
                }
            }
            Item temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

int main() {
    Item itens[1000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> itens[i].codigo;
        cin.ignore();
        getline(cin, itens[i].nome);
        cin >> itens[i].preco;
    }

    int o;
    cin >> o;

    selection_sort(itens, n, o);

    for (int i = 0; i < n; i++) {
        cout << itens[i].nome << endl;
        
        return 0;
    }
            cout << itens[i].codigo << " " << itens[i].nome << " " << itens[i].preco << endl;
        } else if (o
