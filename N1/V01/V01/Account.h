#include <string>
using namespace std;

class Account
{
	string username;
	string password;
	int typeOfUsers;
	// if 2 -> is a student
	// if 1 -> is a staff member
public:
	Account() : username(""), password(""), typeOfUsers(0) {}
	Account(string usrname, string pass, int type): username(usrname), password(pass), typeOfUsers(type) {}

	bool changePassword(string& oldPassword, string& newPassword);
	int getType() {
		return typeOfUsers;
	}
	string getUsername() {
		return username;
	}
	~Account() {}
};

int checkLogin(string username, string password);
