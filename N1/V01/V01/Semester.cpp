#include "Semester.h"

Semester::Semester(int number, LinkedList<Course> listOfCourses)
{
    this->number = number;
    this->listOfCourses = LinkedList<Course>(listOfCourses);
}
Semester::~Semester()
{}
//void Semester::addCourse() {
//    Course temp;
//    temp.input();
//    listOfCourses.add(temp);
//}
void Class::printListOfCourse()
{
    cout << this->listOfCourses << endl;
}