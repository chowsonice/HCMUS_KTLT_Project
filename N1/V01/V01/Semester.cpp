#include "Semester.h"

Semester::Semester(int number, list<Course*> listOfCourses)
{
    this->number = number;
    this->listOfCourses = list<Course*>(listOfCourses);
}
Semester::~Semester()
{}
ostream& operator<<(ostream& os, Semester s)
{
    os << "Term " << s.number << "\n";
    for (Course* c : s.listOfCourses) os << *c << "\n";
    return os;
}
void Semester::addCourse() {
    listOfCourses.push_back(new Course);
    Course* temp = listOfCourses.back();
    temp->input();
}

//void Course::printListOfCourse() (?)
//{
//    for (Course* c : listOfCourses) {
//        cout << *c << "\n";
//    }
//}


