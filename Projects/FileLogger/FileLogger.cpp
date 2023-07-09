/*
	Name: FileLogger
	Copyright: 2023
	Author: John
	Date: 22/06/23 17:19
	Description: Listens to a particular txt file for changes
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Checking if file exists
bool openFile(ifstream &inFile, string fileName){
	inFile.open(fileName);
	if (inFile.fail()){
		return false;
	}
	return true;
}

// Log the file contents 
string logFile(ifstream &inFile, string filePath){
	inFile.close();
	openFile(inFile, filePath);
	string fileContents; 
    string line;
    getline(inFile, line);
    while (inFile) {
        fileContents += line; 
        getline(inFile, line);
    }
    return fileContents;
}

// Display new changes!
void reportNewChanges(string oldContent, string newContent){
	for (int i = 0; i < newContent.length(); i++){
		if (i < oldContent.length()){
			if (newContent[i] != oldContent[i]){
				cout << newContent[i] << " ";
		}else{
			cout << "+ "<< newContent[i];
		}
		}
	}
}

// Match the last file contents
void reportChange(ifstream &inFile, string filePath){
	int logTimes = 0;
	int detectedTimes = 0;
	string oldContent = "";
	while(true){
		sleep(5);
		string newContent = logFile(inFile,filePath);
		if (oldContent != newContent && logTimes > 0){
			detectedTimes += 1;
			cout << "Detected file content change! CHANGED TIMES [" << detectedTimes <<"] "<<endl;
			cout << "This change has occured: "<<endl;
			reportNewChanges(oldContent, newContent);
			cout << endl;
			oldContent = newContent;
		}
		logTimes += 1;
	}
}

// Main test driver 
int main(){
	ifstream inFile;
	string filePath;
	cout << "Enter file location: ";
	cin>>filePath;
	cout << "Now logging file!"<<endl;
	if (openFile(inFile, filePath)){
		reportChange(inFile, filePath);
	}else{
		cout << "No file found!";		
	}
	return 0;
}