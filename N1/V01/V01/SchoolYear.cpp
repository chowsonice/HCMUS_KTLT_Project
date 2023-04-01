#include "SchoolYear.h"

SchoolYear::SchoolYear(int start, int end) 
{
    _start = start;
    _end = end;
    curSem = nullptr;
}

ostream& operator<<(ostream& os, SchoolYear sy) {
    os << sy._start << " - " << sy._end;
    return os;
}