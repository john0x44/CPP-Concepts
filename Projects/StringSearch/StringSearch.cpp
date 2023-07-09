/*
	Name: StringSearch
	Copyright: 2023
	Author: John 
	Date: 22/06/23 19:19
	Description: Searching string in a file 
*/
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std; 

// Prototypes
void getData(ifstream &, string&, string&);
void searchFile(ifstream &, string);
int searchLine(string, string);
bool openFile(ifstream &, string);
void countFinds(ifstream &inFile, int &, string, string);

// Main driver
int main(){
	string fileName, searchStr;
	ifstream inFile;
	getData(inFile, fileName, searchStr);
	return 0; 
}

// Search string in the line 
int searchLine(string line, string searchStr){
	int findPos = line.find(searchStr);
	if (findPos != -1){
		cout << line << endl;
		return 1;
	}
	return 0;
}

// Count number of search string found
void countFinds(ifstream &inFile, int &foundSum, string word, string searchStr){
	while(inFile){
		foundSum = foundSum + searchLine(word, searchStr);
		getline(inFile, word);
	}
}

// Search the string in the file 
void searchFile(ifstream &inFile, string searchStr){
	string word; 
	int timesFound = 0;
	getline(inFile, word);
	cout << "Full lines shown containing the search string \"" 
	<< searchStr << "\":" << endl;
	countFinds(inFile, timesFound, word, searchStr);
	inFile.close();
	cout << "\nNumber of times the search string \"" << searchStr 
	<< "\" was found in the file: " << timesFound;
}

// Checking if file exists
bool openFile(ifstream &inFile, string fileName){
	inFile.open(fileName);
	if (inFile.fail()){
		return false;
	}
	return true;
}

// Ask user for file name and search string
void getData(ifstream &inFile, string &fileName, string &searchStr){
	cout << "Enter a file name: ";
	getline(cin, fileName);
	if (openFile(inFile, fileName)){
		cout << "Enter a string to look for: ";
		getline(cin, searchStr);
		searchFile(inFile, searchStr);
	}else{
		cout << "No file named \"" << fileName << "\" found!";		
	}
}