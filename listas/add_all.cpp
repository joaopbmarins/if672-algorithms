#include <iostream>
#include <vector>
using namespace std;

void HeapBottomUp(vector<int> &h, int size){//cria a heap
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

void heapify(vector<int> &h, int size, int k){//reorganiza ela
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
        swap(h[1], h[i]);
        size--;
        heapify(h,size,1);
    }
}
int main(){
    int n;
    cin >> n;
    while(n >= 2 && n <= 5000){
        vector<int> vet;
        vet.resize(n+1);
        for(int i=1;i<=n;i++){
            cin >> vet[i];
        }
        HeapBottomUp(vet, vet.size());
        int cost = 0;
        while(n > 1){
            delete_heap(vet, vet.size());
            //for(auto i : vet) cout << i << " ";
            //cout << endl;
            int add = vet[vet.size()-1];
            //printf(" add:%d size:%d\n", add, vet.size());
            vet.pop_back();
            add += vet[vet.size()-1];
            //printf(" add:%d size:%d\n", add, vet.size());
            vet.pop_back();
            cost += add;
            //printf("cost:%d, add:%d, size:%d\n", cost, add, vet.size());
            vet.push_back(add);
            HeapBottomUp(vet, vet.size());
            n--;
        }
        
        cout << cost << endl;
        
        cin >> n;
    }
    




    return 0;
}