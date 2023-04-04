#pragma once
#include <fstream>
#include "Account.h"
#include <string.h>
#include <iostream>
using namespace std;

bool checkLogin(string username, string password) {
	ifstream fin("Account.txt");
	
	string buffer1, buffer2;
	while (fin >> buffer1 >> buffer2) {
		if (buffer1.compare(username) == 0) {
			if (buffer2.compare(password) == 0) {
				cout << "Successful login\n";
				return true;
			}
			else break;
		} else continue;
	}
	cout << "Student doesn't exist or entered wrong username.\n";
	return false;
}
//bool Account::changePassword(char* oldPassword, char* newPassword)
//{
//    if (strcmp(password, oldPassword) != 0)
//    {
//        cout << "Incorrect password." << endl;
//        return false;
//    }
//    else
//    {
//        password = newPassword;
//        cout << "Password changed success." << endl;
//        return true;
//    }
//}