#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int row, columns, avoid_o;
bool deu_bom = false;

bool travessia(int i, int j, int avoid, vector<vector<char>> &matriz, vector<vector<bool>> &visitados){
    if(i < 0 || j < 0 || i >= row || j >= columns || matriz.at(i).at(j) == '#' || visitados.at(i).at(j)) return false;

    //cout << matriz.at(i).at(j) << endl;
    visitados.at(i).at(j) = true; 


    if(matriz.at(i).at(j) == 's') avoid--;
    if(matriz.at(i).at(j) == 'x' && avoid_o - ((avoid_o - avoid)*2 ) >= 0 ){deu_bom = true ;return true;}

    if(travessia(i+1, j, avoid, matriz, visitados));
    if(travessia(i-1, j, avoid, matriz, visitados));
    if(travessia(i, j+1, avoid, matriz, visitados));
    if(travessia(i, j-1, avoid, matriz, visitados));

    return false;
}


int main(){

    cin >> row >> columns >> avoid_o;

    pair <int, int> jarmtin_pos;
    pair <int, int> treasure_pos;

    vector<vector<char>> matriz;
    vector<vector<bool>> visitados;
    matriz.resize(row);
    visitados.resize(row);
    for(int i=0;i<row;i++){
        matriz.at(i).resize(columns);
        visitados.at(i).resize(columns, false);
        for(int j=0;j<columns;j++){
            char tmp;
            cin >> tmp;
            matriz.at(i).at(j) = tmp;
            if(tmp == '@') jarmtin_pos = {i,j};
            if(tmp == 'x') treasure_pos = {i,j};
        }
    }

    int avoid_tmp = avoid_o;

    travessia(jarmtin_pos.first, jarmtin_pos.second, avoid_tmp, matriz, visitados);

    
    if(deu_bom)
        cout << "SUCCESS\n";
    else
        cout << "IMPOSSIBLE\n";


    /*
    for(auto i : matriz){//imprime matriz
        for(auto j : i){
            cout << j;
        }
        cout << endl;
    }
    */

    //cout << jarmtin_pos.first << " " << jarmtin_pos.second << endl;
    //cout << treasure_pos.first << " " << treasure_pos.second << endl;

    return 0;
}
