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
        }while(!(array[i]<=p || i>=r));//quicksort decrescente
        do{
            j--;
        }while(!(array[j]>=p));
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


int main()
{
    int c;
    scanf("%d", &c);
    for(int i=0;i<c;i++){
        int n;
        scanf("%d", &n);
        int array[n];
        for(int j=0;j<n;j++){
            scanf("%d", &array[j]);
        }
        
        QuickSort(array, 0, n-1);
        
        for(int j=0;j<n;j++){
            printf("%d ", array[j]);
        }
        printf("\n");
    }

    return 0;
}
