#include<stdio.h>

void display(int arr[], int n){
    // Traversal
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}
int indeletion(int arr[], int size, int index){
    for(int i = index; i < size - 1; i++){
        arr[i]= arr[i+1];
    }
}
int main(){
    int arr[100] = {2,3,4,5,6,7,8,9,11};
    int index = 3, size = 9;
    int n;
    printf("Before deletion");
    display(arr, size);
    indeletion(arr, size, index);
    size--;
    printf("After deletion");
    display(arr, size);
    return 0;
}