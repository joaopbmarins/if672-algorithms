#include <iostream>
#include <vector>
using namespace std;

void HeapBottomUp(vector<int> &h, int size){
    int n = size - 1;
    for(int i=n/2; i>0;i--){
        int k = i;
        int v = h[k];
        bool heap = false;
        while(!heap && 2*k <= n){
            int j = 2*k;
            if(j<n){
                if(h[j] > h[j+1]){
                    j++;
                }
            }
            if(v <= h[j]){
                heap = true;
            }
            else{
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heapify(vector<int> &h, int size, int k){
    bool heap = false;
    int n = size - 1;
    int v = h[k];
    while(!heap && 2*k <= n){
        int j = 2*k;
        if(j<n){
            if(h[j] > h[j+1]){
                j++;
            }
        }
        if(v <= h[j]){
            heap = true;
        }
        else{
            h[k] = h[j];
            k = j;
        }
    }
    h[k] = v;

}

void delete_heap(vector<int> &h, int size){
    for(int i=size-1;i>1;i--){
        for(int i=1;i<size;i++){
            printf("%d ", h[i]);
        }
        cout << endl;
        swap(h[1], h[i]);
        size--;
        heapify(h,size,1);
    }
    for(int i=h.size()-1;i != 0;i--){
        printf("%d ", h[i]);
    }
    printf("\n\n");
}

int main(){

    int c;
    cin >> c;
    for(int i=0;i<c;i++){
        int size;
        cin >> size;
        vector<int> vet;
        vet.resize(size+1);
        for(int j=1;j<size+1;j++){
            cin >> vet[j];
        }
        HeapBottomUp(vet, vet.size());
        delete_heap(vet, vet.size());

    }


    return 0;
}