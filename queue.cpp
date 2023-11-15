#include <iostream>
using namespace std;

typedef struct Node{
  char value;
  struct Node *next;
} Node;

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

typedef struct Queue{
    struct Node *front;
    struct Node *rear;
    int size;
}Queue;

Queue *Create_Queue(){
    Queue *q = new Queue;
    q->front = q->rear = Create_link2(NULL);
    q->size = 0;
    return q;
}

void Enqueue(Queue *q, char value){
    q->rear->next = Create_link(value, NULL);
    q->rear = q->rear->next;
    q->size++;
}

char Dequeue(Queue *q){
    if(q->size == 0){
        cout << "Error" << endl;
        return '\0';
    }
    
    Node *tmp = q->front->next;
    char value = q->front->next->value;

    q->front->next = q->front->next->next;
    if(q->front->next == NULL){
        q->rear = q->front;
    }
    q->size--;
    delete tmp;
    return value;
}

void Delete_Queue(Queue *q){
    for(int i=0;i<q->size;i++){
        Dequeue(q);
    }
    delete q->front;
    delete q->rear;
    delete q;
}

int main(){

    Queue *fila = Create_Queue();

    Enqueue(fila, '1');
    Enqueue(fila, '2');
    Enqueue(fila, '3');

    cout << fila->front->next->value << endl;
    cout << fila->rear->value << endl;

    Dequeue(fila);

    cout << fila->front->next->value << endl;
    cout << fila->rear->value << endl;


    Delete_Queue(fila);


    return 0;
}