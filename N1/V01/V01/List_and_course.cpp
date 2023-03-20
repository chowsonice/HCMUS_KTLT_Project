#include"List_and_course.h"

Course::Course(char* id, char* name, char* className, char* teacherName, int credits, int max, string day, string sess, string sem) {
    strcpy(courseId, id);
    courseName = new char[strlen(name) + 1];
    strcpy(courseName, name);
    this->className = new char[strlen(className) + 1];
    strcpy(this->className, className);
    this->teacherName = new char[strlen(teacherName) + 1];
    strcpy(this->teacherName, teacherName);
    numOfCredits = credits;
    maxStudents = max;
    dayOfWeek = day;
    session = sess;
    semester = sem;
}

Course::~Course() {
    delete[] courseName;
    delete[] className;
    delete[] teacherName;
}

char* Course::getCourseId() {
    return courseId;
}

char* Course::getCourseName() {
    return courseName;
}

char* Course::getClassName() {
    return className;
}

char* Course::getTeacherName() {
    return teacherName;
}

int Course::getNumOfCredits() {
    return numOfCredits;
}

int Course::getMaxStudents() {
    return maxStudents;
}

string Course::getDayOfWeek() {
    return dayOfWeek;
}

string Course::getSession() {
    return session;
}

string Course::getSemester() {
    return semester;
}

list<string> Course::getListOfStudents() {
    return listOfStudents;
}

void Course::setCourseId(char* id) {
    strcpy(courseId, id);
}

void Course::setCourseName(char* name) {
    delete[] courseName;
    courseName = new char[strlen(name) + 1];
    strcpy(courseName, name);
}

void Course::setClassName(char* className) {
    delete[] this->className;
    this->className = new char[strlen(className) + 1];
    strcpy(this->className, className);
}

void Course::setTeacherName(char* teacherName) {
delete[] this->teacherName;
this->teacherName = new char[strlen(teacherName) + 1];
strcpy(this->teacherName, teacherName);
}

void Course::setNumOfCredits(int credits) {
numOfCredits = credits;
}

void Course::setMaxStudents(int max) {
maxStudents = max;
}

void Course::setDayOfWeek(string day) {
dayOfWeek = day;
}

void Course::setSession(string sess) {
session = sess;
}

void Course::setSemester(string sem) {
semester = sem;
}

void Course::importStudentsFromCSV(char* filename) {
ifstream infile;
infile.open(filename);
if (!infile.is_open()) {
    cout << "Error: Could not open file " << filename << endl;
    return;
}

string line;
while (getline(infile, line)) {
    listOfStudents.push_back(line);
}

infile.close();
}

void Course::printListOfStudents() {
cout << "List of Students:" << endl;
for (string student : listOfStudents) {
cout << student << endl;
}
}

void Course::printCourseInfo() {
cout << "Course Information:" << endl;
cout << "Course ID: " << courseId << endl;
cout << "Course Name: " << courseName << endl;
cout << "Class Name: " << className << endl;
cout << "Teacher Name: " << teacherName << endl;
cout << "Number of Credits: " << numOfCredits << endl;
cout << "Max Students: " << maxStudents << endl;
cout << "Day of Week: " << dayOfWeek << endl;
cout << "Session: " << session << endl;
cout << "Semester: " << semester << endl;
}   

int main() {

Course c("CSC10003", "Intro to OOP", "CSC10003-21VP", "Hoang Dung", 3);
// import student data from a CSV file
c.importStudentsFromCSV("students.csv");

// print the list of students in the course
c.printListOfStudents();

// print the course information
c.printCourseInfo();

// update course information

c.setCourseName("Introduction to programming");
c.setTeacherName("Vu Hung");
c.setMaxStudents(60);
c.setDayOfWeek("W");
c.setSession("PM");
c.setSemester("Fall 2022");
c.setCourseId("CSC10001");
c.setClassName("CSC10001-21VP");

cout << "Course information after update:" << endl;
// print the updated course information
c.printCourseInfo();

return 0;
}