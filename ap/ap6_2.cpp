#include <iostream>
using namespace std;
#define endl "\n"

int m = 1000;
int Size = m;
int count = 0;

typedef struct{
    string key;
}HT;


int HashFold(string K){
    int s = K.size();
    int sum = 0;
    for(int i=0;i<s;i++){
        sum += K[i];
    }
    return abs(sum)%m;
}

int Search_HS(HT **table, string key){
    int index = HashFold(key);
    for(int i=0;i<m;i++){
        int tmp = (i + index) % m;
        if(table[tmp] == NULL){
            return tmp;
        }
        if(table[tmp] != NULL && table[tmp]->key == key){
            return tmp;
        }
    }
    return -1;
}

void Insert_HS(HT **table, HT *Add){
    int find = Search_HS(table, Add->key);
    if(table[find] == NULL){
        table[find] = Add;
        count++;
        return;
    }
    return;
}

HT *Delete_HS(HT **table, string key){
    int find = Search_HS(table, key);
    if(table[find] != NULL && table[find]->key == key){
        HT *tmp = table[find];
        table[find] = NULL;
        count--;
        return tmp;
    }
    return NULL;
}

int main(){

    HT *HashTable[m] = {NULL};
    cin >> m;
    string comando;
    HT lixo[m];
    int i = 0;

    while(cin >> comando){
        if(comando == "add"){
            cin >> comando;
            lixo[i] = {.key = comando};
            Insert_HS(HashTable, &lixo[i]);
        }
        else if(comando == "rmv"){
            cin >> comando;
            lixo[i] = {.key = comando};
            Delete_HS(HashTable, lixo[i].key);
        }
        else if(comando == "sch"){
            cin >> comando;
            lixo[i] = {.key = comando};
            int find = Search_HS(HashTable, lixo[i].key);
            if(HashTable[find] == NULL)
                find = -1;
            cout << comando << " " << find << endl;
        }
        i++;
    }

    return 0;
}
