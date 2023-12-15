#include <iostream>
using namespace std;
#define endl "\n"

int h(string key){
    int sum=0;
    for(int i = 0;i<key.size();i++){
        sum += 19 * key[i] * (i+1);
    }
    return sum % 101;
}

typedef struct{
    string key;
    int value;
}HT;

int count = 0;

int Find_HT(HT **table, string key){
    int index = h(key);
    if(table[index] != NULL && table[index]->key == key){//teste com o indice da hashf
        return index;
    }
    int tmp;
    for(int i=1;i<=19;i++){
        tmp = (index + i*i + 23 * i) % 101;
        if(table[tmp] != NULL && table[tmp]->key == key){
            return tmp;
        }
    }
    return -1;
}

void Insert_HT(HT **table, HT *add){
    int index = h(add->key);
    if(count >= 101 || Find_HT(table, add->key) != -1){//se ele achar a chave na tabela nao pode adicionar
        return;
    }
    if(table[index] == NULL){//teste com o indice da hashf
        table[index] = add;
        count++;
        return;
    }
    int tmp;
    for(int i=1;i<=19;i++){//colisao
        tmp = (index + i*i + 23 * i) % 101;
        if(table[tmp] == NULL){
            table[tmp] = add;
            count++;
            return;
        }
    }
}

HT* Remove_HT(HT **table, string key){
    int busca = Find_HT(table, key);
    if(busca == -1){//se ele nn acha a chave na tabela nao tem oq remover
        return NULL;
    }
    else{
        if(table[busca]->key == key){//teste extra provavelmente desnecessario 
            HT *tmp = table[busca];
            table[busca] = NULL;
            count--;
            return tmp;
        }
    }
    return NULL;
}

void Print_HT(HT **table){
    cout << count << endl;
    for(int i=0;i<101;i++){
        if(table[i] != NULL){
            cout << i << ":" << table[i]->key << endl;
        }
    }
}

int main(){
    int m;
    cin >> m;
    while(m != 0){
        HT *HashT[101] = {NULL};

        int n;
        cin >> n;
        HT lixo[n];
        for(int i=0;i<n;i++){
            string comando;
            cin >> comando;
            if(comando.substr(0,3) == "ADD"){
                lixo[i].key = comando.substr(4);
                Insert_HT(HashT, &lixo[i]);
            }
            else if(comando.substr(0,3) == "DEL"){
                string remo;
                remo = comando.substr(4);
                Remove_HT(HashT, remo);
            }
        }
        Print_HT(HashT);
        m--;
        count = 0;
    }
    

    return 0;
}