#include <iostream>
using namespace std;

int bs_string(string array[], int n, string key){
    int l = 0, r = n-1;
    while(l<=r){
         int m = (l+r)/2;
        if(key == array[m]){
            return m;
        }
        else if(key < array[m]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    
    cin >> n;
    string alunos[n];

    for(int i=0;i<n;i++){
        cin >> alunos[i];
    }

    int q;
    string aluno_desejado;
    cin >> q;

    for(int i=0;i<q;i++){
        cin >> aluno_desejado;
        int result = bs_string(alunos, n, aluno_desejado);

        if(result != -1){
            printf("+\n");
        }
        else{
            printf("-\n");
        }
    }

    return 0;
}
