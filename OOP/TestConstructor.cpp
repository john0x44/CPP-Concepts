/*
	Name: TestConstructor
	Copyright: 2023
	Author: John
	Date: 23/06/23 09:40
	Description: Implementing and testing constructor 
*/
#include <iostream>
using namespace std;

// Make a box
class MakeBox{
	private:
		double weight;
	public: 
		MakeBox(){
			weight = 100.01;
		}
		double getWeight(){
			return weight;
		}
};

// Main test driver
int main(){
	MakeBox makeBox; 
	cout << "The default box weight is: "<<makeBox.getWeight()<<endl;
	return 0;
}