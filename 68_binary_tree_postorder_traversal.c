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

void postorder(struct Node * root){
    if(root != NULL){
        
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct Node * p = createnode(2);
    struct Node * p1 = createnode(4);
    struct Node * p2 = createnode(11);
    struct Node * p3 = createnode(9);
    struct Node * p4 = createnode(6);

    //       2
    //      / \
    //     4   11
    //    / \
    //   9   6

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    postorder(p);
    return 0;
}