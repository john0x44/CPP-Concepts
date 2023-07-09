/*
    Name: GetRequest
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Makes a GET request and retrieves the response
*/
#ifndef GETREQUEST_H
#define GETREQUEST_H

#include <windows.h>
#include <wininet.h>
#include <string>
#include <iostream>
#include "json.hpp"
#pragma comment(lib, "wininet.lib")
using namespace std;

using json = nlohmann::json;

class GetRequest {
public:
    // Make a GET request
    static string getRequest(const string& url) {
        string response;
        HINTERNET hInternet = initializeWinInet();
        if (hInternet == NULL) {
            return response;
        }
        HINTERNET hConnect = openUrlConnection(hInternet, url);
        if (hConnect == NULL) {
            closeConnections(hConnect, hInternet);
            return response;
        }
        readResponse(hConnect, response);
        closeConnections(hConnect, hInternet);
        return response;
    }

private:
    // Initialize the WinInet API
    static HINTERNET initializeWinInet() {
        HINTERNET hInternet = InternetOpenA("StockListener", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
        if (hInternet == NULL) {
            cout << "Connection failed: " << GetLastError() << endl;
        }
        return hInternet;
    }

    // Open the URL connection
    static HINTERNET openUrlConnection(HINTERNET hInternet, const string& url) {
        HINTERNET hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
        if (hConnect == NULL) {
            cout << "Connection failed: " << GetLastError() << endl;
            InternetCloseHandle(hInternet);
        }
        return hConnect;
    }

    // Read the response
    static void readResponse(HINTERNET hConnect, string& response) {
        DWORD bytesRead;
        // Maximum characters
        char buffer[10000];
        while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
            response.append(buffer, bytesRead);
        }
    }

    // Close connection and WinInet API
    static void closeConnections(HINTERNET hConnect, HINTERNET hInternet) {
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
    }
};

#endif
