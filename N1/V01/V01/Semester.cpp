#include "Semester.h"

Semester::Semester(SchoolYear schoolYear, int number, Course* listOfCourses)
{
    this->_schoolYear = schoolYear;
    this->_number = number;
    this->_listOfCourses = listOfCourses;
}

Semester::~Semester()
{
    delete[] this->_listOfCourses;
}