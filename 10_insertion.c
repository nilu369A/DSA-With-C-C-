#include<stdio.h>


void display(int arr[], int n){
    // Traversal
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}

//Void because ## this function only update the array
//Int ##to confirm if the insertion is successfull
int indinsertion(int arr[], int size, int element, int capacity, int index){

    if(size >= capacity){
        return -1;
    }
    for(int i = size - 1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index]= element;
    return 1;

}


int main(){
    int arr[100] = {23,23,323,23, 12313, 23};
    int size = 6, element = 99, capacity = 100, index = 3;
    display(arr, size);
    indinsertion(arr, size, element, capacity, index);
    size++;
    display(arr, size);
    return 0;
}