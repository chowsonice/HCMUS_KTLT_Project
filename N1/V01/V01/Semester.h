#pragma once
#include "Node.h"
#include "Course.h"
#include <iostream>
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
    void printListOfCourses() {
        for (Node<Course*> c : listOfCourses) cout << *c.data << endl;
    }
    Course* findCourse(string courseId) {
        for (Node<Course*> c : listOfCourses) {
            if (c.data->getCourseId().compare(courseId) == 0) return c.data;
        }
    }
};