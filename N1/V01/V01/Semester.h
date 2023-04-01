#pragma once
#include <list>
#include <iostream>
#include "Course.h"
using namespace std;

class Semester 
{
    list<Course*> listOfCourses;
    int number;
public:
    Semester() : number(0) {}
    Semester(int number, list<Course*> listOfCourses);
    Semester(int number) : number(number) {}
    friend ostream& operator<<(ostream& os, const Semester &s);
    ~Semester();
    void addCourse();
    void printListOfCourses() {
        for (Course* c : listOfCourses) cout << *c << endl;
    }
};