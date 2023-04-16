#include "Semester.h"

Semester::Semester(int number, LinkedList<Course*> listOfCourses)
{
    this->number = number;
    this->listOfCourses = LinkedList<Course*>(listOfCourses);
}
Semester::~Semester()
{}

void Semester::addCourse() {
    Course* course = new Course();
    course->input();
    course->setSemester(number, year1, year2);
    listOfCourses.push_back(course);
}

ostream& operator<<(ostream& os, const Semester& s) {
    os << "Term " << s.number << "\n";
    Node<Course*>* node = s.listOfCourses.head;
    while (node != nullptr)
    {
        os << node << endl;
        node = node->next;
    }
    return os;
}


