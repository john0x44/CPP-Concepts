/*
	Name: TestAssociation
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing association
*/
#include <iostream>
using namespace std;


class SomeClass{
	private:
    	int someValue;

	public:
    	int getSomeValue() { return someValue; }
    	SomeClass() { someValue = 1234567; }
};

// 'SomeOtherClass' has a relationship to 'SomeClass'
class SomeOtherClass{
	public:
    	void printOtherClass(SomeClass someClass);
};

void SomeOtherClass::printOtherClass(SomeClass someClass) {
    cout << someClass.getSomeValue() << endl;
}

// Main test driver
int main(){
    SomeClass someClass;
    SomeOtherClass someOtherClass;
    someOtherClass.printOtherClass(someClass);
    return 0;
}
