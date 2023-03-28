#pragma once
#include <fstream>
#include "Account.h"
#include <string>
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