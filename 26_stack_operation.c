#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

// ### Check If Empty ###
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

// ### Check If Full ###
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

// ### Push Element ###
void push(struct stack *ptr, int data){
    if(isFull(ptr)){
        printf("Stack overflow\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]= data;
        
    }
}

// ### Pop Element ###
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow\n");
        return -1;
    }else{
        int data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
    
}

// ### Peek Element ###
int peek (struct stack *ptr, int position){
    int arrayInd = ptr->top - position + 1;
    if(arrayInd < 0){
        printf("Not a valid pposition in stack\n");
    }else{
        return ptr->arr[arrayInd];
    }
}

// ### Top Element ###
int top(struct stack *ptr){
    return ptr->arr[ptr->top];
}

// ### Buttom Element ###
int buttom(struct stack *ptr){
    return ptr->arr[0];
}


int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); 
    s->size = 8;
    s->top  =  -1;
    s->arr = (int *)malloc(s->size * sizeof(int)); 

    // if(isEmpty(s)){
    //     printf("The stack is empty");
    // }else{
    //     printf("Stack is not empty");
    // }
    printf("Stack has been created successfully\n");

    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    push(s, 778);
    push(s, 789);
    push(s, 7890);
    push(s, 8);
    push(s, 70008);
    push(s, 98);
    push(s, 9998);
    push(s, 89);
    push(s, 812);
    push(s, 123);
    push(s, 58);
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));


    printf("popped %d from the stack", pop(s));
    for(int i = 0; i <= s-> top + 1; i++){
        printf("The value at position %d is %d \n", i, peek(s, i)); 

    }

    printf("Top element is: %d\n", top(s));
    printf("Buttom element is: %d\n", buttom(s));
    
    return 0;
}