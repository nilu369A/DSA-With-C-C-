#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

// int isEmpty(struct queue * q){
//     if(q->r == q->f){
//         return 1;
//     }
//     return 0;
// }

// int isFull(struct queue * q){
//     if(q->r == q->size - 1){
//         return 1;
//     }
//     return 0;
    
// }

void enqueue(struct queue* q, int val){
    if((q->r+1)%q->size == q->f){
        printf("This queue is full");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
    
}

int dequeue(struct queue* q){
    int a = -1;
    if(q->r == q->f){
        printf("This queue is empty");
    }else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}


int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size *sizeof(int));

    enqueue(&q, 23);
    enqueue(&q, 12);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Dequeued value is %d\n", dequeue(&q));
    printf("Dequeued value is %d\n", dequeue(&q));
    printf("Dequeued value is %d\n", dequeue(&q));
    
    return 0;
}