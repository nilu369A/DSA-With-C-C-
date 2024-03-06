#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}

int maximum(int A[], int n){
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++){
        if(maxx < A[i]){
            maxx = A[i];
        }
    }
    return maxx;
}
void countSort(int A[], int n){
    int i, j;
    int max = maximum(A,n);
    int * count = (int * )malloc((max+1)* sizeof(int));
    
    for( i = 0; i < max+1; i++){
        count[i] = 0;
    }

    for( i = 0; i < n; i++){
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0; j = 0;
    while(i <= max){
        if(count[i] > 0){
            A[j] = i;
            count[i] = count[A[i]] - 1;
            j++;
        }else{
            i++;
        }
    }


}

int main(){
    int A[] = {87, 6, 32, 38, 12, 5, 9}; 
    int n = 7;
    printArray(A,n);
    printf("\n");
    countSort(A,n);
    printArray(A,n);
    return 0;
}