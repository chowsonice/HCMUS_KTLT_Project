#pragma once
#include "Course.h"
using namespace std;

class Semester
{
private:
    LinkedList<Course> listOfCourses;
    int number;
public:
    Semester() : number(0) {}
    Semester(int number, LinkedList<Course> listOfCourses);
    Semester(int number) : number(number) {}
    ~Semester();
    void addCourse();
    void printListOfCourse();
};