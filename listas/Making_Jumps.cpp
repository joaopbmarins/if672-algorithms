#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


void travessia(int i, int j, int qtd, int &best, vector<vector<int>> &matriz, vector<vector<bool>> &visitados){
    if(i < 0 || j < 0 || i >= 10 || j >= 10 || matriz.at(i).at(j) == 0 || visitados.at(i).at(j)) return;

    visitados.at(i).at(j) = true;
    qtd++;
    if(qtd > best) best = qtd;

    travessia(i-2, j-1, qtd, best, matriz, visitados); 
    travessia(i-2, j+1, qtd, best, matriz, visitados);
    travessia(i-1, j-2, qtd, best, matriz, visitados);
    travessia(i-1, j+2, qtd, best, matriz, visitados);
    travessia(i+1, j-2, qtd, best, matriz, visitados);
    travessia(i+1, j+2, qtd, best, matriz, visitados);
    travessia(i+2, j-1, qtd, best, matriz, visitados);
    travessia(i+2, j+1, qtd, best, matriz, visitados);

    visitados.at(i).at(j) = false;


    return;
}


int main(){

    vector<vector<int>> matriz;
    matriz.resize(10);
    for(int i=0;i<10;i++){
        matriz.at(i).resize(10,0);
    }

    vector<vector<bool>> visitados;
    visitados.resize(10);
    for(int i=0;i<10;i++){
        visitados.at(i).resize(10, false);
    }

    int size, caso = 0;
    cin >> size;
    while(size != 0){
        caso++;
        int casas_max = 0;
        for(int i=0;i<size;i++){
            int j,k;
            cin >> j >> k;
            for(int a=j;a<k+j;a++){
                matriz.at(i).at(a) = 1;
                casas_max++;
            }
        }

        int qtd=0, best=0;
        travessia(0,0, qtd, best, matriz, visitados);

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                matriz.at(i).at(j) = 0;
            }
        }

        if(casas_max - best == 1){
            printf("Case %d, %d square can not be reached.\n", caso, casas_max - best);
        }
        else{
            printf("Case %d, %d squares can not be reached.\n", caso, casas_max - best);
        }

        cin >> size;
    }

    return 0;
}