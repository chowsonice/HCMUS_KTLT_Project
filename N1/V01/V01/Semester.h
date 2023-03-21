#pragma once
#include "SchoolYear.h"
#include "Course.h"
using namespace std;

class Semester 
{
    SchoolYear schoolYear;
    Course *listOfCourses;
    int number;
public:
    Semester() : number(0), listOfCourses(nullptr) {}
    Semester(SchoolYear schoolYear, int number, Course *listOfCourses);
    Semester(SchoolYear schoolYear, int number) : Semester(schoolYear, number, nullptr) {}
    ~Semester();
};