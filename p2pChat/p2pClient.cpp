#include <iostream>
#include <string>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "p2p.h"

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

int runClient(string Username, string ip, int port) {
    cout << "@" << Username << " > " << ip << " : " << port << "\n";
    string connectedUsername = "PEER";
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

    if (connect(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        cout << "Unable to connect to server. Returning to menu...\n";
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    connect(sock, (sockaddr*)&addr, sizeof(addr));
    connectedUsername = usernameExchange(sock, Username);

    cout << "Connected to " << connectedUsername << "!\n\n";

    thread recvThread(receiveMessages, sock, connectedUsername);

    std::string message;
    while (true) {
        cout << Username << ":";
        getline(cin, message);
        cin.ignore();
        if (message == "/quit") break;
        send(sock, message.c_str(), message.size(), 0);
    }

    closesocket(sock);
    WSACleanup();
    recvThread.join();
	return 0;
}
