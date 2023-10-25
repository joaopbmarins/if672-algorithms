#include <stdio.h>

void swap(int *array, int a, int b){
    int aux = array[a];
    array[a] = array[b];
    array[b] = aux;
}

void selection_sort(int *array, int n){
    int min;
    for(int i=0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        swap(array, i, min);
    }
}

void bubble_sort(int *array, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(array[j]> array[j+1])
                swap(array, j, j+1);
        }
    }
}

void insertion_sort(int *array, int n){
    for(int i=0;i<n;i++){
        int v = array[i];
        int j = i-1;
        while(j>=0 && array[j]>v){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = v;
    }
}

int main(){

    int n = 5;
    int teste[5] = {2,3,1,5,4};
    
    //bubble_sort(teste, n);
    //insertion_sort(teste, n);
    //selection_sort(teste, n);

    for(int i=0;i<5;i++){
        printf("%d\n", teste[i]);
    }

    return 0;
}