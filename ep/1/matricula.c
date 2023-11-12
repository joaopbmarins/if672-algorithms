#include <stdio.h>
#include <string.h>

 int bs_string(char array[][31],  int n, char key[31]){
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

void merge(char array[][31],  int l,  int r){
    char temp[l+r+1][31];
    for( int i=l;i<=r;i++){
        strcpy(temp[i], array[i]);
    }
     int m = (l+r)/2;
     int i1 = l, i2 = m+1;
    for( int curr=l;curr<=r;curr++){
        if(i1==m+1){
            strcpy(array[curr], temp[i2]);
            i2++;
        }
        else if(i2 > r){
            strcpy(array[curr], temp[i1]);
            i1++;
        }
        else if(strcmp(temp[i1], temp[i2])<=0){
            strcpy(array[curr], temp[i1]);
            i1++;
        }
        else{
            strcpy(array[curr], temp[i2]);
            i2++;
        }
    }    
}

void mergesort(char array[][31],  int l,  int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l , r);
    }
}


int main(){
     int n;
    
    scanf("%d", &n);
    char alunos[n][31];

    for( int i=0;i<n;i++){
        scanf(" %s\n", alunos[i]);
    }

    //mergesort(alunos, 0 , n-1);

     int q;
    char aluno_desejado[31];
    scanf("%d", &q);

    for( int i=0;i<q;i++){
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
