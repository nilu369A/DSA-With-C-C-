#include<stdio.h>

int printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}

void merge(int A[],  int low, int mid, int high){
    int B [high +1];
    int i = low;
    int j = mid+1;
    int k = 0;

    while(i <= mid && j <= high){
        if(A[i] <= A[j]){
            B[k] = A[i];
            i++;        
        }else{
            B[k] = A[j];
            j++;
        } k++;
    }
    while(i <= mid){
        B[k]= A[i];
        i++;k++;
    }
    while(j <= high){
        B[k] = A[j];
        k++;j++;
    }

    for(int i = low; i <= high; i++){
        A[i] = B[i - low];
    }
}

void mergeSort(int A[], int low, int high){
    if(low == high){
        return;
    }
    int mid = (high + low)/2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low,mid, high);
    
    
   
}

int main(){
    int A[] = {87, 6, 32, 38, 12, 5, 9};
    // int A[] = {1,2,3,4,5,6};
    int n = 7;
    printArray(A,n);
    printf("\n");
    mergeSort(A, 0, n-1);
    printArray(A,n);
    return 0;
}