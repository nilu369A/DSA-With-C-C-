#include<stdio.h>

int linear_search(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
    }return -1;
}
int main(){
    int arr[] = {1, 2, 5, 9, 12, 17, 25, 39, 47, 65, 85, 99, 125, 500};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the number : ");
    scanf("%d", &element);
    int search_index = linear_search(arr, size, element);
    if (search_index != -1) {
        printf("%d is at index %d", element, search_index);
        }
    else {
        printf("%d is not in the array", element);
        }
    return 0;
}