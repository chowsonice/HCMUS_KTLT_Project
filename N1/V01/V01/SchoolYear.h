#pragma once
#include <iostream>
#include "Semester.h"
using namespace std;

class SchoolYear {
private:
    int _start;
    int _end;
    LinkedList<Semester*> semesters;
    Semester* curSem = nullptr;
public:
    SchoolYear() : _start(2022), _end(2023) {}
    SchoolYear(int start, int end);
    friend ostream& operator<<(ostream& os, SchoolYear sy);
    void createNewSemester() 
    {
        int n = semesters.size();
        if (n >= 3) {
            cout << "Cannot add another semester to this school year!\n Create a new one and try again.\n";
            return;
        }
        curSem = new Semester(n + 1);
        curSem->setYear(_start, _end);
        semesters.push_back(curSem);
    }
    Semester *getCurrentSemester() 
    {
        return curSem;
    }
};