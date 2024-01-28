#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

struct Node * top = NULL; // ###Top variavle of structurre is a global variable now ###

void linkedlistTraversal(struct Node * ptr){
    while(ptr != NULL){
         printf("%d\n", ptr->data); 
         ptr = ptr->next;
    }
   
}

int isEmpty(struct Node * ptr){
    if(ptr == NULL){
        return 1;
    }else{
        return 0;
    }
    
}

int isFull(struct Node * ptr){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }else{
        return 0;
    }
    
}

struct Node * push(struct Node * top, int x){
    if(isFull(top)){
        printf("Stack overlow\n");
    }else{
        struct Node * p = (struct Node *)malloc(sizeof(struct Node));
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
}

int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack underflow\n");
    }else{
        struct Node * p = tp;
        top = tp->next;
        int x = p->data;
        free(p);
        return x;
    }
}

int peek(int pos){
    struct Node * ptr = top;
    for(int i = 0; ( i < pos - 1 && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;

    }else{
        return -1;
    }
}

int stack_top(struct Node * ptr){
    return top->data;
}

int main(){
    
    top = push(top, 12);
    top = push(top, 333);
    top = push(top, 44);
    top = push(top, 99);
   
    linkedlistTraversal(top);
    // int element = pop(top);
    // printf("Popped Element is:%d\n", element);
    // linkedlistTraversal(top);

    for(int i = 0; i  < 4; i++){
        printf("The element in %d position is: %d\n", i+1, peek(i+1));
    }
    printf("%d\n", stack_top(top));

    return 0;
}