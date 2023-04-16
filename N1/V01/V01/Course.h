#pragma once
#include "Student.h"
#include "University.h"
#include "Node.h"

using namespace std;

class Course
{
	int sem, year1, year2;
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
	Course() : sem(0), year1(0), year2(0), courseId(""), name(""), classId(""), teacherName(""), noCredits(0), maxNoStudents(50), dayOfTheWeek(""), session(0) {}
	~Course() {
		listOfStudents.head = nullptr;
	}
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

	string getCourseId() {
		return courseId;
	}
	void printListOfStudents();
	void input();

	void addStudent(Student *student);
	void removeStudent(string id);
	void importScoreboard();
	void viewScoreboard();
	void setSemester(int s, int y1, int y2) {
		sem = s; year1 = y1; year2 = y2;
	}

	friend ostream& operator<<(ostream& os, const Course& s);
};
