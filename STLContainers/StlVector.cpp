/*
	Name: StlVector
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing STL Vector
*/
#include <iostream>
#include <vector>

// Report contents of vector 
void reportVector(const std::vector<int>& this_vector){
	for(int i = 0; i < this_vector.size(); i++){
		std::cout << this_vector[i] << std::endl;
	}
}

// Report vector access methods
void reportVectorAcc(const std::vector<int> & this_vector){
	std::cout << "Accesing using 'at': " << this_vector.at(0) << std::endl;
	std::cout << "Accesing using 'front': " << this_vector.front() << std::endl;
	std::cout << "Accesing using 'back': " << this_vector.back() << std::endl;
}

// Main test driver
int main(){
	std::vector<int> this_vector;
	this_vector.push_back(4);
	this_vector.emplace_back(4);
	this_vector.push_back(5);
	this_vector.emplace_back(7);
	reportVector(this_vector);
	reportVectorAcc(this_vector);
	std::cout << "The current size of the vector is: " << this_vector.size() << std::endl;
	std::cout << "The current capacity of the vector is: " << this_vector.capacity() << std::endl;
	this_vector.resize(10);
	std::cout << "After resizing the current size of the vector is: " << this_vector.size() << std::endl;
	this_vector.shrink_to_fit();
	std::cout << "After 'shrinking_to_fit' The current size of the vector is: " << this_vector.size() << std::endl;
	this_vector.reserve(20);
	reportVector(this_vector);
	std::cout << "After 'reserving' some memory the vector's new size is: "<< sizeof(this_vector) << std::endl;
	return 0;
}