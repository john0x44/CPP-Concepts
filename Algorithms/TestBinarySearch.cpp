/*
	Name: TestBinarySearch
	Copyright: 2023
	Author: John
	Date: 21/06/23 17:01
	Description: Implementing and testing binary search
*/
#include <iostream>
using namespace std;

// Binary search 
int binSearch(const int arr[], int size, int value){
	int first = 0, last = size - 1;
	while(first <= last){
		int mid = (first + last) / 2;
		if (arr[mid]==value)
			return mid;
		else if(arr[mid] > value)
			last = mid - 1;
		else 
			first = mid + 1;
	}
	return -1;
}

// Main test driver
int main(){
	const int SIZE = 10;
	int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	cout << "The array content is: ";
	for (int i = 0; i < SIZE; i++){
		cout << arr[i] << ' ';
	}
	// Searching value '3' in array
	cout << "\nSearching the value '3' in the array, found at position:"<< binSearch(arr, SIZE, 3) << endl;
	return 0;
}