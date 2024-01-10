#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define endl "\n"

typedef struct BSTNode{
    int key;
    int element;
    int height;
    int sonsL; 
    int sonsR;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

BSTNode *CreateBSTnode(int k, int e){
    BSTNode *node = new BSTNode;
    node->element = e;
    node->key = k;
    node->left = node->right = NULL;
    node->height = 0;
    node->sonsL = 0;
    node->sonsR = 0;
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

BSTNode *findhelp(BSTNode *rt, int k){
    if(rt == NULL){
        return NULL;//erro arvore nula
    }
    if(rt->key > k){
        return findhelp(rt->left, k);
    }
    else if(rt->key == k){
        return rt;
    }
    else{
        return findhelp(rt->right, k);
    }
}

int SonsL(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    return rt->sonsL;
}

int SonsR(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    return rt->sonsR;
}

BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    rt->sonsL = 
    return l;
}

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
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

int posi = 0;
vector<int> array;
void InOrder(BSTNode *rt, int key, bool &Achou){
    if(rt != NULL && !Achou){
        InOrder(rt->left, key, Achou);
        array.push_back(rt->key);
        if(Achou) return;
        posi++;
        if(rt->key == key){
            Achou = true;
            return;
        }
        InOrder(rt->right, key, Achou);
    }
}



int main(){

    BST *bst = CreateBST();
    int n;
    scanf("%d", &n);
    while(n>0){
        int oper, value;
        scanf("%d %d", &oper, &value);

        if(oper == 1){//insert
            Insert(bst, value, value);
            BSTNode *ptr = findhelp(bst->root, value);
            printf("SonL: %d, SonR: %d, Value: %d\n", ptr->sonsL, ptr->sonsR, ptr->element);
        }

        else if(oper == 2){//find
            bool Achou = false;
            BSTNode *node = findhelp(bst->root, value);
            InOrder(bst->root, value, Achou);
            if(node != NULL){
                
                printf("Value:%d, SonL: %d, SonR: %d, Posi:%d\n", node->element, node->sonsL, node->sonsR, posi);
                /*
                if(posi != node->rank){
                    cout << "algo está errado" << endl;
                }*/
            }
            else{
                cout << "Data tidak ada" << endl;
                for(auto i: array) printf("%d ", i);
                cout << endl;   
            }
            posi = 0;
        }
        array.clear();
        n--;
    }


    return 0;
}
