#include<stdio.h>

int printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}

int selectionSort(int *A, int n){
    int temp;
    
    for(int i = 0; i < n - 1; i++){  //### 0 ---> (n - 1)
        int min = i;
        for(int j = i; j < n; j++){   //### 0 ---> (n - 1 - i)
            
            if(A[j] < A[min]){
                min = j;
                
            }
            
            temp = A[min];
            A[min] = A[i];
            A[i]=temp;
        }
    }
    printf(" \n");
}

int main(){
    int A[] = {87, 6, 32, 38, 12, 5, 9};
    // int A[] = {1,2,3,4,5,6};
    int n = 7;
    printArray(A,n);
    selectionSort(A, n);
    printArray(A,n);
    return 0;
}