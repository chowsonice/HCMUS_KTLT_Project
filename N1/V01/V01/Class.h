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
    Student* listOfStudents;
    int numberOfStudents;

public:
    Class();

    void setClassName(const char* name);

    char* getClassName() const;

    int getNumberOfStudents();

    void importStudentsFromCSV(const char* filenameInfoStu);
    //void printClassInfo();
};

