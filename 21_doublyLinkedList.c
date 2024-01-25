#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

void doublylistTraversal(struct Node * ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data); 
        ptr = ptr->next;
    }
   
}

int main(){
    
    struct Node * n1;//Decleared head node
    struct Node * n2; 
    struct Node * n3; 
    struct Node * n4; 


    //Allocate memory for node in heap
    n1 = (struct Node *)malloc(sizeof(struct Node));
    n2 = (struct Node *)malloc(sizeof(struct Node));
    n3 = (struct Node *)malloc(sizeof(struct Node));
    n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->previous = NULL;
    n1->data = 2;
    n1->next = n2;
    
    n2->previous = n1;
    n2->data = 4;
    n2->next = n3;
    
    n3->previous = n2;
    n3->data = 6;
    n3->next = n4;
    
    n4->previous = n3;
    n4->data = 8;
    n4->next = NULL;

    doublylistTraversal(n1);

    return 0;
}