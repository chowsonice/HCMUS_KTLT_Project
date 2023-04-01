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