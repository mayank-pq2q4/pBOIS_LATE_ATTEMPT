#include <stdio.h>

struct pair {
	int min,max;
};

typedef struct pair pair;

pair findMinAndMax(int arr[], int low, int high, int min, int max){

	pair mm;

	if (low == high){

        mm.min = arr[low];
        mm.max = arr[high];

		return mm;
	}

	if (high - low == 1){

		if (arr[low] > arr[high]){

				mm.max = arr[low];
				mm.min = arr[high];
		}
		else{

				mm.max = arr[high];
				mm.min = arr[low];
		}
		return mm;
	}

	int mid = (low + high) / 2;
	pair mml = findMinAndMax(arr, low, mid, min, max);
	pair mmr = findMinAndMax(arr, mid + 1, high, min, max);

	if (mml.min < mmr.min) 
    	mm.min = mml.min; 
  	else
    	mm.min = mmr.min;      
  
	if (mml.max > mmr.max) 
    	mm.max = mml.max; 
  	else
    	mm.max = mmr.max;      
   
  return mm; 

}


int main(){

	int arr[] = {188,54,36,235,75,13,93,35,64,346,27,75,36,8,286,45,12};
	int n = sizeof(arr) / sizeof(arr[0]);

	int max = arr[0];
    int min = arr[0];

	pair minmax = findMinAndMax(arr, 0, n - 1, min, max);

	printf("The minimum element in the array is %d\n",minmax.min);
	printf("The maximum element in the array is %d\n",minmax.max);

	return 0;
}