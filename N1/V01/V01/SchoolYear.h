#pragma once
#include <iostream>
#include "Node.h"
#include "Semester.h"
using namespace std;

class SchoolYear {
private:
    int _start;
    int _end;
    LinkedList<Semester> semesters;
    Node<Semester>* curSemester;
public:
    SchoolYear() : _start(2022), _end(2023), curSemester(nullptr) {}
    SchoolYear(int start, int end);
    friend ostream& operator<<(ostream& os, SchoolYear sy);
    void createNewSemester() {
        int n = semesters.size();
        if (n >= 3) return;
        curSemester = new Node<Semester>(Semester(n + 1));
        semesters.add(curSemester);
    }
    Node<Semester>* getCurrentSemester() {
        return curSemester;
    }
};