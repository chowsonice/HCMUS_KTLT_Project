#pragma once
#include <fstream>
#include "Account.h"
#include <string>
#include <iostream>
using namespace std;

//bool Account::checkLogin(string username, string password) {
//	ifstream fin("Account.txt");
//	
//	string buffer1, buffer2[100];
//	while (fin >> buffer1 >> buffer2) {
//		if (strcmp(buffer1, username) == 0) {
//			if (strcmp(buffer2, password) == 0) return username;
//			else return nullptr;
//		} else continue;
//	}
//	return nullptr;
//}
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

void Account::input_change_password()
{
    string oldPassword, newPassword;
    cout << "Please enter your old password: ";
    cin >> oldPassword;
    cout << "Please enter your new password: ";
    cin >> newPassword;

    if (changePassword(oldPassword, newPassword))
    {
        ifstream fin("Account.txt");
        ofstream fout("temp.txt");
        string buffer1, buffer2;
        while (fin >> buffer1 >> buffer2)
        {
            if (buffer1 == username)
            {
                fout << username << " " << newPassword << endl;
            }
            else
            {
                fout << buffer1 << " " << buffer2 << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Account.txt");
        rename("temp.txt", "Account.txt");
    }
}