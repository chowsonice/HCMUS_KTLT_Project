#pragma once
#include "Student.h"
#include <list>

using namespace std;

class Course
{
	string courseId;
	string name;
	string classId;
	string teacherName;
	int noCredits;
	int maxNoStudents;
	string dayOfTheWeek;
	int session;
	list<Student*> listOfStudents;
public:
	Course() : courseId(""), name(""), classId(""), teacherName(""), noCredits(0), maxNoStudents(50), dayOfTheWeek(""), session(0) {}
	~Course() {}
	bool importStudentsFromCSV(string filename);
	//void setCourseId(const string id);
	//void setCourseName(const string name);
	//void setClassName(const string className);
	//void setClassId(const string classId);
	//void setTeacherName(const string teacherName);
	//void setNumOfCredits(int credits);
	//void setMaxStudents(int max);
	//void setDayOfWeek(const string day);
	//void setSession(int sess);
	//void setListOfStudents(list<Student> listOfStudents);
	void printListOfStudents();
	void input();
	void printListOfCourse();
	
	friend ostream& operator<<(ostream& os, const Course& s);
};



