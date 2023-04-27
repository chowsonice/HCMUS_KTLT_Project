#pragma once
#include <fstream>
#include "Account.h"
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

int Account::getType() {
	return typeOfUsers;
}

string Account::getUsername() {
	return username;
}

int checkLogin(string username, string password) {
	ifstream fin("staff_account/StaffAccount.txt");

	cout << password << endl;
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

bool Account::changePassword(const string oldpass, const string newpass)
{
	if (oldpass != password) return false;

	string source = "student_account/" + username + ".txt";
    ifstream fin(source);
	ofstream fout;

	string line, file;

	fin.ignore(1000, '\n');
	file = newpass + '\n';

	while (!fin.eof()) {
		getline(fin, line);
		file += line + "\n";
	}

	fin.close();
	fout.open(source);

	fout << file;
    fout.close();

	password = newpass;
	return true;
}
