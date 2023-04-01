#pragma once
#include "Student.h"
#include "Scoreboard.h"
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
    Class() : className(nullptr), numberOfStudents(0), list(nullptr) {}
    Class(char* nameOfClass, LinkedList<Student> listData, int numOfStudents);
    ~Class()
    {}

    void setClassName(const char* name);

    char* getClassName() const;

    int getNumberOfStudents();

    void importStudentsFromCSV(const char* filenameInfoStu);
    void printListOfClasses();//TDat
    void printListOfStudents();
    void printScoreboardOfClasses();
};

