#include <iostream>
using namespace std;
#define endl "\n"

/*
HashTable Questao da monitoria
Closed Hashing PseudoRandom Probing

*/

typedef struct Pessoa{
    string nome;
    string cpf;
}Pessoa;

int count = 0;

int Hash(string key, int n){
    int sum = 0;
    for(int i=0;i<key.size();i++){
        sum += key[i] - '0';
    }
    return abs(sum) % n;
}

int Find_HT(Pessoa **table, int n, string key, int perm[]){
    int index = Hash(key, n);
    if(table[index] != NULL && table[index]->cpf == key){
        return index;
    }
    int tmp = index;
    for(int i=0;i<n-1;i++){
        tmp = (index + perm[i]) % n;
        if(table[tmp] != NULL && table[tmp]->cpf == key){
            return tmp;
        }
    }
    return -1; 
}

void Add_HT(Pessoa **table, int n, Pessoa *add, int perm[]){
    int index = Hash(add->cpf, n);
    if(Find_HT(table, n, add->cpf, perm) != -1){
        return;
    }
    if(table[index] == NULL){
        table[index] = add;
        count++;
        return;
    }
    int tmp = index;
    for(int i=0;i<n-1;i++){
        tmp = (index + perm[i]) % n;
        if(table[tmp] == NULL){
            table[tmp] = add;
            count++;
            return;
        }
    }
    return;
}

void Remove_HT(Pessoa **table, int n, string key, int perm[]){
    int index = Find_HT(table, n, key, perm);
    if(index != -1){
        table[index] = NULL;
        return;
    }
    return;
}

void Print_HT(Pessoa **table, int n){
    for(int i=0;i<n;i++){
        cout << i << ".\t";
        if(table[i] == NULL){
            cout << "----" << endl;
        }
        else{
            cout << table[i]->nome << " " << table[i]->cpf << endl;
        }
    }
}

int main(){

    int n;
    cin >> n;
    int perm[n-1];
    for(int i=0;i<n-1;i++){
        cin >> perm[i];
    }
    Pessoa *HashTable[n] = {NULL};

    int c; cin >> c;
    Pessoa lixo[c];
    string comando;
    for(int i=0;i<c;i++){
        cin >> comando;
        Print_HT(HashTable, n);
        cout << endl;
        if(comando == "add"){
            cin >> lixo[i].nome;
            cin >> lixo[i].cpf;
            Add_HT(HashTable, n, &lixo[i], perm);
        }
        else if(comando == "find"){
            string key;
            cin >> key;
            int result = Find_HT(HashTable, n, key, perm);
            if(result != -1){
                cout << HashTable[result]->nome << " " << result << endl;
            }
            else{
                cout << result << endl;
            }
        }
        else if(comando == "rmv"){
            string key;
            cin >> key;
            Remove_HT(HashTable, n, key, perm);
        }
    }

    cout << endl;

    Print_HT(HashTable, n);



    return 0;
}