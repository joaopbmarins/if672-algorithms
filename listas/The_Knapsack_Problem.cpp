#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int Knapsack(int n, int w, pair<int,int> itens[], vector<vector<int>> &matriz){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i == 0 || j == 0){
                matriz[i][j] = 0;
            }
            else if(itens[i].first <= j){
                matriz[i][j] = max(matriz[i-1][j], itens[i].second + matriz[i-1][j - itens[i].first]);
            }
            else{
                matriz[i][j] = matriz[i-1][j];
            }
        }
    }
    return matriz[n][w];
}

int MFKnapsack(int i, int j, pair<int,int> itens[], vector<vector<int>> &matriz){

    if(matriz.at(i).at(j) < 0){
        int value;
        if(j < itens[i].first){
            value = MFKnapsack(i-1,j, itens, matriz);
        }
        else{
            value = max(MFKnapsack(i-1, j, itens, matriz), itens[i].second + MFKnapsack(i-1, (j - itens[i].first), itens, matriz));
        }
        matriz.at(i).at(j) = value;
    }
    return matriz.at(i).at(j);
}

int main(){

    int size, n_item;
    cin >> size >> n_item;
    pair<int,int> itens[n_item+1];
    itens[0] = {0,0};
    for(int i=1;i<=n_item;i++){
        int wt, value;
        cin >> wt >> value;
        itens[i] = {wt,value};
    }
    
    vector<vector<int>> matriz;
    matriz.resize(n_item+1);
    for(int i=0;i<n_item+1;i++){
        matriz[i].resize(size+1);
        for(int j=0;j<size+1;j++){
            if(i == 0 || j == 0) matriz.at(i).at(j) = 0;
            else matriz.at(i).at(j) = -1;

        }
    }

    cout << MFKnapsack(n_item, size, itens, matriz) << endl;

    return 0;

}