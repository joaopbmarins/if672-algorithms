#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"

int h(int key, int mod){
    int temp = (int)floor((((double)key) / ((double)mod)));
    return (key - (mod * temp)) % mod;
}

typedef struct{
    int key;
    int value;
}HT;

int count = 0;

int Find_HT(HT **table, int m, int key, int perm[]){
    int index = h(key, m);
    if(table[index] != NULL && table[index]->key == key){//teste com o indice da hashf
        return index;
    }
    int tmp;
    for(int i=0;i<m-1;i++){
        tmp = (index + perm[i]) % m;
        if(table[tmp] != NULL && table[tmp]->key == key){//teste do pseudo random probing
            return tmp;
        }
    }
    return -1;
}

void Insert_HT(HT **table, int m, HT *add, int perm[]){
    int index = h(add->key, m);
    if(Find_HT(table, m, add->key, perm) != -1){//se ele achar a chave na tabela nao pode adicionar
        return;
    }
    if(table[index] == NULL){//teste com o indice da hashf
        table[index] = add;
        count++;
        return;
    }
    int tmp;
    for(int i=0;i<m-1;i++){
        tmp = (index + perm[i]) % m;
        if(table[tmp] == NULL){//teste com o pseudo random probing
            table[tmp] = add;
            count++;
            return;
        }
    }
}

void Print_HT(HT **table, int m){
    for(int i=0;i<m;i++){
        cout << i << ".";
        if(table[i] == NULL){
            cout << "----" << endl;
        }
        else{
            cout << table[i]->key << " " << table[i]->value << endl;
        }
    }
}

int main(){
    int m;
    cin >> m;
    while(m != 0){
        int perm[m-1];
        HT *HashT[m] = {NULL};

        for(int i=0;i<m-1;i++){
            cin >> perm[i];
        }

        int n;
        cin >> n;
        HT lixo[n];
        for(int i=0;i<n;i++){
            string comando;
            cin >> comando;
            if(comando == "add"){
                cin >> lixo[i].key;
                cin >> lixo[i].value;
                Insert_HT(HashT, m, &lixo[i], perm);
            }
            else if(comando == "find"){
                int buscado;
                cin >> buscado;
                int result = Find_HT(HashT, m, buscado, perm);
                if(result != -1){
                    cout << result << " " << HashT[result]->value << endl;
                }
                else{
                    cout << -1 << endl;
                }
            }
        }
        //Print_HT(HashT, m);
        //cout << endl;
        cin >> m;
        count = 0;
    }
    

    return 0;
}