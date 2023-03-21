#pragma once
#include <iostream>
using namespace std;

class SchoolYear {
private:
    int _start;
    int _end;
public:
    SchoolYear() : _start(2022), _end(2023) {}
    SchoolYear(int start, int end);
};