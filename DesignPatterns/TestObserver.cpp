/*
	Name: TestObserver
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing observer design pattern
*/
#include <vector>
#include <iostream>
using namespace std;

// This 'Box' will be observed
class Box{
	private:
		double weight;
		std::vector<class Observer*> observerList;
	public:
		void setWeight(double);
		double getWeight();
		void notify();
		void addObserver(Observer *observer);
};

// This 'observer' will be called
class Observer{
	private:
		Box *box;
	public:
		Observer(Box *thisBox){
			box = thisBox;
			box->addObserver(this);
		};
		virtual void update() = 0;
	protected: 
		Box* getBox(){return box;}
};

// Create a weight observer 
class WeightObserver : public Observer{
	public:
	WeightObserver(Box *box): Observer(box){};
	void update(){
		cout << "Weight has been updated!: " << getBox()->getWeight();
	}
};


// Main test driver
int main(){
	Box *box = new Box();
	WeightObserver weightObserver(box);
	box->setWeight(100.2);
	return 0;
}

// Set weight of box
void Box::setWeight(double newWeight){
	this->weight = newWeight;
	this->notify();
}

// Get weight of box
double Box::getWeight(){
	return this->weight;
}

// Add observer 
void Box::addObserver(Observer *observer){
	this->observerList.push_back(observer);
}

// Notify all observers
void Box::notify(){
	for(int i =0; i < this->observerList.size(); i++){
		observerList[i]->update();
	}
}