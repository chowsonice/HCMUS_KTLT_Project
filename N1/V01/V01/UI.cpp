#include <iostream>
#include "UI.h"
using namespace std;

void loginScreen(Account &main) {
	string usrn, pass;
	int count = 0;
	while (count < 3) {
		cout << "Welcome to the University Management System!\n";
		cout << "===========================================\n";
		cout << "LOGIN\n";
		cout << "Username: ";
		cin >> usrn;
		cin.ignore(1000, '\n');
		cout << "Password: ";
		char c = 'a';
		while ((c = _getch()) != '\r') {
			if (pass.length() > 0 && c == '\b') {
				printf("\b \b");
				pass.erase(pass.begin() + pass.length() - 1);
			}
			else if (c != '\t' && c > 32 && c < 127) {
				cout << "*";
				pass += c;
			}
			else {
				throw "Invalid character in password";
				break;
			}
		}
		cout << endl;
		int type = checkLogin(usrn, pass);
		if (type != -1) {
			cout << "Login successful. \nReturning to the main menu...\n";
			break;
		}
		else {
			cout << "Wrong username or password. You have "<< 2 - count << " more tries.\nPRESS ANYTHING TO CONTINUE\n";
			_getch();
			system("cls");
			count++;
		}
		if (count >= 3) {
			cout << "SYSTEM EXITING...\n";
			throw "Invalid login";
			return;
		}
		else {
			main = Account(usrn, pass, type);
		}
	}

	return;
}

void staffMenu() {
	system("cls");
	return;
}