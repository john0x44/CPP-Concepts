/*
	Name: TestDestructor
	Copyright: 2023
	Author: John
	Date: 23/06/23 09:40
	Description: Implementing and testing destructor
*/
#include <iostream>
#include <ctime>
using namespace std;

class MakeDeck{
	private: 
		int deckSize;
		int *arrPtr;
	public:
		MakeDeck();
		~MakeDeck(){delete []arrPtr;}
		int getCard(int);
		
};

// Generate a random deck of card values 
MakeDeck::MakeDeck(){
	srand(time(0));
	deckSize = 10;
	this->arrPtr = new int[deckSize];
	for (int i = 0; i < deckSize; i++){
		this->arrPtr[i] = rand() % deckSize + 1;
	}
}

// Get a card at index
int MakeDeck::getCard(int index){
	if (index <= deckSize){
		return this->arrPtr[index];
	}else{
		return -1;
	}
}

// Main test driver
int main(){
	MakeDeck makeDeck;
	cout << "The card is: "<<makeDeck.getCard(3)<<endl;
	return 0;
}