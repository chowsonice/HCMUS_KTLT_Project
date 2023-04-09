#include "Semester.h"

Semester::Semester(int number, LinkedList<Course*> listOfCourses)
{
    this->number = number;
    this->listOfCourses = LinkedList<Course*>(listOfCourses);
}
Semester::~Semester()
{}

void Semester::addCourse() {
    Course* temp = new Course;
    temp->input();
    listOfCourses.push_back(temp);
}

ostream& operator<<(ostream& os, const Semester& s) {
    os << "Term " << s.number << "\n";
    for (Node<Course*> c : s.listOfCourses) os << *c.data << "\n";
    return os;
}

//void Course::printListOfCourse() (?)
//{
//    for (Course* c : listOfCourses) {
//        cout << *c << "\n";
//    }
//}

void Course::printListOfCourse() {
    cout << "Course ID: " << courseId << endl;
    cout << "Course Name: " << name << endl;
    cout << "Class ID: " << classId << endl;
    cout << "Teacher Name: " << teacherName << endl;
    cout << "Number of Credits: " << noCredits << endl;
    cout << "Max Number of Students: " << maxNoStudents << endl;
    cout << "Day of the Week: " << dayOfTheWeek << endl;
    cout << "Session: " << session << endl;
    cout << "List of Students:" << endl;
    for (Node<Student*> s : listOfStudents) {
        cout << s.data->getFirstName() << " " << s.data->getLastName() << endl;
    }
}
