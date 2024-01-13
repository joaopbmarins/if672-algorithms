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

void remove_heap(vector <int> &h){
    int last_elem = h.size() - 1;
    swap(h[1], h[last_elem]);
    h.pop_back();
    heapify(h, h.size(), 1);

}

void HeapTopDown(vector<int> &h, int add){
    h.push_back(add);
    int size = h.size();
    int s = size-1;
    int d = s/2;
    while(h[d] > h[s] && s > 1){
        swap(h[d], h[s]);
        s = d;
        d = s/2;
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
        HeapBottomUp(vet, n+1);
        int cost = 0;
        while(n > 1){
            int add = vet[1];
            remove_heap(vet);
            add += vet[1];
            remove_heap(vet);
            cost += add;
            HeapTopDown(vet, add);
            n--;
        }
        
        cout << cost << endl;
        
        cin >> n;
    }
    
    return 0;
}