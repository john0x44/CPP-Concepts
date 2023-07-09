/*
	Name: StlList
	Copyright: 2023
	Author: John
	Date: 20/06/23 19:35
	Description: Testing and implementing STL List
*/
#include <iostream>
#include <list>
#include <iterator>

// Report the content of the list
void reportContent(const std::list<char>& list){
    std::list<char>::const_iterator index = list.begin();
    for(int i = 0; i < list.size(); i++){
        std::cout << *index << std::endl;
        std::advance(index, 1);
    }
}

//// Report more list methods
//void reportMoreList(){
//	std::list<char> this_list = {'w','o','r','l','d'};
//	this_list.reverse();
//	reportContent(this_list);
//	this_list.sort();
//	reportContent(this_list);
//}

// Report some other list methods
void reportList(std::list<char>& this_list){
	std::cout << "The front of the list is: "<< this_list.front()<<std::endl;
	std::cout << "The back of the list is: "<< this_list.back()<<std::endl;
	this_list.pop_back();
	this_list.pop_front();
	std::cout << "After popping back and popping front the new list is: "<<std::endl;
	reportContent(this_list);
	this_list.remove('l');
	std::cout << "After removing all 'l' in this list is: "<<std::endl;
	reportContent(this_list);
	this_list.clear();
	std::cout << "After clearing the list : "<<std::endl;
	reportContent(this_list);
	std::cout << "The new list size after clearing is: "<<this_list.size()<<std::endl;
}

// Main test driver
int main(){
	std::list<char> this_list = {'h','e','l','l','o'};
	std::cout << "The new list has these elements: " <<std::endl;
	reportContent(this_list);
	this_list.push_back('w');
	std::cout << "Printing after pushing to the back! "<<std::endl;
	reportContent(this_list);
	reportList(this_list);
	//reportMoreList();
	return 0;
}