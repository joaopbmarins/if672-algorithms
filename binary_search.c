#include <stdio.h>

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


    return 0;
}