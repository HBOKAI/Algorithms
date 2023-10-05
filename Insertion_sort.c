#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int *A, int length);
void printarr(int *A, int length);//,int length

int main(){
    int arr[] = {3,2,4,5,7,1,2,3,6};
    int arr_length = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original:\n");
    printarr(arr,sizeof(arr)/sizeof(arr[0]));

    float start = clock();
    InsertionSort(arr,arr_length); // InsertionSort(address_of_array, length of array)
    float end = clock();

    printf("\nSorted:\n");
    printarr(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\nOperation Time: %.5f", (end-start)/CLOCKS_PER_SEC);
}

void printarr(int *A, int length){ //, int length
    for(int i=0;i<length;++i){
        printf("%d\t",A[i]);
    }
}

void InsertionSort(int *A, int length){
    int key, i, j;
    for(j=1;j<length;++j){
        key = A[j];
        i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}