#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include "p2p.h"

using namespace std;

void receiveMessages(SOCKET sock, string Username) {
	char buffer[1024]; // buffer for incoming messages
    while (true) {
		int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0); // leave space for null terminator
		if (bytes <= 0) break; // connection closed
		buffer[bytes] = '\0';
		cout << "\r" << Username << ": " << buffer << "\n>";
		cout.flush();
    }
}

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