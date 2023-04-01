#include <string.h>
class Account
{
	string username;
	string password;
	int typeOfUsers;
	// if 1 -> is a student
	// if 2 -> is a staff member
public:
	Account() : username(""), password(""), typeOfUsers(0) {}
	Account(string usrname, string pass): typeOfUsers(0), username(usrname), password(pass) {}
	bool checkLogin(string username, string password);
};

