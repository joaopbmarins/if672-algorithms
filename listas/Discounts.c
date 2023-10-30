#include <stdio.h>

void swap(long long int *array, long long int a, long long int b){
    long long int aux = array[a];
    array[a] = array[b];
    array[b] = aux;
}

long long int HoarePartition(long long int *array,long long int l,long long int r){
    long long int p = array[l];
    long long int i = l;
    long long int j = r+1;
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

void QuickSort(long long int *array,long long int l,long long int r){
    if(l<r){
        long long int s = HoarePartition(array, l, r);
        QuickSort(array,l,s-1);
        QuickSort(array,s+1,r);
    }
}

int main(){
    long long int n, m, total=0;
    scanf("%lld", &n);

    long long int chocolate[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld ", &chocolate[i]);
        total += chocolate[i];
    }
    scanf("%lld", &m);

    long long int cupom[m];
    for(long long int i=0;i<m;i++){
        scanf("%lld ", &cupom[i]);
    }

    QuickSort(chocolate, 0, n-1);

    for(long long int i=0;i<m;i++){
        long long int dinheiro_gasto = total;
        long long int a = n - cupom[i];

        dinheiro_gasto -= chocolate[a];
       
        printf("%lld\n", dinheiro_gasto);
    }

    
    return 0;
}