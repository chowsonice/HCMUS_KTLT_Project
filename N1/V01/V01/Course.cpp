#include "Course.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool Course::importStudentsFromCSV(int semester, int year, University &u) {
    string filename = "csv_file/" + classId + "_" + courseId + ".csv";
    
    ifstream fin(filename);
    if (!fin.is_open()) {
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
        Scoreboard* sb = new Scoreboard(courseId, name, time);
        sb->setSemester(semester, year);
        newStudent->addScoreboard(sb);
        listOfStudents.push_back(newStudent);
    }
    fin.close();
    return true;
}

Course::~Course() {
    listOfStudents.head = nullptr;
}

void Course::input() {
	cout << "Course ID: ";
    getline(cin, courseId);

	cout << "Name: ";
    getline(cin, name);

	cout << "Class ID: ";
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

string Course::getClassId() {
    return classId;
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

void Course::updateCourse(int semester, int year, University& uni) {
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
    cin.ignore(1000, '\n');

    switch (option) {
        case 1:
            cout << "Enter new course ID: ";
            getline(cin, buffer);
            setCourseId(buffer);
            break;
        case 2:
            cout << "Enter new course name: ";
            getline(cin, buffer);
            setCourseName(buffer);
            break;
        case 3:
            cout << "Enter new class ID: ";
            getline(cin, buffer);
            setClassId(buffer);
            listOfStudents.clear();
            importStudentsFromCSV(semester, year, uni);
            break;
        case 4:
            cout << "Enter new teacher's name: ";
            getline(cin, buffer);
            setTeacherName(buffer);
            break;
        case 5:
            cout << "Enter new number of credits: ";
            getline(cin, buffer);
            setNumOfCredits(stoi(buffer));
            break;
        case 6:
            cout << "Enter new max number of students: ";
            getline(cin, buffer);
            setMaxStudents(stoi(buffer));
            break;
        case 7:
            cout << "Enter new day of the week: ";
            getline(cin, buffer);
            setDayOfWeek(buffer);
            break;
        case 8:
            cout << "Enter new session no: ";
            getline(cin, buffer);
            setSession(stoi(buffer));
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }
}

void Course::exportStudentListToCSV(string courseID)
{
    if (listOfStudents.size() == 0) {
        cout << "No students found in the course!\n";
        return;
    }
    string fileName = "export_csv/" + courseID + "_" + classId + ".csv";
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
    string filename = "csv_file/" + classId + "_" + courseId + "_score" + ".csv", buffer;

    ifstream fin(filename);
    fin.ignore(1000, '\n');

    int ib = 0; string id, num;
    for (Student* s : listOfStudents) {
        getline(fin, buffer);
        stringstream ss(buffer);
        getline(ss, num, ',');
        getline(ss, id, ',');
        buffer.erase(0, id.length() + num.length() + 2);
        if (s->getId() != id) {
            throw "Student list and scoreboard are uncompatible.";
            return;
        }
        else s->updateScoreboard(courseId, buffer);
    }

    updated = true;
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
        << "|" << setw(10) << " Other " << "|" << setw(10) << " Final " << "|" << setw(10) << " Total " << "|" <<  endl;

    for (Student* s : listOfStudents) {
        cout << "|" << setw(10) << s->getId() << "|" << setw(15) << s->getFirstName() << "|" << setw(15) << s->getLastName() << "|";
        s->printScoreboard(courseId);
    }
}

void Course::viewCourseInfo() {
    cout << "Course ID: " << courseId << endl;
    cout << "Course's name: " << name << endl;
    cout << "Class ID: " << classId << endl;
    cout << "Teacher's name: " << teacherName << endl;
    cout << "Number of credits: " << noCredits << endl;
    cout << "Maximum number of students: " << maxNoStudents << endl;
    cout << "Session: " << dayOfTheWeek << " " << "[" << session << "]" << endl;
    cout << "-------------------------------\n";
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
        << s.dayOfTheWeek << " " << s.session << "\n"
        << s.updated;
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
    is >> s.updated;
    is.ignore(1000, '\n');
    return is;
}
