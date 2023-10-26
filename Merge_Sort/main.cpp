#include <iostream>
#include <vector>

//merge two subarrays a1 and a2 into arr
void merge(int* arr, int l, int mid, int r){

	//creating n1 -> A[l...mid] and n2 -> A[mid+1...r]
	int n1 = mid - l + 1;
	int n2 = r - mid;

	std::vector<int> a1(n1);
	std::vector<int> a2(n2);

	for(int i = 0; i < n1; ++i){
		a1[i] = arr[l + i];
	}
	for(int i = 0; i < n2; ++i){
		a2[i] = arr[mid + 1 + i];
	}

	//maintain current index of subarrays and main array
	int x = 0;
	int y = 0;
	int z = l;

	//until we reach either end of a1 or a2 , pick among elements a1 and a2 and place them int the correct position at A[l...r]
	while(x < n1 && y < n2){
		if(a1[x] <= a2[y]){
			arr[z] = a1[x];
			x++;
		}else{
			arr[z] = a2[y];
			y++;
		}
		z++;
	}	

	//when we run out of elements in either a1 or a2, pick up the remaining elements and put in A[l...r]
	while(x < n1){
		arr[z] = a1[x];
		z++;
		x++;
	}
	while(y < n2){
		arr[z] = a2[y];
		z++;
		y++;
	}		
}

//divide the array into subarrays, sort them and merge them
void mergeSort(int* arr, int l, int r){
	if(l < r){
		int mid = (l + r)/2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);

		//Merge the soted array array
		merge(arr, l, mid, r);
	}
}

//print sorted array
void printArray(int* arr, int size){
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {7, 3, 4, 1, 0, 10};
	int size = sizeof(arr)/sizeof(arr[0]);

	mergeSort(arr, 0, size - 1);

	std::cout << "sorted array: " << std::endl;
	printArray(arr, size);

	return 0;
}
