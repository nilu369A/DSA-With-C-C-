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

// ### Delet First ###
struct Node *deletFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// ### At Index ###
struct Node *deletAtIndex(struct Node * head, int index){
    struct Node * ptr = head;
    struct Node * p = head->next;
    for( int i = 0; i< index - 1; i++){
        ptr = ptr->next;
        p = p-> next;
    }
    ptr -> next = p->next;
    free(p);
    return head;
}

// ### Delet Last ###
struct Node *deletLast(struct Node * head){
    struct Node * ptr = head;
    struct Node * p = head->next;
    while(p->next != NULL){
        ptr = ptr->next;
        p = p->next; 
    }
    ptr -> next = NULL;
    free(p);
    return head;
}

// ### Delet Value ###
struct Node *deletValue(struct Node * head, int value){
    struct Node * ptr = head;
    struct Node * p = head->next;
    while(p->data != value && p->next != NULL){
        ptr = ptr->next;
        p = p->next;
    }
    if(p->data == value){
        ptr->next = p->next;
        free(p);
    }
    
    return head;
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
    
    // head = deletFirst(head);
    // head = deletAtIndex(head, 2);
    // head = deletLast(head);
    head = deletValue(head, 123);
    
    printf("List after deletion: \n");
    linkedlistTraversal( head);


    return 0;
}