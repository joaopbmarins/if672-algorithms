#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define endl "\n"

typedef struct BSTNode{
    int key;
    int element;
    int height;
    int rank;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

BSTNode *CreateBSTnode(int k, int e){
    BSTNode *node = new BSTNode;
    node->element = e;
    node->key = k;
    node->left = node->right = NULL;
    node->height = 0;
    node->rank = 1;
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

/*
int tmp = 1;
void RankHelp(BSTNode *rt){
    if(rt->left == NULL){
        return;
    }
    else{
        tmp++;
        RankHelp(rt->left);
    }
    if(rt->right == NULL){
        return;
    }
    else{
        tmp++;
        RankHelp(rt->right);
    }
}

void Rank(BSTNode *rt){
    tmp = 1;
    if(rt->left != NULL){
        tmp++;
        RankHelp(rt->left);
    }
    else if(rt->right != NULL){
        tmp++;
        RankHelp(rt->right);
    }
}*/

int Rank(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    return rt->rank;
}

BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    rt->rank= Rank(rt->left) + Rank(rt->right) +1;
    l->rank = Rank(l->left) + Rank(l->right) +1;
    return l;
}

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    rt->rank= Rank(rt->left) + Rank(rt->right) +1;//
    r->rank = Rank(r->left) + Rank(r->right) +1;  //Rank(rt) +1;//Rank(r->left) + Rank(r->right)
    return r;
}

BSTNode *inserthelp(BSTNode *rt, int k, int e){
    if(rt == NULL){
        return CreateBSTnode(k, e);
    }
    if(rt->key > k){
        rt->rank = Rank(rt) +1;//toda vez q eu navego para esquerda preciso adicionar um no rank
        rt->left = inserthelp(rt->left, k, e);
    }
    else{
        rt->right = inserthelp(rt->right, k , e);
    }

    //rt->rank = Rank(rt) +1;//+ Rank(rt->right) 

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

void InOrder(BSTNode *rt, int key, bool &Achou){
    if(rt != NULL && !Achou){
        InOrder(rt->left, key, Achou);
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
        }

        else if(oper == 2){//find
            bool Achou = false;
            BSTNode *node = findhelp(bst->root, value);
            if(node != NULL){
                InOrder(bst->root, value, Achou);
                //cout << posi << endl;
                cout << node->rank << endl;
                if(posi != node->rank){
                    cout << "algo está errado" << endl;
                }
            }
            else{
                cout << "Data tidak ada" << endl;
            }
            posi = 0;
        }
        n--;
    }


    return 0;
}
