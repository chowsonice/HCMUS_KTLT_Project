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
    Class();

    void setClassName(const char* name); //TDat

    char* getClassName() const; //TDat

    int getNumberOfStudents();//TDat

    void importStudentsFromCSV(const char* filenameInfoStu);
    void printListOfClasses();//TDat
    void printListOfStudents();
};

