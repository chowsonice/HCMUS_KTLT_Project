#pragma once
#include <iostream>
#include "Course.h"
using namespace std;

struct Semester 
{
    LinkedList<Course*> listOfCourses;
private:
    int number;
public:
    Semester() : number(0) {}
    Semester(int number, LinkedList<Course*> listOfCourses);
    Semester(int number) : number(number) {}
    friend ostream& operator<<(ostream& os, const Semester &s);
    ~Semester();
    void addCourse();
};