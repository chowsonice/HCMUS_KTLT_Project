#pragma once
#include <fstream>
#include "Account.h"
#include <string.h>
#include <iostream>
using namespace std;

int checkLogin(string username, string password) {

	ifstream fin("StaffAccount.txt");

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
	fin.open("StudentAccount.txt");
	
	while (fin >> buffer1 >> buffer2) {
		if (buffer1.compare(username) == 0) {
			if (buffer2.compare(password) == 0) {
				return 2;
			}
			else break;
		} else continue;
	}
	return -1;
}

bool Account::changePassword(string& oldPassword, string& newPassword)
{
    if (password != oldPassword)
    {
        cout << "Incorrect password." << endl;
        return false;
    }
    else
    {
        password = newPassword;
        cout << "Password changed successfully." << endl;
        return true;
    }
}

//void Account::input_change_password()
//{
//    string oldPassword, newPassword;
//    cout << "Please enter your old password: ";
//    cin >> oldPassword;
//    cout << "Please enter your new password: ";
//    cin >> newPassword;
//
//    if (changePassword(oldPassword, newPassword))
//    {
//        ifstream fin("Account.txt");
//        ofstream fout("temp.txt");
//        string buffer1, buffer2;
//        while (fin >> buffer1 >> buffer2)
//        {
//            if (buffer1 == username)
//            {
//                fout << username << " " << newPassword << endl;
//            }
//            else
//            {
//                fout << buffer1 << " " << buffer2 << endl;
//            }
//        }
//        fin.close();
//        fout.close();
//        remove("Account.txt");
//        rename("temp.txt", "Account.txt");
//    }
//}