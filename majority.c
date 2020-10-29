#include <stdio.h>
#include <math.h>

//-----------------------

int partition(int arr[], int left, int right){

    //int range = (right - left + 1);
    int range = (right - left);
    int pivot_index = left + (rand() % range);
    if(pivot_index == 0){
        pivot_index += 1;
    }

    int pivot_element = arr[pivot_index];
    
    while ( left < right )
    {
        while ( arr[left] < pivot_element )
            left++;
        
        while ( arr[right] > pivot_element )
            right--;
        
        if ( arr[left] == arr[right] )
            left++;
        else if ( left < right ) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    return right;
}

//-----------------------

int quick_select(int arr[], int left, int right, int k)
{
    if ( left == right ) 
        return arr[left];
    
    int pivot_index = partition(arr, left, right);
    int length = (pivot_index - left + 1);
    
    if (length == k) 
        return arr[pivot_index];
    else if ( k < length ) 
        return quick_select(arr, left, (pivot_index - 1), k);
    else  
        return quick_select(arr, (pivot_index + 1), right, (k - length));
}

//-----------------------

int main(){

    int arr[] = {1,5,5,4,5,5,7,8,5};
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    int x = quick_select(arr,l,r,(r/2)+1);

    for(int i=0;i<r;i++){
        if(arr[i] == x){
            count ++;
        }
    }

    if(count > r/2){
        printf("Majority element is %d\n",x);
    }
    else{
        printf("No majority element.");
    }

    return 0;
}
