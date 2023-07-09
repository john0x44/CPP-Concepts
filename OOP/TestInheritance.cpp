/*
	Name: TestInheritance
	Copyright: 2023
	Author: John
	Date: 23/06/23 09:40
	Description: Implementing and testing inheritance
*/
#include <iostream>
#include <ctime>
using namespace std;

// Base class 
class BaseFunctions{
	public:
		int GenerateNumber(int);
};

// Generate a random number 
int BaseFunctions::GenerateNumber(int maxNumber){
	srand(time(0));
	return rand() % maxNumber + 1;
}

// Inherit from base
class Box : BaseFunctions{
	private:
		int width;
		int height;
	public:
		Box();
		int getWidth();
		int getHeight();
};

// Test inherited function 
Box::Box(){
	this->width = this->GenerateNumber(30);
	this->height = this->GenerateNumber(50);
}

// Getters
int Box::getWidth(){
	return this->width;
}

int Box::getHeight(){
	return this->height;
}

// Main test driver
int main(){
	Box newBox;
	cout << "The width of newBox is: "<<newBox.getWidth()<<" the height is: "<<newBox.getHeight()<<endl;
	return 0;
}
