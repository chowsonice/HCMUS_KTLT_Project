#pragma once
#include "Student.h"
#include "University.h"
#include <list>
#include "Node.h"

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
	LinkedList<Student*> listOfStudents;
public:
	Course() : courseId(""), name(""), classId(""), teacherName(""), noCredits(0), maxNoStudents(50), dayOfTheWeek(""), session(0) {}
	~Course() {}
	bool importStudentsFromCSV(string filename, University& u);
	void setCourseId(const string id);
	void setCourseName(const string name);
	void setClassName(const string className);
	void setClassId(const string classId);
	void setTeacherName(const string teacherName);
	void setNumOfCredits(const int credits);
	void setMaxStudents(const int max);
	void setDayOfWeek(const string day);
	void setSession(const int sess);
	void printListOfStudents();
	void input();

	void addStudent(Student *student);
	void removeStudent(Student *student);
	//void importScoreboard(char* filename);
	//void viewScoreboard();
	void printListOfCourse(); // tai sao co list of course o day ? no o trong semester ma ? xoa di nha
	friend ostream& operator<<(ostream& os, const Course& s);
};
