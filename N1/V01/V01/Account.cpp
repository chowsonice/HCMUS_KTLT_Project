#pragma once
#include <fstream>
#include "Account.h"
#include <string.h>
#include <iostream>
#include <sstream>
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

//Account chuyen sang dang student_account/MSSV.txt roi, nen chinh lai nha
//bool Account::changePassword(string& oldPassword, string& newPassword)
//{
//    ifstream fin("Account.txt");
//    ofstream fout("temp.txt");
//    string line;
//
//    bool passwordChanged = false;
//    while (getline(fin, line)) {
//        string username, pass;
//        int typeOfUsers;
//        istringstream iss(line);
//        iss >> username >> pass >> typeOfUsers;
//        if (username == this->username && pass == oldPassword) {
//            passwordChanged = true;
//            pass = newPassword;
//        }
//        fout << username << " " << pass << " " << typeOfUsers << endl;
//    }
//
//    fin.close();
//    fout.close();
//
//    if (passwordChanged) {
//        remove("Account.txt");
//        rename("temp.txt", "Account.txt");
//        password = newPassword;
//        return true;
//    }
//    else {
//        return false;
//    }
//}
