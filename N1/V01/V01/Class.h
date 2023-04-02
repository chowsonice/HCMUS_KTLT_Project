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
    string className;
    list<Student*> list;
    int numberOfStudents;

public:
    Class() : className(""), numberOfStudents(0) {}
    Class(char* nameOfClass, std::list<Student*>listData(), int numOfStudents);
    ~Class(){}

    void setClassName(const string name);

    string getClassName() const;

    int getNumberOfStudents();

    void importStudentsFromCSV(const char* filenameInfoStu);
    void printListOfClasses();//TDat
    void printListOfStudents();
    void printScoreboardOfClasses();
};

