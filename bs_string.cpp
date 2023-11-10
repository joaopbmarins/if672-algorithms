#include <iostream>
using namespace std;

int bs_string(string array[], int n, string key){
    int l=0, r = n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(key == array[m]){
            return m;
        }
        else if(key < array[m]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return -1;
}

void merge(string array[], int l, int r){
    string temp[l+r+1];
    for(int i=l;i<=r;i++){
        temp[i] = array[i];
    }
    int m = (l+r)/2;
    int i1 = l, i2 = m+1;
    for(int curr=l;curr<=r;curr++){
        if(i1 == m+1){
            array[curr] = temp[i2];
            i2++;
        }
        else if(i2 > r){
            array[curr] = temp[i1];
            i1++;
        }
        else if(temp[i1] <= temp[i2]){
            array[curr] = temp[i1];
            i1++;
        }
        else{
            array[curr] = temp[i2];
            i2++;
        }
    }
}

void mergesort(string array[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l , r);
    }
}

int main(){

    string vetor[5];

    vetor[0] =  "joao";
    vetor[1] = "vitor";
    vetor[2] = "rafael";
    vetor[3] = "pedro";
    vetor[4] = "ana";

    mergesort(vetor, 0, 5-1);

    for(int i=0;i<5;i++){
        cout << vetor[i] << endl;
    }

    cout << "indice: " << bs_string(vetor, 5,  "ana") << endl;
    

    return 0;
}