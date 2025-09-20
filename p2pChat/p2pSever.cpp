#include <iostream>
#include <string>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "p2p.h"

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

int runServer(string Username, string ip, int port) {
	string connectedUsername = "PEER";
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // accept connections from any interface
    addr.sin_port = htons(port);

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    cout << ip <<" listening on port "<< port <<"...\n";
    SOCKET client_fd = accept(server_fd, nullptr, nullptr);
	connectedUsername = usernameExchange(client_fd, Username);
     
    cout << connectedUsername << " connected!\n\n";

    thread recvThread(receiveMessages, client_fd, connectedUsername, Username);

    string message;
    while (true) {
        getline(cin, message);
        if (message == "/quit") break;
        send(client_fd, message.c_str(), message.size(), 0);
        cout << Username << ": ";
    }

    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
    recvThread.join();
    return 2;
}
