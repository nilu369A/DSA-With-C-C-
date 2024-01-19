#include<stdio.h>
int binary_search(int arr[], int size, int element){
    int high = size - 1, low = 0, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] ==element){
            return mid;
        }else if(arr[mid] < element){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;

}
int main(){
    int arr[] = {1, 2, 5, 9, 12, 17, 25, 39, 47, 65, 85, 99, 125, 500};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the number : ");
    scanf("%d", &element);
    int search_index = binary_search(arr, size, element);
    if (search_index != -1) {
        printf("%d is at index %d", element, search_index);
        }
    else {
        printf("%d is not in the array", element);
        }
    return 0;
}