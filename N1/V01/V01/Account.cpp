#pragma once
#include <fstream>
#include "Account.h"
#include <string>
#include <iostream>
using namespace std;

char *Account::checkLogin(char* username, char* password) {
	ifstream fin("Account.txt");
	
	char buffer1[100], buffer2[100];
	while (fin >> buffer1 >> buffer2) {
		if (strcmp(buffer1, username) == 0) {
			if (strcmp(buffer2, password) == 0) return username;
			else return nullptr;
		} else continue;
	}
	return nullptr;
}
bool Account::changePassword(char* oldPassword, char* newPassword)
{
    if (strcmp(password, oldPassword) != 0)
    {
        cout << "Incorrect password." << endl;
        return false;
    }
    else
    {
        delete[] password;
        password = new char[strlen(newPassword) + 1];
        strcpy_s(password, strlen(newPassword) + 1, newPassword);
        cout << "Password changed success." << endl;
        return true;
    }
}