#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createnode(int data){
    struct Node * p; // #### creating node pointer
    p = (struct Node *)malloc(sizeof( struct Node)); // ### allocating memory in heap
    p->data = data; // ###setting the data
    p->left = NULL;// #### setting left and right children to NULL
    p->right = NULL;
    return p;
}

void inorder(struct Node * root){
    if(root != NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct Node *search(struct Node *root, int key){
    while(root != NULL){
        if(key == root->data){
            return root;
        }if(key < root->data){
            root = root->left;
        }else{
            root = root-> right;
        }
    }return NULL;

}

struct Node *inorderpredecessor(struct Node *root){
    root= root->left;
    while(root->left != NULL){
        root = root->right;
    }
    return root;
}

struct Node *delet(struct Node *root,  int value){
    struct Node *ipre;
    if(root == NULL){
        return NULL;
    }if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    //###searching for the nood to delet
    if(value < root->data){
        root->left = delet(root->left, value);
    }else if(value > root->data){
        root->right = delet(root->right, value);
    }

    //####deleting the nodde
    else{
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = delet(root->left, ipre->data);
    }
    return root;
}


int main(){
    struct Node * p = createnode(7);
    struct Node * p1 = createnode(5);
    struct Node * p2 = createnode(11);
    struct Node * p3 = createnode(2);
    struct Node * p4 = createnode(6);

    //       7
    //      / \
    //     5   11
    //    / \
    //   2   6

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    inorder(p);
    
    printf("\n");
    delet(p, 5);
    inorder(p);
    
    return 0;
}