#include<stdio.h>
#define MAX_SIZE 10

int deque[MAX_SIZE];
int f = -1, r = -1;

void insert_at_front(int val){
    if((f== 0 && r == MAX_SIZE-1)||(f==r+1)){
        printf("DEqueue is full");
        return;
    }
    if(f==-1){
        f=r=0;
    }else if(f == 0){
        f = MAX_SIZE - 1;
    }else{
        f = f - 1;
    }
    deque[f] = val;
}

void insert_at_rear(int val){
    if((f== 0 && r == MAX_SIZE-1)||(f==r+1)){
        printf("DEqueue is full");
    }
    if(r==f){
        f=r=0;
    }else if(f == 0){
        f = MAX_SIZE - 1;
    }else{
        r = f + 1;
    }
    deque[r] = val;
}

void display(){
    
    if(f==-1){
        printf("DEqueue is empty");
    return;
    }
    else if(r>=f){
        for(int i = f; i <= r; i++){
            printf("%d\n", deque[i]);
        }
    }
    
}


int main(){

    insert_at_front(23);
    insert_at_front(44);
    insert_at_front(90);
    

    display();

    return 0;
}