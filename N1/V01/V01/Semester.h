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
    void getYear(int& y1, int& y2) {
        y1 = year1;
        y2 = year2;
    }
    int getN() {
        return number;
    }
    int getYear() {
        return year1;
    }
    void addCourse(University& uni);
    void printListOfCourses();
    void printInfoOfCourses();
    void deleteCourse(string courseID, string classID);
    Course* findCourse(string courseId, string classId);
    void printInfo() {
        cout << "semester " << number << ", school year " << year1 << " - " << year2 << endl;
    }
};

