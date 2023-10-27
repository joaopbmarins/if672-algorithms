#include <stdio.h>

int SequentialSearch2(int *array, int n, int k){
    array[n] = k;
    int i = 0;
    while(array[i]!= k){
        i++;
    }
    if(i<n) return i;
    else return -1;
}


int main(){


    return 0;
}