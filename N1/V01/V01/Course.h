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
	//Semester sem;
	LinkedList<Student>* listOfStudents;
public:
	Course() : courseId(nullptr), name(nullptr), classId(nullptr), teacherName(nullptr), noCredits(0), maxNoStudents(50), dayOfTheWeek(nullptr), listOfStudents(nullptr) {}
	//Course(char* idData, char* nameData, char* classIdData, char* teacherNameData, int noCreditsData, int maxStudentData, char* weekDayData, Semester cur, LinkedList<Student> listData) {	
	//	courseId = new char(strlen(idData) + 1);
	//	strcpy_s(courseId, strlen(idData) + 1, idData);
	//	name = new char(strlen(nameData) + 1);
	//	strcpy_s(name, strlen(nameData) + 1, nameData);
	//	classId = new char(strlen(classIdData) + 1);
	//	strcpy_s(classId, strlen(classIdData) + 1, classIdData);
	//	teacherName = new char(strlen(teacherNameData) + 1);
	//	strcpy_s(teacherName, strlen(teacherNameData) + 1, teacherNameData);
	//	noCredits = noCreditsData;
	//	maxNoStudents = maxStudentData;
	//	dayOfTheWeek = new char(strlen(weekDayData) + 1);
	//	strcpy_s(dayOfTheWeek, strlen(weekDayData) + 1, weekDayData);
	//	listOfStudents = 
	//}
	//Course(const Course& c) : Course(c.classId, c.name, c.classId, c.teacherName, c.noCredits, c.maxNoStudents, c.dayOfTheWeek, c.sem, c.listOfStudents) {}
	//bool importStudents();
	~Course() {
		delete courseId, name, classId, teacherName, dayOfTheWeek, listOfStudents;
		courseId = nullptr;
		name = nullptr;
		classId = nullptr;
		dayOfTheWeek = nullptr;
		listOfStudents = nullptr;
	}
};

