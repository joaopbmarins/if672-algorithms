#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"

typedef struct BSTNode{
    int key;
    int element;
    int height;
    BSTNode *left;
    BSTNode *right;
}BSTNode;

BSTNode *create_bstnode(int key, int element){
    BSTNode *n = new BSTNode;
    n->key = key;
    n->element = element;
    n->left = n->right = nullptr;
    n->height = 0;
    return n;
}

int h(BSTNode *rt){
    if(rt == nullptr){
        return -1;
    }
    return rt->height;
}

int getBalance(BSTNode *rt){
    if(rt == nullptr){
        return 0;
    }
    return (h(rt->left) - h(rt->right));
}

typedef struct BST{
    BSTNode *root;
    int nodecount;
}BST;

BST *create_bst(){
    BST *bst = new BST;
    bst->root = nullptr;
    bst->nodecount = 0;
    return bst;
}

BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    l->height = 1 + max(h(l->left), h(l->right));
    return l;
}

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    r->height = 1 + max(h(r->left), h(r->right));
    return r;
}

BSTNode *inserthelp(BSTNode *rt, int key, int element){
    if(rt == nullptr){
        return create_bstnode(key, element);
    }
    if(rt->key > key){
        rt->left = inserthelp(rt->left, key, element);
    }
    else{
        rt->right = inserthelp(rt->right, key, element);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if(balance < -1 && key >= rt->right->key){
        return leftRotate(rt);
    }
    if(balance > 1 && key < rt->left->key){
        return rightRotate(rt);
    }
    if(balance > 1 && key >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && key < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

void insert(BST *bst, int key, int element){
    bst->root = inserthelp(bst->root, key, element);
    bst->nodecount++;
}

void preorder(BSTNode *rt){
    if(rt != nullptr){
        cout << rt->element << endl;
        preorder(rt->left);
        preorder(rt->right);
    }
}

int main(){
    int c;
    cin >> c;
    while(c > 0){
        BST *bst = create_bst();
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            insert(bst, tmp, tmp);
        }
        preorder(bst->root);
        cout << "END\n";
        c--;
    }



    return 0;
}
