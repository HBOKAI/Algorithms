#include <stdio.h>
#include <stdlib.h> // for system("pause")
#define index_init 0
#define index_last 7


void MergeSort(int *A, int p,int r);
void Merge(int *A, int p, int q, int r);
void printarr(int *A, int length);//,int length


int main(){
    int arr[] = {2,4,5,7,1,2,3,6};    

    printf("Original:\n");
    printarr(arr,sizeof(arr)/sizeof(arr[0]));

    MergeSort(arr,0,7); // MergeSort(array, first_index, last_index)

    printf("\nSorted: (from index %d to %d)\n",index_init,index_last);
    printarr(arr,sizeof(arr)/sizeof(arr[0]));
}

void printarr(int *A, int length){ //, int length
    for(int i=0;i<length;++i){
        printf("%d\t",A[i]);
    }
}

void MergeSort(int *A, int p, int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void Merge(int *A, int p, int q, int r){
    int n1,n2,*L,*R,i,j;
    n1 = q-p+1;
    n2 = r-q;
    L = malloc((n1+1)*sizeof(int));
    R = malloc((n2+1)*sizeof(int));
    
    for(i=0;i<=n1;++i) L[i] = A[p+i];
    for(j=0;j<=n2;++j) R[j] = A[q+j+1];
    
    L[n1] = 10000;
    R[n2] = 10000;

    i=0;j=0;
    for(int k=p;k<=r;++k){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);

}