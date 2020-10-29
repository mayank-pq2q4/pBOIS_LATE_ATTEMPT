#include <stdio.h>

//-----------------------

void heapify(int arr[],int size, int i){

    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<size && arr[left]>arr[max]){
        max = left;
    }
    if(right<size && arr[right]>arr[max]){
        max = right;
    }
    if(max!=i){
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr,size,max);
    }

}

//-----------------------

void buildHeap(int arr[],int size){

    int index = (size/2) - 1;

    for(int i=index;i>=0;i--){
        heapify(arr,size,i);
    }

}

//-----------------------

int maxElement(int arr[],int size){
    int temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = 0;
    size = size-1;
    buildHeap(arr,size);
    return temp;
    
}

//-----------------------

int main(){

    int N;
    printf("Enter the length of the heap : ");
    scanf("%d",&N);
    int heap[N];

    for(int i=0;i<N;i++){
        printf("Enter the elements of the heap : ");
        scanf("%d",&heap[i]);
    }

    buildHeap(heap,N);

    for(int i=0;i<N;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    int x;
    printf("Enter 1 to return max element \n");
    printf("Enter 0 to end program \n");
    scanf("%d",&x);

    while(x!=0){
        if(x==1){
            printf("%d\n",maxElement(heap,N));
            N = N-1;
            for(int i=0;i<N;i++){
                printf("%d ",heap[i]);
            }
        }
        printf("\n");
        scanf("%d",&x);
	
        if(N==0){
            printf("Heap is empty\n");
            x = 0;
        }
    }

    return 0;
}
