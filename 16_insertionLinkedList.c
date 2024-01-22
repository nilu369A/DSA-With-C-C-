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

// ### At First ###
struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// ### At Index ###
struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}


// ### At Last ###
struct Node * insertAtLast(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

// ### After Node ###
struct Node * insertAfterNode(struct Node * head,struct Node * previousNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = previousNode->next;
    previousNode->next = ptr;
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
    
    // head = insertAtFirst(head, 99);
    // head = insertAtIndex(head, 99, 2);
    // head = insertAtLast(head, 99);
    head = insertAfterNode(head,second, 99);

    printf("List after Insertion\n");

    linkedlistTraversal( head);
    
    return 0;
}