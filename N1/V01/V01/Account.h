#include <string.h>
class Account
{
	char* username;
	char* password;
	int typeOfUsers;
public:
	Account() : username(nullptr), password(nullptr), typeOfUsers(0) {}
	Account(char *usrname, char *pass): typeOfUsers(0) {
		username = new char[strlen(usrname)];
		strcpy_s(username, 100, usrname);
		password = new char[strlen(pass)];
		strcpy_s(password, 100, pass);
	}
	void checkLogin(char* username, char* password);
};
