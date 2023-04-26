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
    Semester* curSem = nullptr;
public:
    SchoolYear() : _start(0), _end(1) {}
    SchoolYear(int start, int end);
    friend ostream& operator<<(ostream& os, SchoolYear sy);
    void createNewSemester();
    Semester* getCurrentSemester();
    int getCurrentNSemester();

    friend void importFromFile(University& uni, LinkedList<SchoolYear*>& years);
    friend void exportToFile(LinkedList<SchoolYear*> years);
};