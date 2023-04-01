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

        Student* newStudent = new Student;
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

void Course::printListOfStudents() {
    for (Student* s : listOfStudents) {
        cout << *s << "\n";
    }
}

void updateCourse(Course& course) {
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

void Course::removeStudent(Student *student)
{
	if (listOfStudents.size() == 0)
	{
		cout << "No students in the course to remove." << endl;
		return;
	}
	if (find(listOfStudents.begin(), listOfStudents.end(), student) != listOfStudents.end())
	{
        listOfStudents.remove(student);
		cout << "Removed student from the course." << endl;
	}
	else
	{
		cout << "Student not found in the course." << endl;
	}
}

//void Course::viewScoreboard()
//{
//	if (listOfStudents.size() == 0)
//	{
//		cout << "No students in the course." << endl;
//		return;
//	}
//	cout << "Scoreboard of course " << courseId << ": " << endl;
//	for (int i = 0; i < listOfStudents.size(); i++)
//	{
//		Student student = listOfStudents;
//		cout << student.getFirstName() << " " << student.getLastName() << " : " << student.getScoreboard() << endl;
//	}
//}

ostream& operator<<(ostream& os, const Course& s) 
{
	os << s.courseId << " " << s.name << " " << s.classId << " " << s.teacherName << " " << to_string(s.noCredits) << " "
        << to_string(s.maxNoStudents) << " " << s.dayOfTheWeek << " " << s.session;
    return os;
}