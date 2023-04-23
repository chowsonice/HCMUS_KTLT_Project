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
    //cout << "Term ";
    os << s.number << "\n";
    //cout << "Total number of courses: ";
    os << s.listOfCourses.size() << endl;
    for (Course* c : s.listOfCourses) {
        os << *c << endl;
    }
    return os;
}

istream& operator>>(istream& is, Semester& s){
    is >> s.number;
    int n;
    is >> n;
    is.ignore(1000, '\n');
    for (int i = 0; i < n; i++) {
        Course* c = new Course();
        is >> *c;
        s.listOfCourses.push_back(c);
    }
    return is;
}


