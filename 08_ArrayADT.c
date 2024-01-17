#include<stdio.h>
#include<stdlib.h>
// Structure ## Used to create custom data type

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray* a, int tSize, int uSize){ ///Here myArray is a pointer so it will accept only a n address
    (*a).total_size = tSize;
    a->used_size = uSize; //Arrow function
    (*a).ptr = (int *)malloc(tSize*sizeof(int)); //Size of the memory block is tSize ##ptr of the structure is set equal to this memory block
}
void setValue(struct myArray *a){
    int n;
    
    for (int i = 0; i < a->used_size; i++){
        printf("Enter  the value: ");
        scanf("%d\n", &n);
        (a->ptr)[i] = n;
    }
}
void show(struct myArray *a){
    
    for (int i = 0; i < a->used_size; i++){
        printf("The entered values is: ");
        printf("%d\n", (a->ptr)[i]);
    }
}


int main(){
    struct myArray marks; //Marks is a structure variable of the structure
    createArray(&marks, 10, 4); //Giving an address
    setValue(&marks);   
    show(&marks);
    return 0;
}