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

void insert(struct Node * root, int key){
    struct Node * prev = NULL;
    while(root!= NULL){
        prev = root; 
        if(key == root->data){
            return;
        }
        else if(key < root->data){
            root = root->left;
        }else{
            root = root->right;
        }

    }
    struct Node * new = createnode(key);
    if(key < prev->data){
        prev->left = new;
    }else{
        prev->right = new;
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
    printf("%d\n",isBST(p));
    
    insert(p, 4);
    printf("%d", p->left->left->right->data);
    return 0;
}