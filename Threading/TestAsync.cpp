/*
	Name: TestAsync
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing async
*/
#include <iostream>
#include <future>
#include <stdlib.h>

// Loop function
bool runLoop(){
	for (int i = 0; i < 20; i++){
		std::cout << "Hello world!" << (i+1) << '\n';
		sleep(5);
	}
	return true;
}

// Another loop 
bool otherLoop(){
	for (int i = 0; i < 100; i++){
		std::cout << "Hello world! from other function!" << '\n';
		sleep(1);
	}
	return true;
}

// Main test driver
int main(){
	
	// Run concurrently!
	std::future<bool> initLoop = std::async(std::launch::async, runLoop);
	std::future<bool> initLoop2 = std::async(std::launch::async, otherLoop);

	return 0;
}