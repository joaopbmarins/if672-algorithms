#include <iostream>
using namespace std;

typedef struct Node{
    char value;
    struct Node *next;
}Node;

Node *Create_link(char value, Node *nextval){
    Node *n = new Node;
    n->next = nextval;
    n->value = value;
    return n;
}

Node *Create_link2(Node *nextval){
    Node *n = new Node;
    n->next = nextval;
    return n;
}

typedef struct{
    Node *head;
    Node *tail;
    Node *curr;
    int length;
}List;

List *Create_list(){
    List *l = new List;
    l->head = l->tail = l->curr = Create_link2(NULL);
    l->length = 0;
    return l;
}

void Insert(List *l, char value){
    l->curr->next = Create_link(value, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    } 
    l->length++;
}

void MoveToStart(List *l){
    l->curr = l->head;
}

void MoveToEnd(List *l){
    l->curr = l->tail;
}

void Prev(List *l){
    if(l->curr == l->head){
        return;
    }
    Node *temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}

void Next(List *l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

char Remove(List *l){
    if(l->curr->next == NULL){
        return '\0';//return NULL
    }
    char value = l->curr->next->value;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->length--;
    return value;
}
//invencao minha e o moveToEnd tbm mas acontece
void Delete_List(List *l){
    Node *tmp = l->head, *next = tmp->next;
    while(tmp->next != NULL){
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    delete tmp;
    delete l;
}

int main(){
    
    int c, n;
    cin >> c;
    string comando;
    
    for(int i=0;i<c;i++){
        cin >> n;
        List *lista = Create_list();
        
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
                Node *tmp = lista->head->next;

                for(int i=0;i<lista->length;i++){
                    if(tmp->value == value){
                        count++;
                    }
                    tmp = tmp->next;
                }
                
                cout << count << endl;
            }
        
        }    
        Delete_List(lista);
    }

    

    return 0;
}