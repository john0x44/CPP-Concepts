/*
	Name: StudentGrade
	Copyright: 2023
	Author: John
	Date: 22/06/23 05:58
	Description: Reports student grade 
*/
#include <iostream>
using namespace std; 

// Student report data
struct StudentReport{
	string StudentName;
	double Grade;
};

// Add student data
void addStudentData(StudentReport studentReports[],int students){
	for (int i = 0; i < students; i++){
		cin.ignore();
		cout << "Enter student number ["<< i+1 << "] name:";
		getline(cin, studentReports[i].StudentName);
		cout << "Enter student number ["<< i+1 << "] score: ";
		cin>>studentReports[i].Grade;
	}
}

// Display all student data
void reportStudentData(StudentReport studentReports[],int students){
	cout << endl;
	for (int i = 0; i < students; i++){
		cout << "Student number ["<<i+1<<"] data is: "<<endl;
		cout << "Student name: "<<studentReports[i].StudentName << endl;
		cout << "Student grade: "<<studentReports[i].Grade << endl;
		cout << endl;
	}
}

// Report highest grade
void reportHighestGrade(StudentReport studentReports[],int students){
	int studentNumber = 0;
	for(int i = 0; i < students; i++){
		if ( studentReports[studentNumber].Grade < studentReports[i].Grade ){
			studentNumber = i;
		}
	}
	cout << "The student with the highest grade is: "<<studentReports[studentNumber].StudentName<<
	" with a grade of "<<studentReports[studentNumber].Grade<<endl;
}

// Report how many people passed 
void reportNumberPassed(StudentReport studentReports[],int students,double passingScore){
	int studentsPassed = 0;
	for (int i =0; i < students; i++){
		if (passingScore < studentReports[i].Grade){
			studentsPassed = studentsPassed + 1;
			cout << studentReports[i].StudentName <<" has passed! with a score of "<<
			studentReports[i].Grade<<endl;
		}
	}
	cout << "The number of students that passed are: "<<studentsPassed<<endl;
	cout << "The number of students who failed are: "<<students - studentsPassed<<endl;
}

// Main test driver
int main(){
	int numOfStudents = 0;
	double minPassingScore = 65.00;
	cout << "Please enter the minimum passing score: ";
	cin>>minPassingScore;
	cout << "How many students would you like to add: ";
	cin>>numOfStudents;
	StudentReport studentReports[numOfStudents];
	addStudentData(studentReports,numOfStudents);
	reportStudentData(studentReports,numOfStudents);
	reportHighestGrade(studentReports,numOfStudents);
	reportNumberPassed(studentReports,numOfStudents,minPassingScore);
	return 0;
}