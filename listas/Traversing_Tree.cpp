#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"

typedef struct BSTNode{
    int key;
    int element;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

BSTNode *CreateBSTnode(int k, int e){
    BSTNode *node = new BSTNode;
    node->element = e;
    node->key = k;
    node->left = node->right = NULL;
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

void PreOrder(BSTNode *rt){
    if(rt != NULL){
        cout << " " << rt->element;
        PreOrder(rt->left);
        PreOrder(rt->right);
    }
}

void InOrder(BSTNode *rt){
    if(rt != NULL){
        InOrder(rt->left);
        cout << " " << rt->element;
        InOrder(rt->right);
    }
}

void PosOrder(BSTNode *rt){
    if(rt != NULL){
        PosOrder(rt->left);
        PosOrder(rt->right);
        cout << " " << rt->element;
    }
}


int main(){

    BST *bst = CreateBST();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        Insert(bst, tmp, tmp);
    }

    cout << "Pre order :";
    PreOrder(bst->root);
    cout << endl;
    cout << "In order  :";
    InOrder(bst->root);
    cout << endl;
    cout << "Post order:";
    PosOrder(bst->root);
    cout << endl;


    return 0;
}