#pragma once
#include <iostream>
#include <cstring>
#include <sstream>
#include "Node.h"
#include "Scoreboard.h"
#include <fstream>

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
	LinkedList<Scoreboard*> list;
public:
	Student() : no(0), studentID(""), firstName(""), lastName(""), gender('X'), dateOfBirth(""), socialID("") {}
	Student(int n, string id, string fname, string lname, char gen, string dob, string sid) : no(n), studentID(id), firstName(fname), lastName(lname), gender(gen), dateOfBirth(dob), socialID(sid) {}
	Student(string id, string fname, string lname, char gen, string dob, string sid) : studentID(id), firstName(fname), lastName(lname), gender(gen), dateOfBirth(dob), socialID(sid) {}
	~Student();

    int getNo() const;
    const string getId() const;
    const string getFirstName() const;
    const string getLastName() const;
    char getGender() const;
    const string getDateOfBirth() const;
	const string getSocialID() const;

	void addScoreboard(string courseInfo);

	//const Scoreboard* getScoreboard() const;

	void setNo(int no);
	void setId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setGender(char gender);
	void setDateOfBirth(string dateOfBirth);
	void setSocialID(string socialID);

	void removeScoreboard(string id) {
		for (Node<Scoreboard*> s : list) {
			if (s.data->getCourseId().compare(id) == 0) list.remove(s.data);
		}
	}
	Scoreboard* findScoreboard(string courseId) {
		for (Node<Scoreboard*> c : list) {
			if (c.data->getCourseId().compare(courseId) == 0) {
				return c.data;
			}
		}
	}
	void updateScoreboard(string courseId, string line);
	void printOneScoreboard(string courseId);
	void printAllScoreboard();
	void printStudentInfo();

	void readStudentFromCSVLine(string buffer);
	friend ostream& operator<<(ostream& os, const Student& s);

	void readScoreboard(string filename);
	Student* readStudentFromFile(string studentID);
};

