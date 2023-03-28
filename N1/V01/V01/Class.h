#pragma once
#include "Node.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
class Class {
private:
    char* className;
    LinkedList<Student> list;
    int numberOfStudents;

public:
    Class() : className(nullptr), numberOfStudents(0), list(nullptr) {}
    Class(char* nameOfClass, LinkedList<Student> listData, int numOfStudents);
    Class(const Class& cl) : Class(cl.className, cl.list, cl.numberOfStudents) {}
    ~Class()
    {
        delete[] className, list;
        className = nullptr;
        list = nullptr;
    }

    void setClassName(const char* name);

    char* getClassName() const;

    int getNumberOfStudents();

    void importStudentsFromCSV(const char* filenameInfoStu);
    void printListOfClasses();
    void printListOfStudents();
};

