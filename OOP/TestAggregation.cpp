/*
	Name: TestAggregation
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing Aggregation
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

// 'SomeOtherClass' has borrowed 'SomeClass'
class SomeOtherClass{
	public:
    	void printOtherClass(const SomeClass& someClass);
};

void SomeOtherClass::printOtherClass(const SomeClass& someClass) {
    cout << someClass.getSomeValue() << endl;
}

//Main test driver
int main(){
	SomeClass someClass;
    SomeOtherClass someOtherClass;
    someOtherClass.printOtherClass(someClass);
	return 0;
}