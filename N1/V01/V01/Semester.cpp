#include "Semester.h"

Semester::Semester(int number, LinkedList<Course> listOfCourses)
{
    this->number = number;
    this->listOfCourses = LinkedList<Course>(listOfCourses);
}
Semester::~Semester()
{}
void Semester::addCourse() {
    Node<Course>* temp = new Node<Course>();
    temp->data.input();
    listOfCourses.add(temp);
}