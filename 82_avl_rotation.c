#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max (int a, int b){
    return a>b?a:b;
    
}
int getHeight(struct Node *n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}


struct Node * createnode(int key){
    struct Node *node = (struct Node *)malloc(sizeof( struct Node)); // ### allocating memory in heap
    node->key = key; // ###setting the data
    node->left = NULL;// #### setting left and right children to NULL
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node *n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
  
    //     y                        x
    //    / \      ------->        / \           
    //   x @ T3    left rotate   T1 @ y           @--->rotation
    //  / \         <---------       / \
    // T1  T2    right rotate       T2  T3


struct Node *rightRotate(struct Node *y){///##### Here y is the root node ####
    struct Node *x = y->left;
    struct Node *T2 = y->right;
    
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
}

struct Node *leftRotate(struct Node *x){///##### Here x is the root node ####
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
}

struct Node *insert(struct Node * node, int key){
    
    if(node == NULL){
        return createnode(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key > node->key){
        node->right = insert(node->right, key);
    }
    return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
    
    //left to left case
    if(bf > 1 && key < node->left->key){
        return rightRotate(node);
    }
    //right to right
    if(bf < -1 && key > node->right->key){
        return leftRotate(node);
    }
    //left to right
    if(bf > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //right to left
    if(bf < -1 && key < node->right->key){
        node->right = rightRotate(node->right); 
        return leftRotate(node);
    }
    return node;
}

void preorder(struct Node * root){
    if(root != NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    return 0;
}

