/*
	Name: TestAdapter
	Copyright: 2023
	Author: John
	Date: 21/06/23 18:10
	Description: Implementing and testing adapter design pattern
*/

#include <iostream>
#include <string>
using namespace std; 

class Translator{
	public:
		virtual void translator() = 0;
};

class EnglishLanguage{
	public:
		void speakingEnglish() {cout << "Hello" << endl;}
};

class SpanishLanguage{
	public:
		void speakingSpanish() {cout << "Hola" << endl;}
};

// 'Adapter' class
class Translate: public SpanishLanguage, public EnglishLanguage{
	public:
		void translator(){ speakingEnglish(); }
};

// Main test driver
int main(){
	Translate translate;
	cout << "The word in spanish is: "<< endl;
	translate.speakingSpanish();
	cout << "Now translating to english!: " <<endl;
	translate.translator();
	return 0;
}