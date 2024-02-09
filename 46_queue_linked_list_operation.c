#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node *f = NULL;
struct Node *r =NULL; 

void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Elements: %d\n", ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("This queue is full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f=r=n;
        }else{
            r->next = n;
            r=n;
        }
    }
    
}

int dequeue(){
    int a = -1;
    struct Node * ptr = f;
    if(f==NULL){
        printf("This queue is empty");
    }else{
        f = f->next;
        a=ptr->data; 
        free(ptr);
    }
    return a;
}


int main(){
     
    printf("Dequeued value is %d\n", dequeue());
    enqueue(23);
    enqueue( 12);
    enqueue( 3);
    enqueue( 4);
    
    linkedListTraversal(f);
    
    printf("Dequeued value is %d\n", dequeue());
    printf("Dequeued value is %d\n", dequeue());
    printf("Dequeued value is %d\n", dequeue());
    enqueue(100);
    
    linkedListTraversal(f);
    
    return 0;
}