#include <iostream>
using namespace std;

/*
Transform the Expression SPOJ - ONP 
https://vjudge.net/problem/SPOJ-ONP

Questão de monitoria de stack e não de lista ou ep
*/

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

    int n; cin >> n;

    for(int i=0;i<n;i++){
        Stack *pilha = Create_Stack();
        Stack *operador = Create_Stack();
        string expr;
        cin >> expr;

        for(int j=expr.size()-1;j>=0;j--){
            Push(pilha, expr[j]);
        }
        char car;
        int size = pilha->size;
        for(int j=0;j<size;j++){
            car = Pop(pilha);
            if(car == '(' || car == ')'){
                if(car == ')'){
                    cout << Pop(operador);
                }
                          
            }
            else if(car == '+' || car == '-'  || car == '*' || car == '/' || car == '^'){
                Push(operador, car);
            }
            else{
                cout << car;
            }
        }

        Delete_Stack(pilha);
        Delete_Stack(operador);
        cout << "\n";
    }


  return 0;
}