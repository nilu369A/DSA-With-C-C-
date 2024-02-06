#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue * q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue * q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
    
}

void enqueue(struct queue* q, int val){
    if(isFull(q)){
        printf("This queue is full");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
    
}

int dequeue(struct queue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is empty");
    }else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}


int main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size *sizeof(int));


    enqueue(&q, 23);
    enqueue(&q, 12);
    enqueue(&q, 3);

    printf("Dequeued value is %d", dequeue(&q));
    if(isEmpty(&q)){
        printf("Queue is empty");
    }
    if(isFull(&q)){
        printf("Queue is full");
    }

    return 0;
}