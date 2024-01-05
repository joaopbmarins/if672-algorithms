#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define endl "\n"

typedef struct BSTNode{
    int key;
    int element;
    int height;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

BSTNode *CreateBSTnode(int k, int e){
    BSTNode *node = new BSTNode;
    node->element = e;
    node->key = k;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

BSTNode *getmin(BSTNode *rt){
    if(rt->left == NULL){
        return rt;
    }
    return getmin(rt->left);
}

BSTNode *deletemin(BSTNode *rt){
    if(rt->left == NULL){
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
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

int findhelp(BSTNode *rt, int k){
    if(rt == NULL){
        return -1;//erro arvore nula
    }
    if(rt->key > k){
        return findhelp(rt->left, k);
    }
    else if(rt->key == k){
        return rt->element;
    }
    else{
        return findhelp(rt->right, k);
    }
}

int Find(BST *bst, int k){
    return findhelp(bst->root, k);
}

BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
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

BSTNode *removehelp(BSTNode *rt, int k){
    if(rt == NULL){
        return NULL;
    }
    if(rt->key > k){
        rt->left = removehelp(rt->left, k);
    }
    else if(rt->key < k){
        rt->right = removehelp(rt->right, k);
    }
    else{
        if(rt->left == NULL){
            return rt->right;
        }
        else if(rt->right == NULL){
            return rt->left;
        }
        else{
            BSTNode *tmp = getmin(rt->right);
            rt->element = tmp->element;
            rt->key = tmp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

int Remove(BST *bst, int key){
    int tmp = findhelp(bst->root, key);
    if(tmp != -1){//teste para dizer se a busca funcionou
        bst->root = removehelp(bst->root, key);
        bst->node_count--;
    }
    return tmp;
}

int posi = 0;
//vector<int> array;

void InOrder(BSTNode *rt, int key, bool &Achou){
    if(rt != NULL && !Achou){
        InOrder(rt->left, key, Achou);
        posi++;
        //array.push_back(rt->key);
        if(rt->key == key){
            Achou = true;
            cout << posi << endl;
            return;
        }
        InOrder(rt->right, key, Achou);
    }
}


int main(){

    BST *bst = CreateBST();
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int oper, value;
        scanf("%d %d", &oper, &value);
        if(oper == 1){//insert
            Insert(bst, value, value);
        }
        else if(oper == 2){//find
            bool Achou = false;
            InOrder(bst->root, value, Achou);
            //remover dps
            //for(auto i: array) cout << i << " ";
            //cout << endl;
            //array.clear();
            //
            if(!Achou){
                cout << "Data tidak ada" << endl;
            }
            posi = 0;
        }
    }
    

    return 0;
}
