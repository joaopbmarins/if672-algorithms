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

int binary_search(int *array, int n, int k){//sorted array
    int l=0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(k == array[mid]) 
            return mid;
        else if(k < array[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}


int main(){

    int n,k;
    scanf("%d %d", &n, &k);
    int array[n];

    for(int i=0;i<n;i++){
        scanf("%d ", &array[i]);
    }

    QuickSort(array, 0, n-1);
    
    int count = 0, teste;
    for(int i=0;i<n;i++){
        teste = array[i] - k;
        int busca_binaria = binary_search(array, n, teste);
        if(busca_binaria != -1 && busca_binaria != i){
            count++;
            //printf("!%d %d!\n", array[i], teste);
        }
    }


    printf("%d\n", count);


    return 0;
}