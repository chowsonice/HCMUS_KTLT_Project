#pragma once
#include <iostream>

using namespace std;

class Student
{
private:
	int no;
	char* studentID;
	char* firstName;
	char* lastName;
	char gender;
	char* dateOfBirth;
	char* socialID;
	//Scoreboard scoreboard;
public:
	Student(int no, const char* studentID, const char* firstName, const char* lastName, char gender, const char* dateOfBirth, const char* socialID);
    ~Student();

    int getNo() const;
    const char* getId() const;
    const char* getFirstName() const;
    const char* getLastName() const;
    char getGender() const;
    const char* getDateOfBirth() const;
	const char* getSocialID() const;

	friend ostream& operator<<(ostream& os, const Student& s);
	//const Scoreboard& getScoreboard() const;
};

