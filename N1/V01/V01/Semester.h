#pragma once
#include "Node.h"
#include "Course.h"
#include <iostream>
using namespace std;

struct Semester 
{
    LinkedList<Course*> listOfCourses;
private:
    int year1, year2;
    int number;
public:
    Semester() : number(0), year1(0), year2(0) {}
    Semester(int number, LinkedList<Course*> listOfCourses);
    Semester(int number) : number(number), year1(0), year2(0) {}
    friend ostream& operator<<(ostream& os, const Semester &s);
    friend istream& operator>>(istream& is, Semester& s);
    ~Semester();
    void setYear(int y1, int y2);
    void addCourse();
    void printListOfCourses();
    Course* findCourse(string courseId);
};

