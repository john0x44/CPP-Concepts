/*
	Name: StlForwardList
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing STL Forward List
*/
#include <iostream>
#include <forward_list>

// Report forward list content
template<class T>
void reportFlistContent(const std::forward_list<T>& flist) {
    int index = 0;
    for (const auto& element : flist) {
        std::cout << "Element at index " << index++ << ": " << element << std::endl;
    }
}

// Main test driver
int main(){
	std::forward_list<int> my_flist = {1,2,3,4,99,999,99,99};
	my_flist.push_front(10);
	my_flist.emplace_front(12);
	auto itr = my_flist.begin();
	my_flist.insert_after(itr, 13);
	my_flist.pop_front();
	reportFlistContent(my_flist);
	my_flist.sort();
	std::cout << "After sorting and removing '99' from the list is: " << std::endl;
	my_flist.remove(99);
	reportFlistContent(my_flist);
	return 0;
}