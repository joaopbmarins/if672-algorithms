#include <iostream>
using namespace std;

typedef struct{
    int maxSize;
    int listSize;
    int curr;
    char *listArray;
}List;

List *Create_list(int size){
    List *l = new List;
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = new char[size];
    return l;
}

void Insert(List *l, char value){
    if(l->listSize >= l->maxSize){
        cout << "Error\n";
        return;
    }
    int i= l->listSize;
    while(i>l->curr){
        l->listArray[i] = l->listArray[i-1];
        i--;
    }
    l->listArray[l->curr] = value;
    l->listSize++;
}

void MoveToStart(List *l){
    l->curr = 0;
}

void MoveToEnd(List *l){
    l->curr = l->listSize;
}

void Prev(List *l){
    if(l->curr != 0){
        l->curr--;
    }
}

void Next(List *l){
    if(l->curr < l->listSize){
        l->curr++;
    }
}

char Remove(List *l){
    if(l->curr < 0 || l->curr >= l->listSize){
        return '\0'; //return NULL
    }
    char value = l->listArray[l->curr];
    int i = l->curr;
    while(i<l->listSize){
        l->listArray[i] = l->listArray[i+1];
        i++;
    }
    l->listSize--;
    return value;
}
//criado por mim
void Delete_List(List *l){
    delete[] l->listArray;
    delete l;
}

int main(){
    
    int c, n;
    cin >> c;
    string comando;
    
    for(int i=0;i<c;i++){
        cin >> n;
        List *lista = Create_list(n);
        
        cout << "Case " << c << ":" <<  endl;
        
        for(int i=0;i<n;i++){
            cin >> comando;
            if(comando == "insert"){
                int value;
                cin >> value;
                Insert(lista, value);
            }
            else if(comando == "remove"){
                Remove(lista);
            }
            else if(comando == "prev"){
                Prev(lista);
            }
            else if(comando == "next"){
                Next(lista);
            }
            else if(comando == "count"){
                int value, count=0;
                cin >> value;
                
                for(int i=0;i<lista->listSize;i++){
                    if(lista->listArray[i] == value){
                        count++;
                    }
                }
                cout << count << endl;
            }
        
        }    
        Delete_List(lista);
    }


    return 0;
}