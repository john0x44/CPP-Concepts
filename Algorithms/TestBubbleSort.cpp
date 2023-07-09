/*
	Name: TestBubbleSort
	Copyright: 2023
	Author: John
	Date: 21/06/23 17:01
	Description: Implementing and testing bubble sort 
*/
#include <iostream>
using namespace std;

// Bubble sort
void bubSort(int arr[], int size){
	bool swap;
	int temp;
	do{
		swap = false;
		for(int i = 0; i < (size-1); i++){
			if (arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true;
			}
		}
	}while(swap);
}

// Report array content 
void reportArr(const int arr[], int size){
	cout << "The array content is: ";
	for (int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// Main test driver 
int main(){
	const int SIZE = 10;
	int arr[SIZE] = {1,2,-99,-100,-1,0,3,99,100};
	reportArr(arr,SIZE);
	bubSort(arr, SIZE);
	cout << "The array after sorting is: " << endl;
	reportArr(arr,SIZE);
	return 0;
}