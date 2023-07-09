/*
	Name: TestThreadConcurrency
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing thread concurrency
*/
#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <stdlib.h>

// Run this function simultaneously
void runFunct() {
    std::cout << "Hello, this is thread number: " << std::this_thread::get_id() << '\n';
    sleep(1);
}

// Main test driver
int main() {
	
	// Run threads concurrently!
	for (int i = 0; i < 100 ;i++){
    	std::packaged_task<void()> task(runFunct);
    	std::future<void> initFuture = task.get_future();
    	std::thread this_thread(std::move(task));
    	this_thread.join();
	}	
    return 0;
}