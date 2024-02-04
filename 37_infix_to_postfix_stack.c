#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

// ### Top Element ###
int stack_top(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int precedenceof(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }else if(ch =='+' || ch == '-'){
        return 2;
    }else{
        return 0;
    }
}

int isoperator(char ch){
    if(ch == '+' || ch =='-' || ch =='*' || ch == '/' ){
        return 1;
    } 
    else{
        return 0;
    }
}

char* infixtopostfix(char *infix){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size *sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0; //track infix traversal
    int j = 0; //Track postfix traversal

    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }else{
            if(precedenceof(infix[i]) > precedenceof(stack_top(sp))){
                push(sp, infix[i]);
                i++;
            }else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *infix = "a-b+c*d-n/k";
    printf("%s\n",infixtopostfix(infix));
    
    return 0;
}