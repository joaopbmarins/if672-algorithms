#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char value;
    struct Node *next;
}Node;

Node *Create_link(char value, Node *nextval){
    Node *n = (Node *) malloc(sizeof(Node));
    n->next = nextval;
    n->value = value;
    return n;
}

Node *Create_link2(Node *nextval){
    Node *n = (Node *) malloc(sizeof(Node));
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
    List *l = (List *) malloc(sizeof(List));
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
    free(tmp);
    l->length--;
    return value;
}

void Delete_List(List *l){
    Node *tmp = l->head, *next = tmp->next;
    while(tmp->next != NULL){
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(tmp);
    free(l);
}

void Print_list(List *l){
    Node *tmp = l->head;
    while(tmp->next != NULL){
        printf("%c",tmp->next->value);
        tmp = tmp->next;
    }
    if(l->length != 0)
        printf("\n");
}


int main(){

    char frase[100001];

    while(scanf(" %s", frase) != EOF){
        int frase_size = strlen(frase);
        List *lista = Create_list();
        for(int i=0;i<frase_size;i++){
            if(frase[i] == '['){
                MoveToStart(lista);
            }
            else if(frase[i] == ']'){
                MoveToEnd(lista);

            }
            else{
                Insert(lista, frase[i]);
                Next(lista);
            }
        }
        Print_list(lista);
        Delete_List(lista);
    }


    return 0;
}
