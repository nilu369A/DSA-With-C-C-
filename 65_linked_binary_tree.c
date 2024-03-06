#include<stdio.h>
#include<stdlib.h>

struct Node (){
    int data;
    struct Node * left;
    struct Node * right;
}

struct Node * createnode(int data){
    struct Node * p; // #### creating node pointer
    p = (struct Node *)malloc(sizeof( struct Node)); // ### allocating memory in heap
    p->data = data; // ###setting the data
    p->left = NULL;// #### setting left and right children to NULL
    p->right = NULL;
    return p;
}

int main(){
    struct Node * p = createnode(2);
    struct Node * p1 = createnode(4);
    struct Node * p2 = createnode(11);

    p->left = p1;
    p->right = p2;
    
    return 0;
}