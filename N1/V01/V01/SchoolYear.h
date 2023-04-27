#pragma once
#include <iostream>
#include "Semester.h"
#include <time.h>
using namespace std;

class SchoolYear {
private:
    int _start;
    int _end;
    LinkedList<Semester*> semesters;
    static Semester* curSem;
public:
    SchoolYear() : _start(0), _end(1) {}
    SchoolYear(int start, int end);
    friend ostream& operator<<(ostream& os, SchoolYear sy);
    void createNewSemester();
    Semester* getCurrentSemester();
    int getCurrentNSemester();
    bool operator==(Semester* s) {
        int year1, year2;
        s->getYear(year1, year2);
        if (_start == year1 && _end == year2) return true;
        else return false;
    }
    friend void importFromFile(University& uni, LinkedList<SchoolYear*>& years);
    friend void exportToFile(LinkedList<SchoolYear*> years);
};