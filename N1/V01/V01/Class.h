#pragma once
#include "Student.h"
#include <fstream>
#include <string>
#include <iostream>
#include <list>

using namespace std;
class Class {
private:
    char* className;
    list<Student*> list;
    int numberOfStudents;

public:
    Class();

    void setClassName(const char* name); //TDat

    char* getClassName() const; //TDat

    int getNumberOfStudents();//TDat

    void importStudentsFromCSV(const char* filenameInfoStu);
    //void printListOfClasses();//TDat
    void printListOfStudents();
};

