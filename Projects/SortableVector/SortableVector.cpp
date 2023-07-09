/*
	Name: SortableVector
	Author: John
	Date: 06/22/23 10:47
	Description: Testing SortableVector class template
*/
#include <iostream>
#include "SimpleVector.h"
using namespace std;

// Defining a SortableVector class template
template <class T> 
class SortableVector : public SimpleVector<T>{
	public:
		
		// Default constructor 
		SortableVector() : SimpleVector<T>()
		{}
	
		// Constructor 
		SortableVector(int size) : SimpleVector<T>(size)
		{}
	
		// Copy Constructor 
		SortableVector(const SortableVector &);
	
		// Sort in ascending order function
		void ascendSort();
};

// Display FeetInchVector object data
template <class T>
void reportVector(SortableVector<T> &thisVector){
	cout << "Displaying contents" << endl;
	for(int i = 0; i < thisVector.size(); i++){
		cout << thisVector[i] << endl;
	}
	cout << endl;
}

// Testing sort for <T>Vector object
template <class T>
void testVectorSort(SortableVector<T> &thisVector){
	cout << "Before sorting vector" << endl;
	reportVector(thisVector);
	cout << "After sorting vector" << endl;
	thisVector.ascendSort();
	reportVector(thisVector);
}

// Main test driver
int main(int argc, char** argv){
	SortableVector<int> intVector(5);
	// Set some test data for intVector object
	intVector[0] = -999;
	intVector[1] = 999;
	intVector[2] = 0;
	intVector[3] = 321;
	intVector[4] = -92;

	// Test ascend sort then display data for each object
	testVectorSort(intVector);
	return 0;
}

// Class copy constructor
template <class T>
SortableVector<T>::SortableVector(const SortableVector &obj) :
SimpleVector<T>(obj.size())
{
	for(int count = 0; count < this->size(); count++){
		this->operator[](count) = obj[count];
	}
}      

// Ascend sort class function 
template <class T> 
void SortableVector<T>::ascendSort(){
	bool swap; 
	T temp;
	do{
		swap = false;
		for(int count = 0; count < (this->size()-1); count++){
			if ( this->operator[](count) > this->operator[](count+1) ){
				temp = this->operator[](count);
				this->operator[](count) = this->operator[](count+1);
				this->operator[](count+1) = temp;
				swap = true;
			}
		}
	}while(swap);
}

