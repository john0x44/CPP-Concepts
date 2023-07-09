#include <iostream>
#include <vector>
using namespace std; 

// Node class 
class Node{
	private: 
		int nodeValue; 
		Node *next_Node;
	public:
		Node(int value);
		Node(const Node &otherNode) = delete;
		Node operator = (const Node &otherNode) = delete;
		~Node();
		int value() const;
		Node *nextNode() const;
		void setNextNode(Node *nextNode);
};

Node::Node(int value){
	this->nodeValue = value;
	this->next_Node = nullptr;
}

Node::~Node(){
	if(this->next_Node != nullptr){
		delete this->next_Node;
		this->next_Node = nullptr;
	}
}

Node *Node::nextNode() const{
	return this->next_Node;
}

int Node::value() const{
	return this->nodeValue;
}

void Node::setNextNode(Node *nextNode){
	this->next_Node = nextNode;
}

// Linked List class 
class LinkedList{
	private:
		Node *head;
		Node *current;
		int size;
	public: 
		LinkedList();
		~LinkedList();
		LinkedList(const LinkedList &other) = delete;
		LinkedList operator = (const LinkedList &other) = delete;
		void add(int element);
		void remove(int element);
		int getSize() const;
};

LinkedList::LinkedList(){
	this->head = new Node(0);
	this->size = 0;
	this->current = this->head;
}

LinkedList::~LinkedList(){
	if(this->head != nullptr){
		delete this->head;
		this->head = nullptr;
	}
}

void LinkedList::add(int element){
    Node *node = new Node(element);
    this->current->setNextNode(node);
    this->current = node; 
    this->size += 1;
}

void LinkedList::remove(int element){
	Node *node = this->head->nextNode();
	Node *prev = this->head;
	while(node != nullptr && node->value() != element){
		prev = node;
		node = node->nextNode();
	}
	if(node != nullptr){
		prev->setNextNode(node->nextNode());
		node->setNextNode(nullptr);
		delete node;
	}
	--this->size;
}

int LinkedList::getSize() const{
	return this->size;
}

// Main test driver
int main(){
    LinkedList linkedList;
    cout << linkedList.getSize() << endl;//0
    linkedList.add(3);
    cout << linkedList.getSize() << endl;//1
    linkedList.remove(3);
    linkedList.add(3);
    linkedList.add(6);
    cout << linkedList.getSize() << endl;//2
    linkedList.remove(3);
    cout << linkedList.getSize() << endl;//1
    return 0;
}
