#include <stdio.h>

int binary_search(int *array, int n, int k){
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

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d ", &array[i]);
    }
    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int v;
        scanf("%d",&v);
        
        int resul = binary_search(array, n, v);
        
        if(resul != -1){
            printf("%d\n", resul);
        }
        else{
            printf("x\n");
        }
    }

    return 0;
}
