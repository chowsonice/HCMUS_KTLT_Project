#pragma once
#include "Student.h"
#include "Node.h"

using namespace std;

class Course
{
	char* courseId;
	char* name;
	char* classId;
	char* teacherName;
	int noCredits;
	int maxNoStudents;
	char* dayOfTheWeek;
	int session;
	LinkedList<Student> listOfStudents;
public:
	Course() : courseId(nullptr), name(nullptr), classId(nullptr), teacherName(nullptr), noCredits(0), maxNoStudents(50), dayOfTheWeek(nullptr), session(0), listOfStudents(nullptr) {}
	Course(char* idData, char* nameData, char* classIdData, char* teacherNameData, int noCreditsData, int maxStudentData, char* weekDayData, int sessionData, LinkedList<Student> listData);
	Course(const Course& c) : Course(c.classId, c.name, c.classId, c.teacherName, c.noCredits, c.maxNoStudents, c.dayOfTheWeek, c.session, c.listOfStudents) {}
	~Course() {
		delete[] courseId, name, classId, teacherName, dayOfTheWeek, listOfStudents;
		courseId = nullptr;
		name = nullptr;
		classId = nullptr;
		dayOfTheWeek = nullptr;
		listOfStudents = nullptr;
	}
	bool importStudentsFromCSV(char* filename);
	void printListOfStudents();
	void setCourseId(char* id);
	void setCourseName(char* name);
	void setClassName(char* className);
	void setTeacherName(char* teacherName);
	void setNumOfCredits(int credits);
	void setMaxStudents(int max);
	void setDayOfWeek(char* day);
	void setSession(string sess);
	void input();
};



