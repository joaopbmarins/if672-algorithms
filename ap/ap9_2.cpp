#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<char> &h, int size, int k){
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

void delete_heap(vector<char> &h, int size){
    for(int i=size-1;i>1;i--){
        swap(h[1], h[i]);
        size--;
        heapify(h,size,1);
    }
}


void HeapTopDown(vector<char> &h, char add){
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

    int n,m;
    cin >> n;
    cin >> m;
    vector<char> vet;
    vet.push_back('\0');
    int size = 0;
    for(int i=0;i<m;i++){
        string comando;
        cin >> comando;
        
        if(comando == "insert"){
            if(size < n){
                char add;
                cin >> add;
                size++;
                HeapTopDown(vet, add);
            }
            else{
                cout << "Tamanho máximo atingido!\n";
            }
            
        }
        else if(comando == "max"){
            if(size > 0){
                printf("%c\n", vet[1]);
            }
            else{
                printf("Não há elemento no topo.\n");
            }
        }
        else if(comando == "remove"){
            if(size > 0){
                swap(vet[1], vet[size]);
                size--;
                heapify(vet,size,1);

            }
            else{
                cout << "Heap vazia.\n";
            }
        }
    }

    return 0;
}