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
                if(h[j]< h[j+1]){
                    j++;
                }
            }
            if(v >= h[j]){
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
                if(h[j]< h[j+1]){
                    j++;
                }
            }
            if(v >= h[j]){
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

void HeapTopDown(vector<int> &h, int add){
    h.push_back(add);
    int size = h.size();
    int s = size-1;
    int d = s/2;
    while(h[d] < h[s] && s > 1){
        swap(h[d], h[s]);
        s = d;
        d = s/2;
    }

}


int main(){

    vector<int> teste = {-1, 2,9,7,6,5,8,10};
    //int add = 10;
    HeapBottomUp(teste, teste.size());
    //HeapTopDown(teste, add);

    delete_heap(teste, teste.size());

    for(int i=1;i<teste.size();i++){
        printf("%d ", teste[i]);
    }

    
    cout << endl;


    return 0;
}
