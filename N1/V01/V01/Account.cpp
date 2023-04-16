#pragma once
#include <fstream>
#include "Account.h"
#include <string.h>
#include <iostream>
using namespace std;

int checkLogin(string username, string password) {
	ifstream fin("staff_account/StaffAccount.txt");

	string buffer1, buffer2;

	while (fin >> buffer1 >> buffer2) {
		if (buffer1.compare(username) == 0) {
			if (buffer2.compare(password) == 0) {
				return 1;
			}
			else break;
		}
		else continue;
	}
	fin.close();

	string filename = "student_account/" + username + ".txt";
	fin.open(filename);
	
	if (!fin.is_open()) {
		throw "Student doesn't exist.\n";
		return -1;
	}

	fin >> buffer2;
	if (buffer2.compare(password) == 0) {
		return 2;
	}
	return -1;
}

//need to fix
bool Account::changePassword(string& oldPassword, string& newPassword)
{
    if (password != oldPassword)
        return false;

    password = newPassword;

    ofstream fout("Account.txt", ios::out | ios::trunc);
    fout << username << " " << newPassword << " " << typeOfUsers << endl;
    fout.close();

    return true;
}
