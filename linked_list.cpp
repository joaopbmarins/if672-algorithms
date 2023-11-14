#include <iostream>
using namespace std;

typedef struct node{
    char value;
    node *next;

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
    Node *n = Create_link2(NULL);
    l->head = n;
    l->tail = n;
    l->curr = n;
    l->length = 0;
    return l;
}

void Insert(List *l, char value){//conferir se precisar ser um ponteiro a lista
    l->curr->next = Create_link(value, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    } 
    l->length++;
}

void MoveToStart(List *l){
    l->curr = l->head;
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


int main(){




    return 0;
}