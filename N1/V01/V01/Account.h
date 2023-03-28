#include <string.h>
class Account
{
	char* username;
	char* password;
	int typeOfUsers;
	// if 1 -> is a student
	// if 2 -> is a staff member
public:
	Account() : username(nullptr), password(nullptr), typeOfUsers(0) {}
	Account(char *usrname, char *pass): typeOfUsers(0) {
		username = new char[strlen(usrname)];
		strcpy_s(username, 100, usrname);
		password = new char[strlen(pass)];
		strcpy_s(password, 100, pass);
	}
	char *checkLogin(char* username, char* password);
};

