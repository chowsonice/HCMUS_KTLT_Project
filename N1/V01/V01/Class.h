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
    Class(string name) : className(name), numberOfStudents(0) {}
    Class(string nameOfClass, std::list<Student*>listData(), int numOfStudents);
    ~Class(){}

    void setClassName(const string name);
    string getClassName() const;
    int getNumberOfStudents();

    Student* findStudent(string id) {
        for (Student* s : list) {
            if (s->getId().compare(id) == 0) {
                return s;
            }
        }
        return nullptr;
    }
    void importStudentsFromCSV();

    //void printListOfClasses();//TDat

    friend ostream& operator<<(ostream& os, Class c) {
        os << "Class " << c.className << "\n" << "Number of students: " << c.numberOfStudents << "\n";
    }
    void printListOfStudents();
    void printScoreboardOfClasses();
};

