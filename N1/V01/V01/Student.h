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
	Student() : no(0), studentID(nullptr), firstName(nullptr), lastName(nullptr), gender('X'), dateOfBirth(nullptr), socialID(nullptr) {}
	Student(int no, const char* studentID, const char* firstName, const char* lastName, char gender, const char* dateOfBirth, const char* socialID);
	Student(const Student& s) : Student(s.no, s.studentID, s.firstName, s.lastName, s.gender, s.dateOfBirth, s.socialID) {}
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

