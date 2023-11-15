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
    Node *tmp = l->curr->next;
    char value = l->curr->next->value;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    delete tmp;
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

void Print_list(List *l){
    Node *tmp = l->head;
    while(tmp->next != NULL){
        cout << tmp->next->value << endl;
        tmp = tmp->next;
    }
}


int main(){

    List *lista = Create_list();

    Insert (lista, '1');
    Insert (lista, '2');
    Insert (lista, '3');

    Print_list(lista);

    Delete_List(lista);



    return 0;
}