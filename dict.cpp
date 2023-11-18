#include <iostream>
#define endl "\n"
using namespace std;

int HashFold(string K, int m){
    int s = K.size();
    int sum = 0;
    for(int i=0;i<s;i++){
        sum += K[i];
    }
    return abs(sum)%m;
}

int HashSFold(string K, int m){
    int intLength = K.size()/4;
    int sum = 0, mult = 1;
    string sub;
    for(int i=0;i<intLength;i++){
        sub = K.substr(i*4, (i*4)+4);
        mult = 1;
        for(int j=0;j<4;j++){
            sum += sub[j] * mult;
            mult *= 256;
        }
    }
    sub = K.substr(intLength * 4);
    mult = 1;
    int s = sub.size();
    for(int j=0;j<s;j++){
        sum += sub[j] * mult;
        mult *= 256;
    }
    return abs(sum)%m;    
}

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

typedef struct Dictionary{
    int m;
    int lenght;
    List **H;
    int (*h) (string, int);

}Dictionary;

Dictionary *Create_Dict(int size, int (*h)(string, int)){
    Dictionary *d = new Dictionary;
    d->m = size;
    d->lenght = 0;
    d->H = new List *[size];
    for(int i=0;i<size;i++){
        d->H[i] = Create_list();
    }
    d->h = h;
    return d;
}

void Insert(Dictionary *d, string k);

int main(){

    Dictionary *d = Create_Dict(10, HashSFold);




    return 0;
}
