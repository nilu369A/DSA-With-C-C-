#include<stdio.h>

int printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}

int insertionSort(int *A, int n){
    int temp;
    // int key, j
    for(int i = 1; i < n; i++){  //### 0 ---> (n - 1)
        
        for(int j = i - 1; j >= 0; j--){   //### 0 ---> (n - 1 - i)
            
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1]=temp;
                
            }

            //  ####
            //key = A[i];
            // j = i - 1;
            // while(j >= 0 && A[j] > key){
            //     A[j+1] = A[j];
            //     j--;
            // }
            // A[j+1]= key; #### //

        }
    }
    printf(" \n");
}

int main(){
    int A[] = {87, 66, 32, 38, 12, 5, 9};
    // int A[] = {1,2,3,4,5,6};
    int n = 7;
    printArray(A,n);
    insertionSort(A, n);
    printArray(A,n);
    return 0;
}