#include<stdio.h>

int printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}

int partition(int A[],  int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;

    do{
        while(A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }if(i < j){
            int tmp = A[i];
            A[i]= A[j];
            A[j] = tmp;
        }
    }while(i < j);

    int tmp = A[low];
    A[low] = A[j];
    A[j] = tmp;
    
    return j;
}

int quickSort(int A[], int low, int high){
    int partitionIndx;
    
    if(low < high){
    partitionIndx  = partition(A, low, high);
    quickSort(A, low, partitionIndx - 1);
    quickSort(A, partitionIndx+1, high);
    }
   
}

int main(){
    int A[] = {87, 66, 32, 38, 12, 5, 9};
    // int A[] = {1,2,3,4,5,6};
    int n = 7;
    int m = 0;
    printArray(A,n);
    printf("\n");
    quickSort(A, m, n - 1);
    printArray(A,n);
    return 0;
}