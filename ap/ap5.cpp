#include <iostream>
using namespace std;

typedef struct Node{
  int value;
  struct Node *next;
} Node;

Node *Create_link(int value, Node *nextval){
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

void Push(Stack *s, int value){
  s->top = Create_link(value, s->top);
  s->size++;
}

int Pop(Stack *s){
  if(s->top == NULL){
    cout << "Error" << endl;
    return '\0';
  }
  int value = s->top->value;
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

    int c;
    cin >> c;
    string comando;

    for(int i=0;i<c;i++){
        Stack *pilha = Create_Stack();
        cout << "Case " << c << ":" <<  endl;
        bool menu = true;

        while(menu){
          cin >> comando;
           if(comando == "push"){
                int value;
                cin >> value;
                Push(pilha, value);
            }
            else if(comando == "pop"){
                int qtd, soma=0;
                cin >> qtd;
                for(int i=0;i<qtd;i++){
                    soma += pilha->top->value;
                    Pop(pilha);
                }
                cout << soma << endl;
            }
            else if(comando == "end"){
              menu = false;
            }
        }
        
      Delete_Stack(pilha);
    }

  return 0;
}
