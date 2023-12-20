#include <stdio.h>
#include <string.h>

int bs_string(char array[][20], int n, const char key[20]){
    int l=0, r = n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(strcmp(key, array[m]) == 0){
            return m;
        }
        else if(strcmp(key, array[m]) < 0){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return -1;
}

void merge(char array[][20], int l, int r){
    char temp[l+r+1][20];
    for(int i=l;i<=r;i++){
        strcpy(temp[i], array[i]);
    }
    int m = (l+r)/2;
    int i1 = l, i2 = m+1;
    for(int curr=l;curr<=r;curr++){
        if(i1 == m+1){
            strcpy(array[curr], temp[i2]);
            i2++;
        }
        else if(i2 > r){
            strcpy(array[curr], temp[i1]);
            i1++;
        }
        else if(strcmp(temp[i1], temp[i2]) <= 0){
            strcpy(array[curr], temp[i1]);
            i1++;
        }
        else{
            strcpy(array[curr], temp[i2]);
            i2++;
        }
    }
}

void mergesort(char array[][20], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l , r);
    }
}

int main(){

    char vetor[5][20];

    strcpy(vetor[0], "joao");
    strcpy(vetor[1], "vitor");
    strcpy(vetor[2], "rafael");
    strcpy(vetor[3], "pedro");
    strcpy(vetor[4], "ana");

    mergesort(vetor, 0, 5-1);

    for(int i=0;i<5;i++){
        printf("%s\n", vetor[i]);
    }

    printf("indice: %d\n", bs_string(vetor, 5,  "ana"));
    



    return 0;
}