#include <iostream>
#include <queue>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    while(casos>0){
        queue<pair<int,int>> fila;
        int num_students;
        cin >> num_students;

        for(int i=0;i<num_students;i++){
            pair<int,int> tmp;
            cin >> tmp.first >> tmp.second;
            fila.push(tmp);
        }
        int tempo=0;
        for(int i=0;i<num_students;i++){
            if(tempo < fila.front().second){
                tempo = max(tempo+1, fila.front().first);
                cout << tempo << " ";
            }
            else{
                cout << "0 ";
            }
            fila.pop();
            
        }
        cout << "\n";
        
        casos--;
    }



    return 0;
}