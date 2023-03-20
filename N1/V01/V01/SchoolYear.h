#pragma once
#include <iostream>
using namespace std;

class SchoolYear
{
    private:
        int _start;
        int _end;
    public:
    SchoolYear() : _start(2020), _end(2021);
    SchoolYear(int start, int end);
};