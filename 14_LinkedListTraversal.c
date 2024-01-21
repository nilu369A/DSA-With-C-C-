#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

void linkedlistTraversal(struct Node * ptr){
    while(ptr != NULL){
         printf("%d\n", ptr->data); 
         ptr = ptr->next;
    }
   
}

int main(){
    struct Node * head;//Decleared head node
    struct Node * second; 
    struct Node * third; 
    struct Node * forth; 


    //Allocate memory for node in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second node
    head->data = 7;
    head->next = second;
    
    //Link second and third node
    second->data = 9;
    second->next = third;
    
    //Link third and forth node
    third->data = 123;
    third->next = forth;

    //Terminate the list after third node
    forth->data = 564;
    forth->next = NULL;



    linkedlistTraversal( head);
    return 0;
}