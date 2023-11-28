#include <iostream>
#include <vector>
using namespace std;

int Size = 10;
int count = 0;

int Hash(int k){
    return k % 10;
}

void Insert_HS(vector<int> **Table, int key){
    int index = Hash(key);
    if(Table[index] == NULL){
        Table[index] = new vector<int>;
        Table[index]->push_back(key);
        count++;
        return;
    }
    else if(Table[index] != NULL){
        Table[index]->push_back(key);
        return;
    }
    return;
}

vector<int> *Busca(vector<int> **table, int k){
    int index = Hash(k);
    return table[index];
}



int main(){
    int m = 10;
    vector<int> *HT[m] = {NULL};
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int key;
        cin >> key;
        Insert_HS(HT, key);
    }

    for(int i=0;i<Size;i++){
        cout << i << " ";
        vector<int> *tmp = Busca(HT, i+1);
        for(int j=0;j<tmp->size();j++){
            cout << tmp->at(j) << " ";
        }
        cout << endl;

    }



    return 0;
}
