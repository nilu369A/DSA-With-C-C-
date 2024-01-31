#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr, char data){
    if(isFull(ptr)){
        printf("Stack overflow\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]= data;
        
    }
}

// ### Pop Element ###
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow\n");
        return -1;
    }else{
        char data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
    
}

int match(char a, char b){
    if(a=='{' && b =='}'){
        return 1;
    }else if(a=='[' && b ==']'){
        return 1;
    }
    else if(a=='(' && b ==')'){
        return 1;
    }return 0;
}

int parenthesisMathChq(char * exp){
    //create and initialize the the stack
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_char;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i] == '{' || exp[i] == '['){
            push(sp, exp[i]);
        }else if(exp[i] == ')' || exp[i] == '{' || exp[i] == '['){
            if(isEmpty(sp)){
                return 0;
            }
            popped_char = pop(sp);
            if(!match(exp[i], popped_char)){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    
    char * exp = "[7+(7(+5)})]";
    if(parenthesisMathChq(exp)){
        printf("Matching");
    }else{
        printf("Not Matchhing");
    }
    return 0;
}