/*
	Name: TestComposition
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing Composition
*/
#include <iostream>
using namespace std;

class SomeClass{
	private:
    	int someValue;

	public:
    	int getSomeValue() const { return someValue; }
    	SomeClass() { someValue = 1234567; }
};

// 'SomeOtherClass' has created 'SomeClass'
class SomeOtherClass{
	private:
		SomeClass *someClass = new SomeClass();
	public:
		void printSomeClass(){
			cout << someClass->getSomeValue() << endl;
		}
};

// Main test driver
int main(){
	SomeOtherClass someOtherClass;
	someOtherClass.printSomeClass();
}