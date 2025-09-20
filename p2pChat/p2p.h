#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

using namespace std;

int runClient(string Username, string ip, int port);
int runServer(string Username, string ip, int port);
void receiveMessages(SOCKET sock, string connectedUsername);
string usernameExchange(SOCKET sock, string Username);
string getIP();