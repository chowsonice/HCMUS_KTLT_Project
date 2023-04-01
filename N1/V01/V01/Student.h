#pragma once
#include <iostream>
#include "Scoreboard.h"

using namespace std;

class Student
{
private:
	int no;
	string studentID;
	string firstName;
	string lastName;
	char gender;
	string dateOfBirth;
	string socialID;
	Scoreboard* scoreboard = nullptr;
public:
	Student() : no(0), studentID(""), firstName(""), lastName(""), gender('X'), dateOfBirth(""), socialID("") {}
	~Student();

    //int getNo() const;
    //const string getId() const;
    //const string getFirstName() const;
    //const string getLastName() const;
    //char getGender() const;
    //const string getDateOfBirth() const;
	//const string getSocialID() const;
	//const Scoreboard* getScoreboard() const;

	//void setNo(int no);
	//void setId(const string studentID);
	//void setFirstName(const string firstName);
	//void setLastName(const string lastName);
	//void setGender(char gender);
	//void setDateOfBirth(const string dateOfBirth);
	//void setSocialID(const string socialID);
	//void setScoreboard(const Scoreboard& scoreboard);

	void UpdateScoreboard(Scoreboard& scoreboard);
	void PrintScoreboard();
	void printStudentInfo();

	void readStudentFromCSVLine(string buffer);
	friend ostream& operator<<(ostream& os, const Student& s);
};

