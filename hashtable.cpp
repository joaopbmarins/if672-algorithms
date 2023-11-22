#include <iostream>
#include <list>
using namespace std;


int HashFold(string K, int m){
    int s = K.size();
    int sum = 0;
    for(int i=0;i<s;i++){
        sum += K[i];
    }
    return abs(sum)%m;
}

int HashSFold(string K, int m){
    int intLength = K.size()/4;
    int sum = 0, mult = 1;
    string sub;
    for(int i=0;i<intLength;i++){
        sub = K.substr(i*4, (i*4)+4);
        mult = 1;
        for(int j=0;j<4;j++){
            sum += sub[j] * mult;
            mult *= 256;
        }
    }
    sub = K.substr(intLength * 4);
    mult = 1;
    int s = sub.size();
    for(int j=0;j<s;j++){
        sum += sub[j] * mult;
        mult *= 256;
    }
    return abs(sum)%m;    
}

typedef struct Set{
    string key;
    string content;
}Set;


int main(){
    int m = 1000;
    list<Set> HashTable[m];

    Set dados = {"JoaoPedro","Eu gosto de batata doce"};

    int index = HashSFold("JoaoPedro", m);

    
    HashTable[index].push_back(dados); 


    cout << HashTable[index].front().content << endl;
    

    return 0;
}