#pragma once
#include "Node.h"
#include "Student.h"

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

    //void printClassInfo();
};

