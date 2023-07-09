/*
	Name: TestPolymorphism
	Copyright: 2023
	Author: John
	Date: 23/06/23 09:40
	Description: Implementing and testing polymorphism
*/
#include <iostream>
using namespace std;

// Abstract base class
class Base{
	virtual void test() = 0;
};

class OtherClass: public Base{
	public:
		void test(){
			cout << "This is OtherClass"<<endl;
		};
};

class SomeClass: public Base{
	public:
		void test(){
			cout << "This is SomeClass"<<endl;
		}
};

// Main test driver 
int main(){
	OtherClass otherClass;
	SomeClass someClass;
	otherClass.test();
	someClass.test();
	return 0;
}