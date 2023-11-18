#include <iostream>
#define endl "\n"
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

int main(){


    cout << HashFold("ALGORITHMS", 1000) << endl;

    cout << HashSFold("ALGORITHMS", 1000) << endl;


    return 0;
}
