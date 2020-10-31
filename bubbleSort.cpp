#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n){
 
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
  
int main(){

    int arr[] = {1,5,2,3,57,7,33,23,14,16};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printArr(arr, n);

    return 0;
}
  