#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

// ### Traversal ###
void circularlistTraversal(struct Node * head){
    struct Node *ptr = head;
    do{
        printf("%d\n", ptr->data); 
        ptr = ptr->next;
    }while(ptr != head);
}
 
// ### Insert At First ###
struct Node* insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node*));
    struct Node * p = head->next;
    ptr->data = data;
    while(p-> next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    forth->next = head;


    circularlistTraversal(head);
    head = insertAtFirst(head, 90);
    circularlistTraversal(head);

    return 0;
}