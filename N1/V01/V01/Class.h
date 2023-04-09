#pragma once
#include "Student.h"
#include "Scoreboard.h"
#include "Node.h"
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

class Class {
private:
    bool updated = false;
    string className;
    LinkedList<Student*> list;
    int numberOfStudents;

public:
    Class() : className(""), numberOfStudents(0) {}
    Class(string name) : className(name), numberOfStudents(0) {}
    Class(string nameOfClass, LinkedList <Student*>listData(), int numOfStudents);
    ~Class(){}

    void setClassName(const string name);
    string getClassName() const;
    int getNumberOfStudents();

    Student* findStudent(string id) {
        for (Node<Student*> s : list) {
            if (s.data->getId().compare(id) == 0) {
                return s.data;
            }
        }
        return nullptr;
    }
    void importStudentsFromCSV();
    void exportStudentsToCSV();

    friend ostream& operator<<(ostream& os, Class c) {
        os << "Class " << c.className << "\n" << "Number of students: " << c.numberOfStudents << "\n";
        return os;
    }

    void printListOfStudents();
    void printScoreboardOfClass(string id);
};

