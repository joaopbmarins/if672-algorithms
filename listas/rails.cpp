#include <iostream>
using namespace std;
#define endl "\n"

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

void Clear_Stack(Stack *s){
    while(s->size > 0){
        Pop(s);
    }
}

void Delete_Stack(Stack *s){
    for(int i=0;i<s->size;i++){
        Pop(s);
    }
    delete s->top;
    delete s;
}

int main (){

    int n;
    
    while(cin >> n){
        if(n == 0){
            break;
        }
        int vetor[n];
        bool corno = true;
        Stack *s = Create_Stack();
        while(corno){
            int index = 0;
                for(int i=0;i<n;i++){
                    cin >> vetor[i];
                    if(vetor[i] == 0){
                        corno = false;
                        break;
                }
            }
            for(int i=1;i<=n && corno;i++){
                Push(s, i);
                while(s->size > 0 && s->top->value == vetor[index]){
                    Pop(s);
                    index++;
                }
            }
            if(s->size == 0 && corno){
                cout << "Yes" << endl;
            }
            else if(corno){
                cout << "No" << endl;
                Clear_Stack(s);
            }
        }
        Clear_Stack(s);
        cout << endl;
        Delete_Stack(s);
        

    }
    
    return 0;
}
