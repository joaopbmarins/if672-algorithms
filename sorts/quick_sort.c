#include <stdio.h>

void swap(int *array, int a, int b){
    int aux = array[a];
    array[a] = array[b];
    array[b] = aux;
}

int HoarePartition(int *array,int l,int r){
    int p = array[l];
    int i = l;
    int j = r+1;
    do{
        do{
            i++;
        }while(!(array[i]>=p || i>=r));
        do{
            j--;
        }while(!(array[j]<=p));
        swap(array, i,j);
    } while (!(i>=j));
    swap(array,i,j);
    swap(array,l,j);
    return j;
}

void QuickSort(int *array,int l,int r){
    if(l<r){
        int s = HoarePartition(array, l, r);
        QuickSort(array,l,s-1);
        QuickSort(array,s+1,r);
    }
}

int main(){

    int n = 5;
    int teste[5] = {2,3,1,5,4};

    QuickSort(teste, 0, n-1);
    
    for(int i=0;i<n;i++){
        printf("%d\n", teste[i]);
    }


    return 0;
}