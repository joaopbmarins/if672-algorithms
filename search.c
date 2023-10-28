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

    int array[5] = {0,11,35,62,71};

    printf("%d\n",binary_search(array,5,1));

    int array_2[5] = {0,62,35,71,11};

    printf("%d\n", SequentialSearch2(array_2, 5, 11));

    return 0;
}