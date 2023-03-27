#include "Semester.h"

Semester::Semester(SchoolYear schoolYear, int number, Course* listOfCourses)
{
    this->schoolYear = schoolYear;
    this->number = number;
    size_t count = sizeof(listOfCourses) / sizeof(listOfCourses[0]);
    cout << count << endl;
    this->listOfCourses = new Course [count];
    for (int i = 0; i < count; i++) {
        this->listOfCourses[i] = listOfCourses[i];
    }
}

Semester::~Semester()
{
    delete[] listOfCourses;
}