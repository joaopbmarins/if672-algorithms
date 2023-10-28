#include <stdio.h>

void merge(int *array, int l, int r){
    int temp[l+r+1];
    for(int i=l;i<=r;i++){
        temp[i] = array[i];
    }
    int mid = (l+r)/2;
    int i1 = l, i2 = mid+1;
    for(int curr=l;curr<=r;curr++){
        if(i1==(mid+1)){
            array[curr] = temp[i2++];
        }
        else if(i2>r){
            array[curr] = temp[i1++];
        }
        else if(temp[i1] <= temp[i2]){
            array[curr] = temp[i1++];
        }
        else{
            array[curr] = temp[i2++];
        }
    }
}

void merge_sort(int *array, int l, int r){
    int mid = (l+r)/2;
    if(l<r){
        merge_sort(array, l, mid);
        merge_sort(array,mid+1, r);
        merge(array, l, r);
    }
}



int main(){

    int n = 5;
    int teste[5] = {5,2,1,7,0};

    merge_sort(teste, 0, n-1);
    
    for(int i=0;i<n;i++){
        printf("%d\n", teste[i]);
    }

    return 0;
}