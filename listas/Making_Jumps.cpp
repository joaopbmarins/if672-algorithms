#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int best = 0;
void travessia(int i, int j, int qtd, vector<vector<int>> &matriz, vector<vector<bool>> &visitados){
    if(i < 0 || j < 0 || i >= 10 || j >= 10 || matriz.at(i).at(j) == 0 || visitados.at(i).at(j)) return;

    visitados.at(i).at(j) = true;
    qtd++;
    if(qtd > best) best = qtd;

    //(r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1)

    travessia(i-2, j-1, qtd, matriz, visitados); 
    travessia(i-2, j+1, qtd, matriz, visitados);
    travessia(i-1, j-2, qtd, matriz, visitados);
    travessia(i-1, j+2, qtd, matriz, visitados);
    travessia(i+1, j-2, qtd, matriz, visitados);
    travessia(i+1, j+2, qtd, matriz, visitados);
    travessia(i+2, j-1, qtd, matriz, visitados);
    travessia(i+2, j+1, qtd, matriz, visitados);

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

        int qtd=0;
        travessia(0,0, qtd, matriz, visitados);

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                matriz.at(i).at(j) = 0;
            }
        }

        char quadrado_fdp[10];

        if(casas_max - best == 1){
            stpcpy(quadrado_fdp, "square");
        }
        else{
            stpcpy(quadrado_fdp, "squares");
        }

        printf("Case %d, %d %s can not be reached.\n", caso, casas_max - best, quadrado_fdp);
        best = 0;
        cin >> size;
    }

    return 0;
}