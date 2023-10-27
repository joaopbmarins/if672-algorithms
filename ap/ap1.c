#include <stdio.h>

void merge(int *left, int L, int *right, int R, int *array){
    int i=0, j=0, k=0;
    while(i<L && j<R){
        if(left[i]<=right[j]){
            array[k] = left[i];
            i++;
        }
        else{
            array[k] = right[j];
            j++;
        }
        k++;
    }
    if(i==L){
        for(int p=j;p<R;p++){
            array[k] = right[p];
            k++;
        }
    }
    else{
        for(int p=i;p<L;p++){
            array[k] = left[p];
            k++;
        }
    }
}

void merge_sort(int *array, int n){
    int m1 = n/2;
    int m2 = n - m1;
    int left[m1], right[m2];

    if(n>1){
        for(int i=0;i<m1;i++){
            left[i] = array[i];
        }
        for(int j=0;j<m2;j++){
            right[j] = array[j+m1];
        }
        merge_sort(left, m1);
        merge_sort(right, m2);
        merge(left, m1, right, m2, array);
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
        
        merge_sort(array,n);
        
        for(int j=0;j<n;j++){
            printf("%d ", array[j]);
        }
        printf("\n");
    }

    return 0;
}
