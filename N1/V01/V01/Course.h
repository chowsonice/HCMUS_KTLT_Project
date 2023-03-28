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
	void setCourseId(const char* id);
	void setCourseName(const char* name);
	void setClassId(const char* classId);
	void setTeacherName(const char* teacherName);
	void setNumOfCredits(const int credits);
	void setMaxStudents(const int max);
	void setDayOfWeek(const char* day);
	void setSession(const int sess);
	void setListOfStudents(LinkedList<Student> listOfStudents);
	void input();


	friend ostream& operator<<(ostream& os, const Course& s);
};
