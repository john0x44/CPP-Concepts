/*
	Name: TestNthElement
	Copyright: 2023
	Author: John
	Date: 21/06/23 17:01
	Description: Implementing and testing nth_element
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// Main test driver
int main(){
	std::vector<int> vec{1,3,4,6,8,3,2,1,33};
	cout << "The second largest number is: " << endl;
	std::nth_element(vec.begin(), vec.begin()+1, vec.end(),std::greater<int>());
	cout << vec[1] << endl;
	return 0;
}