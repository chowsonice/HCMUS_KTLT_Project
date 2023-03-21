#include "Course.h"
#include <string>
#include <fstream>
using namespace std;

Course::Course(char* idData, char* nameData, char* classIdData, char* teacherNameData, int noCreditsData, int maxStudentData, char* weekDayData, int sessionData, LinkedList<Student> listData) {
	courseId = new char [strlen(idData) + 1];
	strcpy_s(courseId, strlen(idData) + 1, idData);
	name = new char [strlen(nameData) + 1];
	strcpy_s(name, strlen(nameData) + 1, nameData);
	classId = new char [strlen(classIdData) + 1];
	strcpy_s(classId, strlen(classIdData) + 1, classIdData);
	teacherName = new char [strlen(teacherNameData) + 1];
	strcpy_s(teacherName, strlen(teacherNameData) + 1, teacherNameData);
	noCredits = noCreditsData;
	maxNoStudents = maxStudentData;
	dayOfTheWeek = new char [strlen(weekDayData) + 1];
	session = sessionData;
	strcpy_s(dayOfTheWeek, strlen(weekDayData) + 1, weekDayData);
	listOfStudents = LinkedList<Student>(listData); //remember to add copy constructor for linked list
}

bool Course::importStudentsFromCSV(char* filename) {
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) return false;
	
	char buffer[100]; int n = 0; Student s;
	while (!fin.eof()) {
		fin.getline(buffer, sizeof buffer);
		s.readStudentFromCSVLine(buffer);
		listOfStudents.add(s);
	}
	fin.close();
}

void Course::printListOfStudents() {
	cout << listOfStudents;
}
