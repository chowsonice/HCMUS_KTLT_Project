#include "Course.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool Course::importStudentsFromCSV(University &u) {
    string filename = "csv_file/" + classId + "_" + courseId + ".csv";
    
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Cannot update students in course " << courseId << "." << endl;
        return false;
    }
    string line;
    getline(fin, line, '\n');
    while (getline(fin, line)) {

        const string delim = ",";
        string token;
        for (int i = 0; i < 3; i++) {
            token = line.substr(0, line.find(delim));
            line.erase(0, token.length() + 1);
        }
        Student* newStudent = u.findStudent(token);
        string time = dayOfTheWeek + " " + "S" + to_string(session);
        newStudent->addScoreboard(courseId, name, time);
        listOfStudents.push_back(newStudent);

    }
    fin.close();
    return true;
}

Course::~Course() {
    listOfStudents.head = nullptr;
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
    cin >> session;
    cin.ignore(1000, '\n');
}

void Course::setCourseId(const string courseId)
{
    this->courseId = courseId;
}

void Course::setCourseName(const string name)
{
    this->name = name;
}

void Course::setClassId(const string classId)
{
    this->classId = classId;
}

void Course::setTeacherName(const string teacherName)
{
    this->teacherName = teacherName;
}

void Course::setNumOfCredits(int noCredits)
{
    this->noCredits = noCredits;
}

void Course::setMaxStudents(int maxNoStudents)
{
    this->maxNoStudents = maxNoStudents;
}

void Course::setDayOfWeek(const string dayOfTheWeek)
{
    this->dayOfTheWeek = dayOfTheWeek;
}

void Course::setSession(int session)
{
    this->session = session;
}

string Course::getCourseId() {
    return courseId;
}

string Course::getName()
{
    return string();
}

void Course::printListOfStudents() {
    for (Node<Student*> s : listOfStudents) {
        cout << *s.data << "\n";
    }
}

void Course::updateCourse(Course& course) {
    int option;
    string buffer;

    cout << "Choose to update: " << endl;
    cout << "1. Course ID" << endl;
    cout << "2. Name" << endl;
    cout << "3. Class ID" << endl;
    cout << "4. Teacher's name" << endl;
    cout << "5. Number of credits" << endl;
    cout << "6. Max number of students" << endl;
    cout << "7. Day of the week" << endl;
    cout << "8. Session no" << endl;
    cin >> option;

    switch (option) {
        case 1:
            cout << "Enter new course ID: ";
            getline(cin, buffer);
            course.setCourseId(buffer);
            break;
        case 2:
            cout << "Enter new course name: ";
            getline(cin, buffer);
            course.setCourseName(buffer);
            break;
        case 3:
            cout << "Enter new class ID: ";
            getline(cin, buffer);
            course.setClassId(buffer);
            break;
        case 4:
            cout << "Enter new teacher's name: ";
            getline(cin, buffer);
            course.setTeacherName(buffer);
            break;
        case 5:
            cout << "Enter new number of credits: ";
            getline(cin, buffer);
            course.setNumOfCredits(stoi(buffer));
            break;
        case 6:
            cout << "Enter new max number of students: ";
            getline(cin, buffer);
            course.setMaxStudents(stoi(buffer));
            break;
        case 7:
            cout << "Enter new day of the week: ";
            getline(cin, buffer);
            course.setDayOfWeek(buffer);
            break;
        case 8:
            cout << "Enter new session no: ";
            getline(cin, buffer);
            course.setSession(stoi(buffer));
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }
}

void Course::deleteCourse(Course* course)
{
    delete course;
    course = nullptr;
}

void Course::exportStudentListToCSV(string courseID)
{
    if (listOfStudents.size() == 0) {
        cout << "No students found in the course!\n";
        return;
    }
    string fileName = "student_list_" + courseID + ".csv";
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cout << "Faile to create CSV file.\n";
        return;
    }

    outFile << "Sutdent ID, First Name, Last Name, Birthday\n";
    Node<Student*>* curr = listOfStudents.head;
    while (curr != nullptr) {
        Student* student = curr->data;
        outFile << student->getId() << ","
            << student->getFirstName() << ","
            << student->getLastName() << ","
            << student->getDateOfBirth() << endl;
        curr = curr->next;
    }
    outFile.close();
    cout << "Export student list of " << courseID << " successfully.\n";
}

Student* Course::findStudent(string id) {
    for (Node<Student*> s : listOfStudents) {
        if (s.data->getId().compare(id) == 0) {
            return s.data;
        }
    }
    return nullptr;
}

void Course::addStudent(Student *student)
{
	if (listOfStudents.size() >= maxNoStudents)
	{
		cout << "Cannot add more students to the course." << endl;
		return;
	}
	listOfStudents.push_back(student);
	cout << "Added student to the course." << endl;
}

void Course::removeStudent(string id)
{
	if (listOfStudents.size() == 0)
	{
		cout << "No students in the course to remove." << endl;
		return;
	}
    for (Node<Student*> s : listOfStudents) {
        if (s.data->getId().compare(id) == 0) {
            //s.data->removeScoreboard(courseId);
            listOfStudents.remove(s.data);
            cout << "Removed student ID "<< id <<" from the course." << endl;
            return;
        }
    }
	cout << "Student ID "<< id << " not found in the course." << endl;

}

void Course::importScoreboard() {
    string filename = classId + "_" + ".csv", buffer;

    ifstream fin(filename);
    fin.ignore(1000, '\n');

    int ib = 0; string id; char c;
    for (Student* s : listOfStudents) {
        getline(fin, buffer);
        stringstream ss(buffer);
        ss >> ib >> c;
        getline(ss, id, ',');
        buffer.erase(0, id.length() + 1);
        cout << buffer;
        if (s->getId() != id) {
            throw "Scoreboard is unsuitable for this course.\n";
            return;
        }
        else 
            s->updateScoreboard(courseId, buffer);
    }
}

void Course::viewScoreboard()
{
	if (listOfStudents.size() == 0)
	{
		cout << "No students in the course." << endl;
		return;
	}
	cout << "Scoreboard of course " << courseId << ": " << endl;
    cout << "|" << setw(10) << "  ID  " << "|" << setw(15) << "  First name  " << "|" << setw(15) << "  Last name  " << "|" << setw(10) << " Midterm "
        << "|" << setw(10) << " Other " << "|" << setw(10) << " Final " << "|" << setw(10) << " Total " << endl;

    for (Student* s : listOfStudents) {
        cout << "| " << setw(10) << s->getId() << "| " << setw(15) << s->getFirstName() << "| " << setw(15) << s->getLastName() << "| ";
        s->printScoreboard(courseId);
        cout << "\n";
    }
}

void Course::viewCourseInfo() {
    cout << courseId << endl;
    cout << name << endl;
    cout << classId << endl;
    cout << teacherName << endl;
    cout << noCredits << endl;
    cout << maxNoStudents << endl;
    cout << dayOfTheWeek << " " << session << endl;
}

void Course::setSemester(int s, int y1, int y2) {
    sem = s; year1 = y1; year2 = y2;
}

ostream& operator<<(ostream& os, const Course& s) 
{
	os << s.courseId << "\n" 
        << s.name << "\n" 
        << s.classId << "\n" 
        << s.teacherName << "\n" 
        << to_string(s.noCredits) << "\n" 
        << to_string(s.maxNoStudents) << "\n" 
        << s.dayOfTheWeek << " " << s.session;
    return os;
}

istream& operator>>(istream& is, Course& s) {
    getline(is, s.courseId);
    getline(is, s.name);
    getline(is, s.classId);
    getline(is, s.teacherName);
    is >> s.noCredits >> s.maxNoStudents;
    is.ignore(1000, '\n');
    is >> s.dayOfTheWeek;
    is >> s.session;
    is.ignore(1000, '\n');
    return is;
}
