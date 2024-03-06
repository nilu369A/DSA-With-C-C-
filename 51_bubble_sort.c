#include<stdio.h>

int printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}

int bubbleSort(int *A, int n){
    int temp;
    
    for(int i = n; i > 0; i--){  //### 0 ---> (n - 1)
        
        for(int j = 0; j < i - 1; j++){   //### 0 ---> (n - 1 - i)
            
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1]=temp;
                
            }
        }
    }
    printf(" \n");
}

int main(){
    int A[] = {87, 66, 32, 38, 12, 5, 9};
    // int A[] = {1,2,3,4,5,6};
    int n = 7;
    printArray(A,n);
    bubbleSort(A, n);
    printArray(A,n);
    return 0;
}