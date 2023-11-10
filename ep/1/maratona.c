#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[31];
    int tempo;
} maratona;

void merge(maratona array[], int l, int r){
    maratona temp[l+r+1];
    for(int i=l;i<=r;i++){
        temp[i] = array[i];
    }
    int m = (l+r)/2;
    int i1 = l, i2 = m+1;
    for(int curr=l;curr<=r;curr++){
        if(i1==m+1){
            array[curr] = temp[i2];
            i2++;
        }
        else if(i2 > r){
            array[curr] = temp[i1];
            i1++;
        }
        else if(temp[i1].tempo <= temp[i2].tempo){
            array[curr] = temp[i1];
            i1++;
        }
        else{
            array[curr] = temp[i2];
            i2++;
        }
    }    
}

void mergesort(maratona array[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l , r);
    }
}



int main(){

    int c;
    scanf("%d", &c);

    maratona pessoas[c];

    for(int i=0;i<c;i++){
        scanf(" %s %d\n", pessoas[i].nome, &pessoas[i].tempo);
    }

    mergesort(pessoas, 0, c-1);

    for(int i = 0;i<c;i++){
        printf("%s %d\n", pessoas[i].nome, pessoas[i].tempo);
    }


    return 0;
}
