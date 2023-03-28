#include "Course.h"
#include <string>
#include <fstream>
using namespace std;

Course::Course(char* idData, char* nameData, char* classIdData, char* teacherNameData, int noCreditsData, int maxStudentData, char* weekDayData, int sessionData, LinkedList<Student> listData) {
	courseId = new char[strlen(idData) + 1];
	strcpy_s(courseId, strlen(idData) + 1, idData);
	name = new char[strlen(nameData) + 1];
	strcpy_s(name, strlen(nameData) + 1, nameData);
	classId = new char[strlen(classIdData) + 1];
	strcpy_s(classId, strlen(classIdData) + 1, classIdData);
	teacherName = new char[strlen(teacherNameData) + 1];
	strcpy_s(teacherName, strlen(teacherNameData) + 1, teacherNameData);
	noCredits = noCreditsData;
	maxNoStudents = maxStudentData;
	dayOfTheWeek = new char[strlen(weekDayData) + 1];
	session = sessionData;
	strcpy_s(dayOfTheWeek, strlen(weekDayData) + 1, weekDayData);
	listOfStudents = LinkedList<Student>(listData); //remember to add copy constructor for linked list
}

bool Course::importStudentsFromCSV(char* filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Cannot open file" << endl;
		return false;
	}

	string line;
	getline(fin, line, '\n');

	LinkedList<Student> listOfStudents;

	while (getline(fin, line)) {
		char* buffer = new char[line.length() + 1];
		strcpy_s(buffer, line.length() + 1, line.c_str());
		Student newStudent;
		newStudent.readStudentFromCSVLine(buffer);
		listOfStudents.add(newStudent);

		delete[] buffer;
	}
	fin.close();
	return true;
}

void Course::input() {
	char buffer[100];
	cout << "Course ID: ";
	cin >> buffer;
	cout << "\n";
	courseId = new char[strlen(buffer) + 1];
	strcpy_s(courseId, strlen(buffer) + 1, buffer);

	cout << "Name: ";
	cin >> buffer;
	cout << "\n";
	name = new char[strlen(buffer) + 1];
	strcpy_s(name, strlen(buffer) + 1, buffer);

	cout << "Class ID: ";
	cin >> buffer;
	cout << "\n";
	classId = new char[strlen(buffer) + 1];
	strcpy_s(classId, strlen(buffer) + 1, buffer);

	cout << "Teacher's name: ";
	cin >> buffer;
	cout << "\n";
	teacherName = new char[strlen(buffer) + 1];
	strcpy_s(teacherName, strlen(buffer) + 1, buffer);

	cout << "Number of credits: ";
	cin >> buffer;
	cout << "\n";
	noCredits = stoi(buffer);

	cout << "Max number of students: ";
	cin >> buffer;
	cout << "\n";
	maxNoStudents = stoi(buffer);

	cout << "Day of the week (MON/TUE/WED/THU/FRI/SAT/SUN): ";
	cin >> buffer;
	cout << "\n";
	dayOfTheWeek = new char[strlen(buffer) + 1];
	strcpy_s(dayOfTheWeek, strlen(buffer) + 1, buffer);

	cout << "Session no (1, 2, 3, 4): ";
	cin >> buffer;
	cout << "\n";
	session = stoi(buffer);
}

void Course::setCourseId(const char* courseId)
{
	if (this->courseId != nullptr)
		delete[] this->courseId;
	this->courseId = new char[strlen(courseId) + 1];
	strcpy_s(this->courseId, strlen(courseId) + 1, courseId);
}

void Course::setCourseName(const char* name)
{
	if (this->name != nullptr)
		delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Course::setClassId(const char* classId)
{
	if (this->classId != nullptr)
		delete[] this->classId;
	this->classId = new char[strlen(classId) + 1];
	strcpy_s(this->classId, strlen(classId) + 1, classId);
}

void Course::setTeacherName(const char* teacherName)
{
	if (this->teacherName != nullptr)
		delete[] this->teacherName;
	this->teacherName = new char[strlen(teacherName) + 1];
	strcpy_s(this->teacherName, strlen(teacherName) + 1, teacherName);
}

void Course::setNumOfCredits(const int noCredits)
{
	this->noCredits = noCredits;
}

void Course::setMaxStudents(const int maxNoStudents)
{
	this->maxNoStudents = maxNoStudents;
}

void Course::setDayOfWeek(const char* dayOfTheWeek)
{
	if (this->dayOfTheWeek != nullptr)
		delete[] this->dayOfTheWeek;
	this->dayOfTheWeek = new char[strlen(dayOfTheWeek) + 1];
	strcpy_s(this->dayOfTheWeek, strlen(dayOfTheWeek) + 1, dayOfTheWeek);
}

void Course::setSession(const int session)
{
	this->session = session;
}

void Course::setListOfStudents(LinkedList<Student> listOfStudents)
{
	this->listOfStudents = listOfStudents;
}

void Course::printListOfStudents() {
	cout << listOfStudents;
}

ostream& operator<<(ostream& os, const Course& s)
{
	for (int i = 0; i < strlen(s.courseId); i++) os << s.courseId[i];
	os << " ";
	for (int i = 0; i < strlen(s.name); i++) os << s.name[i];
	os << " ";
	for (int i = 0; i < strlen(s.classId); i++) os << s.classId[i];
	os << " ";
	for (int i = 0; i < strlen(s.teacherName); i++) os << s.teacherName[i];
	os << " ";
	os << s.noCredits << endl;
	os << " ";
	os << s.maxNoStudents << endl;
	os << " ";
	for (int i = 0; i < strlen(s.dayOfTheWeek); i++) os << s.dayOfTheWeek[i];
	os << " ";
	os << s.session;
	return os;
}