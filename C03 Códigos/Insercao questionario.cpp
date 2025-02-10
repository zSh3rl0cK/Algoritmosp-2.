// numeros 10, 22, 31, 5, 15, 28 e m = 13 c1 = 2 c2 = 3

#include <iostream>
using namespace std;

struct dado{
    int status;
    int k;
};

int hash_aux(int k, int m){
    int h;
    h = k%m;
    
    return h;
}

int hash1(int k, int i, int m){
    
    int h;
    int res = hash_aux(k,m);
    
    h = (res + i)%m;
    
    return h;
}

int hash2(int k, int i, int m, int c1, int c2){
    
    int h;
    
    h = (hash_aux(k, m) + c1*i + c2*i*i)%m;
    
    return h;
    
}

int hash_insert(dado T[], int m, int k, int c1, int c2){
    int i = 0;
    int j; // posicao
    
    while(i<m){
        j = hash2(k, i , m, c1, c2);
        
        if (T[j].status != 1){
            T[j].k = k;
            T[j].status = 1;
           break;
        }
        
        i++;
    }
    
    return j;
}

int main(){
    
    int k; // chave a ser inserida
    int m; // tamanho da tabela hash
    int c1, c2;
    
	cin >> m >> c1 >> c2;
    
    dado T[m];
    
   for(int i = 0; i < m; i++){
        T[i].k = -1;
        T[i].status = -1;
    }
    
     do{
        cin >> k;
        if(k == 0)
            break;
        
        hash_insert(T, m, k, c1, c2);
        
    }while(k != 0);
    
    for(int i = 0; i < m; i++){
        if(T[i].status == 1)
            cout << T[i].k << " ";
        else
            cout << "-1" << " ";
    }
    
    
    return 0;
}