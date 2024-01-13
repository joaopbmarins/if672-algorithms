#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"

typedef struct BSTNode{
    int key;
    int element;
    int height;
    int size;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

BSTNode *CreateBSTnode(int k, int e){
    BSTNode *node = new BSTNode;
    node->element = e;
    node->key = k;
    node->left = node->right = NULL;
    node->height = 0;
    node->size = 1;
    return node;
}

int h(BSTNode *rt){
    if(rt == NULL){
        return -1;
    }
    return rt->height;
}

int getBalance(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    return (h(rt->left) - h(rt->right));
}

typedef struct BST{
    BSTNode *root;
    int node_count;
}BST;

BST *CreateBST(){
    BST *bst = new BST;
    bst->root = NULL;
    bst->node_count = 0;
    return bst;
}

int Size_n(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    return rt->size;
}

int indice = 0;
BSTNode *findhelp(BSTNode *rt, int k){
    if(rt == NULL){
        return NULL;
    }
    if(rt->key > k){
        return findhelp(rt->left, k);
    }
    else if(rt->key == k){
        indice += Size_n(rt->left) + 1;
        return rt;
    }
    else{
        indice += Size_n(rt->left) + 1;
        return findhelp(rt->right, k);
    }
}


BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    rt->size = Size_n(rt->left) + Size_n(rt->right) + 1;
    l->size = Size_n(l->left) + Size_n(l->right) + 1;
    return l;
}

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    rt->size = Size_n(rt->left) + Size_n(rt->right) + 1;
    r->size = Size_n(r->left) + Size_n(r->right) + 1;
    return r;
}

BSTNode *inserthelp(BSTNode *rt, int k, int e){
    if(rt == NULL){       
        return CreateBSTnode(k, e);
    }
    if(rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
    }
    else{
        rt->right = inserthelp(rt->right, k , e);
    }

    rt->size = Size_n(rt->left) + Size_n(rt->right) + 1;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if(balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }
    if(balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }
    if(balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    
    return rt;
}

void Insert(BST *bst, int key, int element){
    bst->root = inserthelp(bst->root, key, element);
    bst->node_count++;
}
 


int main(){

    BST *bst = CreateBST();
    int n;
    scanf("%d", &n);
    while(n>0){
        int oper, value;
        scanf("%d %d", &oper, &value);
        indice = 0;
        if(oper == 1){//insert
            Insert(bst, value, value);
        }
        else if(oper == 2){//find
            BSTNode *node = findhelp(bst->root, value);
            if(node != NULL){
                cout << indice << "\n";
            }
            else{
                cout << "Data tidak ada" << endl;
            }
        }
        n--;
    }


    return 0;
}
