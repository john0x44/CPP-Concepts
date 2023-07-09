/*
	Name: StockListener
	Copyright: 2023
	Author: John
	Date: 22/06/23 16:31
	Description: Listens to a stock price change every 10 seconds
*/
#include <windows.h>
#include <wininet.h>
#include <string>
#include <iostream>
#include "json.hpp"
#pragma comment(lib, "wininet.lib")
using namespace std; 

// More info on wininet api:
// http://speed.eik.bme.hu/help/html/Web_Programming_Unleashed/ch17.htm
// https://discover.hubpages.com/technology/C-Tutorial-Interaction-with-internet-using-Wininet
// https://cplusplus.com/forum/beginner/75062/

using json = nlohmann::json;

// Initialize the WinInet API
HINTERNET initializeWinInet()
{
    HINTERNET hInternet = InternetOpenA("StockListener", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL){
        cout << "Connection failed: " << GetLastError() <<endl;
    }
    return hInternet;
}

// Open the url connection
HINTERNET openUrlConnection(HINTERNET hInternet, const string& url){
    HINTERNET hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (hConnect == NULL){
        cout << "Connection failed: " << GetLastError() << endl;
        InternetCloseHandle(hInternet);
    }
    return hConnect;
}

// Read the response 
void readResponse(HINTERNET hConnect, string& response)
{
    DWORD bytesRead;
    // Maximum characters
    char buffer[10000];
    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0){
        response.append(buffer, bytesRead);
    }
}

// close connection and WinInet API
void closeConnections(HINTERNET hConnect, HINTERNET hInternet){
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
}

// Make a get request 
string getRequest(const string& url){
    string response;
    HINTERNET hInternet = initializeWinInet();
    if (hInternet == NULL){
        return response;
    }
    HINTERNET hConnect = openUrlConnection(hInternet, url);
    if (hConnect == NULL){
        closeConnections(hConnect, hInternet);
        return response;
    }
    readResponse(hConnect, response);
    closeConnections(hConnect, hInternet);
    return response;
}

// Report the stock price continously at interval!
void reportListen(string ticker, int waitTime){
	int updateTimes = 0;
	string url = "https://ql.stocktwits.com/batch?symbols="+ticker;
	cout << "Now watching [" << ticker << "]\n"; 
	while (true){
		updateTimes += 1;
		try{
    		json data = json::parse(getRequest(url));
    		double lastValue = data[ticker]["Last"];
    		double change = data[ticker]["Change"];
    		cout << "CURRENT ["<<ticker<<"] PRICE: $"<< lastValue <<" CHANGE: $"<<change
			<<" UPDATED TIMES ["<<updateTimes<<"]"<<endl;
    	}catch(...){
    		cout << "something went wrong restart program!/n";
    		break;
		}
    	sleep(10);
	}
}

// Main test driver 
int main()
{
	string ticker = "";
	cout << "Please enter a valid ticker symbol to watch: ";
	cin >> ticker;
	reportListen(ticker, 10);
    return 0;
}