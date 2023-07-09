/*
	Name: TestThread
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing thread
*/
#include <iostream>
#include <future>
#include <thread>
#include <vector>

// Run this function simultaneously
void runFunct(int number) {
    std::cout << "Hello, this is thread number: " << number << '\n';
}

// Main test driver
int main() {
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 20; i++) {
        threads.emplace_back(runFunct, i);
    }
    
    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    
    return 0;
}