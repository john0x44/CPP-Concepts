/*
	Name: TestSingleton
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing singleton 
*/
#include <iostream>
#include <string>
using namespace std; 

// Declare 'Server' class 
class Server{
	private:
	static Server* instance;
	string status;
	public:
		static Server* getInstance(){
			if(instance == NULL)
				instance = new Server();
				return instance;
		};
		void setStatus(string);
		string getStatus();
		Server();
		~Server();
};

Server *Server::instance = NULL;

// Report singleton!
void reportSingleton(){
	Server *newServer = Server::getInstance();
	cout << newServer->getStatus() << endl;
}
// Main test driver 
int main(){
	Server *newServer = Server::getInstance();
	cout << newServer->getStatus() << endl;
	newServer->setStatus("online");
	reportSingleton();
	return 0;
}

// Constructor 
Server::Server(){
	this->status = "offline";
}

// Destructor 
Server::~Server(){
	delete this->getInstance();
}
string Server::getStatus(){
	return this->status;
}

void Server::setStatus(string newStatus){
	this->status = newStatus;
}