/*
	Name: TestSelectionSort
	Copyright: 2023
	Author: John
	Date: 21/06/23 17:01
	Description: Implementing and testing selection
*/
#include <iostream>
using namespace std;

// Selection sort
void selSort(int arr[], int size){
	int startScan, minIndex, minValue;
	for(startScan = 0; startScan < (size - 1); startScan++){
		minIndex = startScan;
		minValue = arr[startScan];
		for(int i = startScan + 1; i < size; i++){
			if (arr[i] < minValue){
				minValue = arr[i];
				minIndex = i;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minValue;
	}
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
	int arr[SIZE] = {1,2,-92,40,1,0,-3,99,100};
	reportArr(arr,SIZE);
	selSort(arr, SIZE);
	cout << "The array after sorting is: " << endl;
	reportArr(arr,SIZE);
	return 0;
}