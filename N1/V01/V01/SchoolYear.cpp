#include "SchoolYear.h"

SchoolYear::SchoolYear(int start, int end) 
{
    _start = start;
    _end = end;
    semesters = nullptr;
}

ostream& operator<<(ostream& os, SchoolYear sy) {
    os << sy._start << " - " << sy._end;
    return os;
}