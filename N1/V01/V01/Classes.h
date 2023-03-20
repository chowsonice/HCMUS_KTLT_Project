#pragma once
#include "Node.h"
#include "Student.h"

class Classes {
private:
    char className[50];
    Node<Student>* n = new Node<Student>;
    int numberOfStudents;

public:
    Classes();

    void setClassName(const char* name);

    char* getClassName();

    void addStudent(char* name);

    int getNumberOfStudents();

    void printClassInfo();
};

