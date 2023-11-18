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

typedef struct Stack{
  struct Node *top; 
  int size;
}Stack;

Stack *Create_Stack(){
  Stack *s = new Stack;
  s->top = NULL;
  s->size = 0;
  return s;
}

void Push(Stack *s, char value){
  s->top = Create_link(value, s->top);
  s->size++;
}

char Pop(Stack *s){
  if(s->top == NULL){
    cout << "Error" << endl;
    return '\0';
  }
  char value = s->top->value;
  Node *tmp = s->top;
  s->top = s->top->next;
  delete tmp;
  s->size--;
  return value;
}

void Delete_Stack(Stack *s){
    for(int i=0;i<s->size;i++){
        Pop(s);
    }
    delete s->top;
    delete s;
}

int main (){

    Stack *pilha = Create_Stack();

    Push(pilha, '1');
    Push(pilha, '2');
    Push(pilha, '3');

    cout << pilha->top->value << endl;

    Delete_Stack(pilha);



  return 0;
}