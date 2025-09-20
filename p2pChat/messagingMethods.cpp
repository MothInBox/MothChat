#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <string>
#include "p2p.h"

using namespace std;

// Function to continuously receive messages from the socket and display them with the sender's username.
void receiveMessages(SOCKET sock, string recUsername, string Username) {
	char buffer[1024]; // buffer for incoming messages
    while (true) {
		int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0); // leave space for null terminator
		if (bytes <= 0) break; // connection closed
		buffer[bytes] = '\0';
		cout << "\r" << recUsername << ": " << buffer << "\n";
		cout.flush();
        cout << Username << ": ";
    }
}

/// Exchanges usernames over a socket connection, sending the local username and receiving the peer's username.
string usernameExchange(SOCKET sock, string Username) {
	char buffer[1024];
	// Send our username
	send(sock, Username.c_str(), Username.size(), 0);
	// Receive peer's username
	int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
	if (bytes <= 0) return "PEER"; // default if connection closed
	buffer[bytes] = '\0';
	return string(buffer);
}

// Function to get public IP address
string getIP() {
    HINTERNET hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (!hInternet) return "Unavailable";

    HINTERNET hFile = InternetOpenUrlA(hInternet, "https://api.ipify.org", NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hFile) {
        InternetCloseHandle(hInternet);
        return "Unavailable";
    }

    char buffer[47] = {0};
    DWORD rSize = 0;
    BOOL result = InternetReadFile(hFile, buffer, sizeof(buffer) - 1, &rSize);
    buffer[rSize] = '\0';

    InternetCloseHandle(hFile);
    InternetCloseHandle(hInternet);

    if (!result || rSize == 0) return "Unavailable";
    return string(buffer);
}