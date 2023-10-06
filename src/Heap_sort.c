#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define swap(x,y)   do{typeof(x) t;t=x;x=y;y=t;}while(0)

void MaxHeapify(int *A, int i, int heap_size);
int BuildMaxHeap(int *A, int length);
void HeapSort(int *A,int length);
void printarr(int *A, int length);//,int length

int main(){
    int arr[] = {2,4,5,7,1,2,3,6};
    // int arr[] = {4,3,1};
    int arr_length = sizeof(arr)/sizeof(arr[0]);

    printf("Original:\n");
    printarr(arr,sizeof(arr)/sizeof(arr[0]));

    float start = clock();
    HeapSort(arr,arr_length); // 
    float end = clock();

    printf("\nSorted:\n");
    printarr(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\nOperation Time: %.5fs\n", (end-start)/CLOCKS_PER_SEC);

}

void HeapSort(int *A, int length){
    int heap_size;
    heap_size = BuildMaxHeap(A,length);
    printf("\n");
    printarr(A,length);
    for (int i=length-1;i>=1;--i){
        swap(A[0],A[i]);
        heap_size -=1;
        MaxHeapify(A,1,heap_size);
        printf("\n");
        printarr(A,length);  
    }
}

void MaxHeapify(int *A, int i, int heap_size){
    int l,r,largest;
    l = 2*i+1;
    r = 2*i+2;
    if (l<=heap_size && A[l]>A[i]) largest = l;
    else largest = i;
    if (r<=heap_size && A[r]>A[largest]) largest = r;
    if (largest != i){
        swap(A[i],A[largest]);
        MaxHeapify(A,largest,heap_size);
    }
}

int BuildMaxHeap(int *A, int length){
    int heap_size = length-1;
    for(int i=floor(length/2)-1;i>=0;--i) MaxHeapify(A,i,heap_size);
    return heap_size;
}

void printarr(int *A, int length){ //, int length
    for(int i=0;i<length;++i){
        printf("%d\t",A[i]);
    }
}