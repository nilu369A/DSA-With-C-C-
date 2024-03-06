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

int isBST(struct Node * root){
    static struct Node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return(isBST(root->right));
    }
    else{
        return 1;
    }
    
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
    printf("%d",isBST(p));
    return 0;
}