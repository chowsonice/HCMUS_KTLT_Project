#include "Course.h"
#include <string>
#include <fstream>
using namespace std;

bool Course::importStudentsFromCSV(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Cannot open file" << endl;
        return false;
    }

    string line;
    getline(fin, line, '\n');

    while (getline(fin, line)) {
 
        Student *newStudent = new Student;
        newStudent->readStudentFromCSVLine(line);
        listOfStudents.push_back(newStudent);

    }
    fin.close();
    return true;
}

void Course::input() {

	cout << "Course ID:";
    getline(cin, courseId);

	cout << "Name:";
    getline(cin, name);

	cout << "Class ID:";
    getline(cin, classId);

	cout << "Teacher's name: ";
    getline(cin, teacherName);

	cout << "Number of credits: ";
    string buffer;
    getline(cin, buffer);
	noCredits = stoi(buffer);

	cout << "Max number of students: ";
    getline(cin, buffer);
	maxNoStudents = stoi(buffer);

	cout << "Day of the week (MON/TUE/WED/THU/FRI/SAT/SUN): ";
    getline(cin, dayOfTheWeek);

	cout << "Session no (1, 2, 3, 4): ";
    getline(cin, buffer);
	session = stoi(buffer);
}

//void Course::setCourseId(const string courseId)
//{
//    if (this->courseId != nullptr)
//        delete[] this->courseId;
//    this->courseId = new char[strlen(courseId) + 1];
//    strcpy_s(this->courseId, strlen(courseId) + 1, courseId);
//}

//void Course::setCourseName(const string name)
//{
//    if (this->name != nullptr)
//        delete[] this->name;
//    this->name = new char[strlen(name) + 1];
//    strcpy_s(this->name, strlen(name) + 1, name);
//}
//
//void Course::setClassId(const string classId)
//{
//    if (this->classId != nullptr)
//        delete[] this->classId;
//    this->classId = new char[strlen(classId) + 1];
//    strcpy_s(this->classId, strlen(classId) + 1, classId);
//}
//
//void Course::setTeacherName(const string teacherName)
//{
//    if (this->teacherName != nullptr)
//        delete[] this->teacherName;
//    this->teacherName = new char[strlen(teacherName) + 1];
//    strcpy_s(this->teacherName, strlen(teacherName) + 1, teacherName);
//}

//void Course::setNumOfCredits(int noCredits)
//{
//    this->noCredits = noCredits;
//}
//
//void Course::setMaxStudents(int maxNoStudents)
//{
//    this->maxNoStudents = maxNoStudents;
//}

//void Course::setDayOfWeek(const string dayOfTheWeek)
//{
//    if (this->dayOfTheWeek != nullptr)
//        delete[] this->dayOfTheWeek;
//    this->dayOfTheWeek = new char[strlen(dayOfTheWeek) + 1];
//    strcpy_s(this->dayOfTheWeek, strlen(dayOfTheWeek) + 1, dayOfTheWeek);
//}

//void Course::setSession(int session)
//{
//    this->session = session;
//}

//void Course::setListOfStudents(list<Student> listOfStudents)
//{
//	this->listOfStudents = listOfStudents;
//}

void Course::printListOfStudents() {
    for (Student* s : listOfStudents) {
        cout << *s << "\n";
    }
}

ostream& operator<<(ostream& os, const Course& s) 
{
	os << s.courseId << " " << s.name << " " << s.classId << " " << s.teacherName << " " << to_string(s.noCredits) << " " << to_string(s.maxNoStudents) 
        << " " << s.dayOfTheWeek << " " << s.session;
    return os;
}