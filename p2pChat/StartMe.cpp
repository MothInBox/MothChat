#include <iostream>
#include "p2p.h"

using namespace std;

int main(){
	bool running = true;
	int result = 0;
	string ip = "127.0.0.1";
	int port = 8080;


	cout << "Welcome to Moth Chat 1\n";
	cout << "--------------------------------\n";
	cout << "Please create a username: ";
	string Username;
	getline(cin, Username);
	if (Username.length() == 0) Username = "PEER";
	system("cls");

	string message;

	while (running) {

		switch (result) {
			case 0:
				message = "Hello, " + Username + "!";
				break;
			case 1:
				message = "Your Connection failed, "+Username+". Try Again ? ";
				break;
			case 2:
				message = "You have disconnected, "+Username+".";
				break;
			default:
				message = "Something unexpected has occured.";
				break;
		}

		cout << "Welcome to Moth Chat 1\n";
		cout << "--------------------------------\n";
		cout << message << "\n";
		cout << "1. Start as Server\n";
		cout << "2. Start as Client\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";

		int choice;
		cin >> choice;
		cin.ignore(); // to ignore the newline character after the integer input
		system("cls");
		switch (choice) {
			case 1:
				cout << "PORT (e.g. 8080): ";
				cin >> port;
				system("cls");
				cout.flush();
				result = runServer(Username, port);
				break;
			case 2:
				cout << "IP (e.g. 127.0.0.1): ";
				cin >> ip;
				cout << "PORT (e.g. 8080): ";
				cin >> port;
				system("cls");
				cout.flush();
				result = runClient(Username, ip, port);
				break;
			case 3:
				running = false;
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
				break;
		}
		system("cls");
	}

	return 0;
}