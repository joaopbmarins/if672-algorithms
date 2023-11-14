#include <stdio.h>
#include <string.h>

int bs_string(char array[][31], int n, char key[31]){
    int l = 0, r = n-1;
    while(l<=r){
        int m = (l+r)/2;
        if(strcmp(key, array[m])==0){
            return m;
        }
        else if(strcmp(key, array[m])<0){
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
    
    scanf("%d", &n);
    char alunos[n][31];

    for( int i=0;i<n;i++){
        scanf(" %s\n", alunos[i]);
    }

    int q;
    char aluno_desejado[31];
    scanf("%d", &q);

    for(int i=0;i<q;i++){
        scanf(" %s\n", aluno_desejado);
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
