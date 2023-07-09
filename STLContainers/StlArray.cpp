/*
	Name: StlArray
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing STL Array
*/
#include <array> 
#include <iostream>

// Report some STL Array methods
template<std::size_t SIZE>
void reportArr(std::array<char, SIZE>& arr){
	std::cout << "The front of the array is: "<< arr.front() <<'\n';
	std::cout << "The back of the array is: "<< arr.back() <<'\n';
	std::cout << "The max size of the array is: "<< arr.max_size() <<'\n';
	std::array<char, 5> this_array = {'w','o','r','l','d'};
	arr.swap(this_array);
	for (int i = 0; i < arr.size(); i++){
		std::cout<< arr.at(i) <<'\n';
	}
	std::cout << "Is the array empty?: "<< std::boolalpha << arr.empty()<<'\n';
}

// Main test driver
int main(){
	std::array<char, 5> this_array = {'h','e','l','l','o'};
	std::cout<< this_array.at(0)<<'\n';
	std::cout<< this_array[0]<<'\n';
	for (int i = 0; i < this_array.size(); i++){
		std::cout<< this_array.at(i) <<'\n';
	}
	reportArr(this_array);
	return 0;
}