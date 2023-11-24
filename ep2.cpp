#include <iostream>
using namespace std;
#define endl "\n"

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *Create_link(int value, Node *next){
    Node *n = new Node;
    n->next = next;
    n->value = value;
    return n;
}

typedef struct Stack{
    Node *top;
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
        cout << "error\n";
        return -1;
    }
    Node *tmp = s->top;
    int value = s->top->value;
    s->top = s->top->next;
    s->size--;
    delete tmp;
    return value;
}

void ClearStack(Stack *s){
    while(s->size > 0){
        Pop(s);
    }
}

void DeleteStack(Stack *s){
    while(s->size > 0){
        Pop(s);
    }
    delete s->top;
    delete s;
}

int main(){

    string expr;
    Stack *s = Create_Stack();

    while(cin >> expr){
        if(expr[0] >= '0' && expr[0] <= '9'){
            Push(s, stoi(expr));
        }
        else if((expr[0] == '+' || expr[0] == '-' || expr[0] == '*') && expr.size() == 1){
            int v1, v2;
            v1 = Pop(s);
            v2 = Pop(s);
            if(expr[0] == '+'){
                Push(s, v2+v1);
            }
            else if(expr[0] == '-'){
                Push(s, v2-v1);
            }
            else if(expr[0] == '*'){
                Push(s, v2*v1);
            }
            
        }
        else if(expr == "END"){
            cout << Pop(s) << endl;
            ClearStack(s);
        }
        else if(expr == "EOF"){
            break;
        }
        else if(expr.size() != 1){
            Push(s, stoi(expr.substr(1,3)) * -1);
        }
    }


    DeleteStack(s);

    return 0;
}