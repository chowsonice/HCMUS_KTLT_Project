#pragma once
#include <iostream>
#include "Scoreboard.h"

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
	Scoreboard scoreboard;
public:
	Student() : no(0), studentID(nullptr), firstName(nullptr), lastName(nullptr), gender('X'), dateOfBirth(nullptr), socialID(nullptr) {}
	Student(int no, const char* studentID, const char* firstName, const char* lastName, char gender, const char* dateOfBirth, const char* socialID, const Scoreboard& scoreboard);
	Student(const Student& s) : Student(s.no, s.studentID, s.firstName, s.lastName, s.gender, s.dateOfBirth, s.socialID, s.scoreboard) {}
	~Student();

    int getNo() const;
    const char* getId() const;
    const char* getFirstName() const;
    const char* getLastName() const;
    char getGender() const;
    const char* getDateOfBirth() const;
	const char* getSocialID() const;
	const Scoreboard& getScoreboard() const;

	void setNo(int no);
	void setId(const char* studentID);
	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);
	void setGender(char gender);
	void setDateOfBirth(const char* dateOfBirth);
	void setSocialID(const char* socialID);
	void setScoreboard(const Scoreboard& scoreboard);

	//void UpdateScoreboard(Scoreboard& scoreboard);
	void PrintScoreboard();


	void readStudentFromCSVLine(char* buffer);
	friend ostream& operator<<(ostream& os, const Student& s);
};

